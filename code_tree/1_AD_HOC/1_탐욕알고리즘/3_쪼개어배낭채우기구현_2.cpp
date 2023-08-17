#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int n, m;
vector<tuple<double, int, int>> jewels;
double ans;

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        jewels.push_back(make_tuple(-(double)v/w, w, w));
    }

    // 위에서 값을 -로 저장했기 때문에 절대값이 큰 값부터 내림차순으로 정렬된다.
    sort(jewels.begin(), jewels.end());

    for(int i = 0; i < n; i++) {
        int w, v;
        tie(ignore, w, v) = jewels[i];
        // 현재 보석을 온전히 다 담을 수 있다면 그대로 담아줍니다.
        if(m >= w) {
            m -= w;
            ans += v;
        }
        // 만약 부분만 담을 수 있다면 비율에 맞추기
        else {
            ans += (double)m / w * v;
            break;
        }
    }
    // 아래는 부동 소수점3
    cout << fixed;
    cout.precision(3);
    cout << ans;

    return 0;
}