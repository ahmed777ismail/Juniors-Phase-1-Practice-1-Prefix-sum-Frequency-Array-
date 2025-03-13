#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int l, r;
    Interval(int l_, int r_) : l(l_), r(r_) {}
};

bool compareIntervals(const Interval& a, const Interval& b) {
    return a.l < b.l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int q;
    cin >> q;
    vector<Interval> intervals;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        intervals.emplace_back(l, r);
    }

    vector<Interval> merged;
    if (!intervals.empty()) {
        sort(intervals.begin(), intervals.end(), compareIntervals);
        merged.push_back(intervals[0]);
        for (size_t i = 1; i < intervals.size(); ++i) {
            Interval current = intervals[i];
            Interval& last = merged.back();
            if (current.l <= last.r) {
                last.r = max(last.r, current.r);
            }
            else {
                merged.push_back(current);
            }
        }
    }

    vector<int> remaining;
    for (int i = 0; i < n; ++i) {
        int idx = i + 1; // Convert to 1-based index
        int left = 0, right = merged.size() - 1;
        int pos = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (merged[mid].l <= idx) {
                pos = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        if (pos == -1 || merged[pos].r < idx) {
            remaining.push_back(a[i]);
        }
    }

    cout << remaining.size() << "\n";
    if (!remaining.empty()) {
        for (size_t i = 0; i < remaining.size(); ++i) {
            if (i > 0) cout << " ";
            cout << remaining[i];
        }
        cout << "\n";
    }

    return 0;
}