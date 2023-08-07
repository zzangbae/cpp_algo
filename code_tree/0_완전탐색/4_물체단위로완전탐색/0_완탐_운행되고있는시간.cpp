// 12:28~12:36(8분/21분) on time
#include <iostream>
#include <vector>

using namespace std;

int n;  // 1~100
vector<pair<int, int>> v;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int s, e;   // [s, e)일하게 됨
        cin >> s >> e;
        v.push_back({s, e});
    }
    // 어떤 개발자를 뺄지는 물어보지 않았다**
    int max_time = 0;
    // i번째 개발자를 뺄 것
    for(int i = 0; i < n; i++) {
        int cnt[1001] = {0,};
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            int s = v[j].first;
            int e = v[j].second;
            for(int k = s; k < e; k++)
                cnt[k] = 1;
        }
        int tmp_time = 0;
        for(int l : cnt) {
            if(l == 1) tmp_time++;
        }
        max_time = max(tmp_time, max_time);
    }
    cout << max_time;
    return 0;
}

/**
 * 해설과 같은 로직으로 문제를 풀이하였다.
 * 다른 점은 직원의 시작 시간, 끝나는 시간을 따로 1차원 배열로 만들었다.
 * 만약 어느 직원이 퇴사하여야 하는가라고 물었다면?
 * -> max값을 tmp로 잡아두고, 바뀌었다면 그 때의 인덱스를 저장해야할 것 이다.
*/