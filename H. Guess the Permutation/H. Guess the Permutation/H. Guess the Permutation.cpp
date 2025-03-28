#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    // Use 1-based indexing for simplicity
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    // Read the matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    // Permutation array
    vector<int> p(n + 1);
    // Set of remaining positions
    set<int> remaining;
    for (int i = 1; i <= n; i++) {
        remaining.insert(i);
    }
    // Assign values from 1 to n
    for (int k = 1; k <= n; k++) {
        // Find the first i that satisfies the condition
        for (auto it = remaining.begin(); it != remaining.end(); ++it) {
            int i = *it;
            bool ok = true;
            // Check all j in remaining except i
            for (auto jt = remaining.begin(); jt != remaining.end(); ++jt) {
                int j = *jt;
                if (j != i && a[i][j] != k) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                p[i] = k;
                remaining.erase(it);
                break; // Move to next k
            }
        }
    }
    // Print the permutation
    for (int i = 1; i <= n; i++) {
        cout << p[i];
        if (i < n) cout << " ";
    }
    cout << endl;
    return 0;
}