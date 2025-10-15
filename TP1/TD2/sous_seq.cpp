#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find and print the Longest Increasing Subsequence (LIS)
vector<int> longestIncreasingSubsequence(vector<int>& A) {
    int n = A.size();
    vector<int> L(n, 1);       // L[i] = length of LIS ending at index i
    vector<int> parent(n, -1); // To reconstruct the LIS

    // Build the LIS values and parent array
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i] && L[i] < L[j] + 1) {
                L[i] = L[j] + 1;
                parent[i] = j; // Track predecessor
            }
        }
    }

    // Find the index of the maximum length LIS
    int lis_length = 0;
    int lis_end = 0;
    for (int i = 0; i < n; i++) {
        if (L[i] > lis_length) {
            lis_length = L[i];
            lis_end = i;
        }
    }

    // Reconstruct the LIS
    vector<int> lis_sequence;
    for (int i = lis_end; i != -1; i = parent[i]) {
        lis_sequence.push_back(A[i]);
    }
    reverse(lis_sequence.begin(), lis_sequence.end());

    return lis_sequence;
}

int main() {
    int n;
    cout << "=== Longest Increasing Subsequence (LIS) Finder ===" << endl;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> A(n);
    cout << "Enter the elements of the sequence: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<int> lis = longestIncreasingSubsequence(A);

    cout << "The length of the longest increasing subsequence is: " << lis.size() << endl;
    cout << "The longest increasing subsequence is: ";
    for (int x : lis) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
