#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;          // Number of trainees, number of "help" records

    vector<long long> A(N); // Initial coins of each trainee
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // netFlow[i] will track how much net money trainee i (0-based) gains (positive) 
    // or owes (negative) by the end.
    vector<long long> netFlow(N, 0LL);

    // Read each help event (X, Y, Z)
    // and adjust net flows accordingly
    for (int i = 0; i < M; i++) {
        long long X, Y, Z;
        cin >> X >> Y >> Z;
        // Convert to 0-based index
        X--;
        Y--;
        netFlow[X] -= Z;
        netFlow[Y] += Z;
    }

    // Check if all trainees can end up with >= 0 coins
    for (int i = 0; i < N; i++) {
        if (A[i] + netFlow[i] < 0) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}
