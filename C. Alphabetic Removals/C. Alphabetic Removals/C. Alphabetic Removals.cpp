#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<queue<int>> pos(26); // Stores positions of each letter

    // Store indices of each character in their respective queue
    for (int i = 0; i < n; i++) {
        pos[s[i] - 'a'].push(i);
    }

    vector<bool> removed(n, false); // Marks removed characters

    // Remove k characters in lexicographical order
    for (int i = 0; i < 26 && k > 0; i++) {
        while (!pos[i].empty() && k > 0) {
            int index = pos[i].front();
            pos[i].pop();
            removed[index] = true;
            k--;
        }
    }

    // Construct the final result
    for (int i = 0; i < n; i++) {
        if (!removed[i]) {
            cout << s[i];
        }
    }

    cout << endl; // Ensures proper output format

    return 0;
}
