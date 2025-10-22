#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>  
#include <utility>    

using namespace std;

pair<vector<int>, int> read_input(const string& filename) {
    ifstream input(filename);
    if (!input.is_open()) {
        cerr << "Error opening input file: " << filename << endl;
        return {vector<int>(), 0};  // Return empty vector and 0 on error
    }

    int n;
    input >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        input >> A[i];
    }
    input.close();

    return {A, n};
}

// Compute the DP tables for LIS
pair<vector<int>, vector<int>> compute_lis_dp(const vector<int>& A, int n) {
    vector<int> dp(n, 1);  // dp[i]: max length ending at i
    vector<int> prev(n, -1);  // prev[i]: predecessor index for reconstruction

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (A[j] < A[i] && dp[j] + 1 > dp[i]) {  // Strict increasing
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }

    return {dp, prev};
}

// Function to find the maximum length and the ending index of the LIS
pair<int, int> find_max_lis(const vector<int>& dp, int n) {
    int max_len = 0;
    int end = -1;
    for (int i = 0; i < n; ++i) {
        if (dp[i] > max_len) {
            max_len = dp[i];
            end = i;
        }
    }
    return {max_len, end};
}

// Reconstruct the LIS using the prev array
// Returns a vector of pairs: (1-based index, value)
vector<pair<int, int>> reconstruct_lis(const vector<int>& A, const vector<int>& prev, int end) {
    vector<pair<int, int>> lis;
    int current = end;
    while (current != -1) {
        lis.emplace_back(current + 1, A[current]);  // 1-based index
        current = prev[current];
    }
    reverse(lis.begin(), lis.end());  // Reverse to get original order
    return lis;
}

void write_output(const string& filename, int max_len, const vector<pair<int, int>>& lis) {
    ofstream output(filename);
    if (!output.is_open()) {
        cerr << "Error opening output file: " << filename << endl;
        return;
    }

    output << max_len << endl;
    for (const auto& p : lis) {
        output << "a[" << p.first << "] = " << p.second << endl;
    }
    output.close();
}

int main() {
    auto [A, n] = read_input("INPMONOSEQ.TXT");
    if (n == 0) {
        return 1;  
    }

    auto [dp, prev] = compute_lis_dp(A, n);
    auto [max_len, end] = find_max_lis(dp, n);
    auto lis = reconstruct_lis(A, prev, end);

    write_output("OUTMONOSEQ.TXT", max_len, lis);

    cout << "Largest increasing subsequence printed to OUTMONOSEQ.TXT." << endl;

    return 0;
}