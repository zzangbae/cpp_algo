// 11:36~11:42(6분/10분) on time
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int n;  // 2~100
vector<pair<int, int>> v;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;   // 0~1000
        cin >> x >> y;
        v.push_back({x, y});
    }

    // 2개의 점을 뽑아서 최소거리의 제곱
    int min_sq = INT_MAX;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int x1 = v[i].first;
            int y1 = v[i].second;
            int x2 = v[j].first;
            int y2 = v[j].second;
            min_sq = min(min_sq, (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        }
    }
    cout << min_sq;

    return 0;
}

/**
 * 해설의 경우, x[i], y[i]를 통해 1차원 상에서 저장함
 * - 인덱스는 몇 번째 점인지를 나타내게 된다.
*/