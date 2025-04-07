#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int W, H, N;
        cin >> W >> H >> N;

        // Create a difference array with extra margins
        vector<vector<int>> diff(W + 2, vector<int>(H + 2, 0));

        for (int i = 0; i < N; i++) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            // Normalize the coordinates
            int xl = min(x1, x2);
            int xr = max(x1, x2);
            int yl = min(y1, y2);
            int yr = max(y1, y2);

            // Apply difference array updates
            diff[xl][yl] += 1;
            diff[xr + 1][yl] -= 1;
            diff[xl][yr + 1] -= 1;
            diff[xr + 1][yr + 1] += 1;
        }

        // Convert difference array to actual grid values using 2D prefix sums
        for (int i = 1; i <= W; i++) {
            for (int j = 1; j <= H; j++) {
                diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
            }
        }

        // Count cells with no coverage
        long long uncovered = 0;
        for (int i = 1; i <= W; i++) {
            for (int j = 1; j <= H; j++) {
                if (diff[i][j] == 0)
                    uncovered++;
            }
        }

        cout << uncovered << "\n";
    }

    return 0;
}
