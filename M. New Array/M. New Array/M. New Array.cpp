#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1, 0); // using 1-indexed array
        vector<bool> queryPresent(n + 1, false);

        // Read queries and mark distinct x values.
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            if (x <= n)
                queryPresent[x] = true;
        }

        // For each x that appears, mark its multiples.
        for (int x = 1; x <= n; x++) {
            if (queryPresent[x]) {
                for (int i = x; i <= n; i += x) {
                    a[i] = 1;
                }
            }
        }

        // Print the final array (positions 1 to n).
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
