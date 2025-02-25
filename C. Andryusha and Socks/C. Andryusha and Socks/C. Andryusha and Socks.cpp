#include <iostream>
#include <unordered_set>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    int max_socks = 0, current_socks = 0;
    std::unordered_set<int> table;

    for (int i = 0; i < 2 * n; i++) {
        int sock;
        std::cin >> sock;

        if (table.find(sock) == table.end()) {
            // Sock is not on the table, put it on
            table.insert(sock);
            current_socks++;
        }
        else {
            // Sock pair is completed, remove it
            table.erase(sock);
            current_socks--;
        }

        max_socks = std::max(max_socks, current_socks);
    }

    std::cout << max_socks << "\n";
    return 0;
}
