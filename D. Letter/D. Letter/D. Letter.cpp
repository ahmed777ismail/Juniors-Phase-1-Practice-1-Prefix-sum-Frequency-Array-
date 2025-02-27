#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    unordered_map<char, int> s1_counts;

    // Count characters in s1 (excluding spaces)
    for (char c : s1) {
        if (c != ' ') {
            s1_counts[c]++;
        }
    }

    unordered_map<char, int> s2_counts;

    // Count characters in s2 (excluding spaces)
    for (char c : s2) {
        if (c != ' ') {
            s2_counts[c]++;
        }
    }

    // Check if all characters in s2 are covered by s1
    for (const auto& pair : s2_counts) {
        char c = pair.first;
        int count = pair.second;

        if (s1_counts.find(c) == s1_counts.end() || s1_counts[c] < count) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}