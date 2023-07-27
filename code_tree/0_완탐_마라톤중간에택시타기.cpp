#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
// 11:01~
// 한개 건너뜀(1, N번 체크포인트는 X)
int n;  // 3~100
int x, y;
vector<pair<int, int>> cp;  // check 포인트를 담을 벡터
int main() {
    // 입력 받기
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        cp.push_back({x, y});
    }

    // 체크 포인트를 하나씩 빼면서 최단거리를 체크하자
    int min_dis = INT_MAX;
    for(int i = 1; i < n - 1; i++) {
        // i번째 체크 포인트를 거르고자한다.
        vector<pair<int, int>> cp_tmp;  // 하나를 뺀 임시 cp들
        for(int j = 0; j < n; j++) {
            if(j == i) continue;
            cp_tmp.push_back(cp[j]);
        }

        int sum_dis = 0;
        for(int j = 1; j < cp_tmp.size(); j++) {
            int sx = cp_tmp[j - 1].first;
            int sy = cp_tmp[j - 1].second;
            int nx = cp_tmp[j].first;
            int ny = cp_tmp[j].second;
            sum_dis += abs(nx - sx) + abs(ny - sy); // 의미상 +=가 맞다! 누적!
        }
        min_dis = min(min_dis, sum_dis);
    }
    
    cout << min_dis;
    return 0;
}