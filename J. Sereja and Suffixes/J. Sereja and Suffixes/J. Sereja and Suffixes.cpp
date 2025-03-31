#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // dp[i] will hold the number of distinct integers from position i to n.
    vector<int> dp(n + 2, 0);
    // visited[x] is true if we've seen integer x in our traversal from the right.
    vector<bool> visited(100001, false);

    // Process the array from right to left.
    for (int i = n; i >= 1; i--) {
        if (!visited[a[i]]) {
            dp[i] = dp[i + 1] + 1;
            visited[a[i]] = true;
        }
        else {
            dp[i] = dp[i + 1];
        }
    }

    // Answer the queries.
    while (m--) {
        int l;
        cin >> l;
        cout << dp[l] << "\n";
    }

    return 0;
}
