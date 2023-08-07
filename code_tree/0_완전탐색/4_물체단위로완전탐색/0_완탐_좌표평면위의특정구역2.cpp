// 11:23~11:34(11분/27분) on time
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;  // 3 ~ 100
vector<pair<int, int>> v; 

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;   // 1 ~ 40,000
        cin >> x >> y;
        v.push_back({x, y});
    }

    int min_sq = INT_MAX;
    // 정확히 한점을 뺀 직사각형의 최소 너비
    // i번째 점을 뺀 경우
    for(int i = 0; i < v.size(); i++) {
        // 0~n번째 점에서 만들어지는 직사각형 최소너비(i번째 제외)
        int min_x = INT_MAX;
        int max_x = INT_MIN;
        int min_y = INT_MAX;
        int max_y = INT_MIN;

        for(int j = 0; j < v.size(); j++) {
            if(i == j) continue;
            int x = v[j].first;
            int y = v[j].second;
            min_x = min(x, min_x);
            max_x = max(x, max_x);
            min_y = min(y, min_y);
            max_y = max(y, max_y);
        }
        min_sq = min(min_sq, (max_x - min_x) * (max_y - min_y));
    }

    cout << min_sq;

    return 0;
}

/**
 * 해설풀이와 동일하게 문제풀이했음
*/