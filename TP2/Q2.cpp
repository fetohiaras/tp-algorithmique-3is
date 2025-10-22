#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>  
#include <utility>    
#include <tuple>     

using namespace std;

// Function to read input from the file and return the vector A, its size n, and k
tuple<vector<int>, int, int> read_input(const string& filename) {
    ifstream input(filename);
    if (!input.is_open()) {
        cerr << "Error opening input file: " << filename << endl;
        return {vector<int>(), 0, 0};  // Return empty vector, 0, 0 on error
    }

    int n, k;
    input >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        input >> A[i];
    }
    input.close();

    return {A, n, k};
}

// Function to compute the DP tables for longest subsequence with sum % k == 0
// Returns dp and prev
pair<vector<vector<int>>, vector<vector<pair<int, int>>>> compute_dp(const vector<int>& A, int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(k, -1));  // dp[i][r]: max length using first i elements, sum % k == r
    vector<vector<pair<int, int>>> prev(n + 1, vector<pair<int, int>>(k, make_pair(-1, -1)));  // prev[i][r] = (prev_i, prev_r)

    dp[0][0] = 0;  // Initial: length 0, remainder 0

    for (int i = 1; i <= n; ++i) {
        int mod_a = A[i - 1] % k;

        // Option: not take A[i-1]
        for (int r = 0; r < k; ++r) {
            if (dp[i - 1][r] != -1) {
                if (dp[i - 1][r] > dp[i][r] || dp[i][r] == -1) {
                    dp[i][r] = dp[i - 1][r];
                    prev[i][r] = make_pair(i - 1, r);
                }
            }
        }

        // Option: take A[i-1]
        for (int r = 0; r < k; ++r) {
            if (dp[i - 1][r] != -1) {
                int new_r = (r + mod_a) % k;
                int new_len = dp[i - 1][r] + 1;
                if (new_len > dp[i][new_r] || dp[i][new_r] == -1) {
                    dp[i][new_r] = new_len;
                    prev[i][new_r] = make_pair(i - 1, r);
                }
            }
        }
    }

    return {dp, prev};
}

// Function to reconstruct the subsequence using the prev table
// Returns a vector of pairs: (1-based index, value) in reverse order (from end to start)
vector<pair<int, int>> reconstruct_subseq(const vector<int>& A, const vector<vector<pair<int, int>>>& prev, const vector<vector<int>>& dp, int n) {
    vector<pair<int, int>> subseq;
    int i = n;
    int r = 0;  // We want sum % k == 0

    while (i > 0) {
        auto [prev_i, prev_r] = prev[i][r];
        if (dp[i][r] == dp[prev_i][prev_r]) {
            // Did not take the element
            i = prev_i;
            r = prev_r;
        } else {
            // Took the element
            int idx = i;  // 1-based
            int val = A[i - 1];
            subseq.emplace_back(idx, val);
            i = prev_i;
            r = prev_r;
        }
    }

    return subseq;  
}

// Function to write the output to the file
void write_output(const string& filename, int max_len, const vector<pair<int, int>>& subseq) {
    ofstream output(filename);
    if (!output.is_open()) {
        cerr << "Error opening output file: " << filename << endl;
        return;
    }

    int sum_val = 0;
    for (const auto& p : subseq) {
        sum_val += p.second;
    }

    output << max_len << endl;
    for (const auto& p : subseq) {
        output << "a[" << p.first << "] = " << p.second << endl;
    }
    output << "Sum = " << sum_val << endl;

    output.close();
}

int main() {
    auto [A, n, k] = read_input("INPDIVSEQ.TXT");
    if (n == 0) {
        return 1;  
    }

    if (n < 1 || n > 1000 || k < 1 || k > 50) {
        cerr << "n or k out of bounds" << endl;
        return 1;
    }

    for (int val : A) {
        if (val <= 0) {
            cerr << "A[i] must be positive" << endl;
            return 1;
        }
    }

    auto [dp, prev] = compute_dp(A, n, k);
    int max_len = dp[n][0];
    auto subseq = reconstruct_subseq(A, prev, dp, n);

    write_output("OUTDIVSEQ.TXT", max_len, subseq);

    cout << "Longest subsequence with sum divisible by k printed to OUTDIVSEQ.TXT." << endl;

    return 0;
}