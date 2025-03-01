#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Runner {
    string name;
    long long speed;
};

bool compare(Runner a, Runner b) {
    return a.speed > b.speed;  
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        vector<Runner> runners = {
            {"Hussien", 0},
            {"Atef", 0},
            {"Karemo", 0},
            {"Ezzat", 0}
        };

      
        for (int i = 0; i < 4; i++) {
            cin >> runners[i].speed;
        }

       
        sort(runners.begin(), runners.end(), compare);

      
        cout << runners[0].name << " " << runners[1].name << endl;
    }

    return 0;
}
