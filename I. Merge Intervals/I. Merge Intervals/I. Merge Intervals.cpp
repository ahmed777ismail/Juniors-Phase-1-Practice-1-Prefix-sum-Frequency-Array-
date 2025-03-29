#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int l, r;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<Interval> intervals(N);
    for (int i = 0; i < N; i++) {
        cin >> intervals[i].l >> intervals[i].r;
    }

    // Sort intervals by the left endpoint
    sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
        return a.l < b.l;
        });

    vector<Interval> merged;
    // Start with the first interval
    Interval current = intervals[0];

    for (int i = 1; i < N; i++) {
        // If intervals overlap (they intersect)
        if (intervals[i].l <= current.r) {
            // Merge by updating the right endpoint to be the maximum.
            current.r = max(current.r, intervals[i].r);
        }
        else {
            // No intersection, add the current interval and move to the next
            merged.push_back(current);
            current = intervals[i];
        }
    }
    // Push the last interval
    merged.push_back(current);

    // Print merged intervals sorted by their left endpoint.
    for (const auto& interval : merged) {
        cout << interval.l << " " << interval.r << "\n";
    }

    return 0;
}
