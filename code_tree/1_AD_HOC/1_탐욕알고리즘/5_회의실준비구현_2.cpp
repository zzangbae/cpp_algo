#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

int n;
vector<pair<int, int>> meetings;

int ans;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        meetings.push_back(make_pair(e, s));    // e를 먼저 -> 정렬 편함
    }

    sort(meetings.begin(), meetings.end());

    int last_e = -1;    // 가장 최근에 잡힌 회의가 끝난 시간을 기록
    for(int i = 0; i < n; i++) {
        int s, e;
        tie(e, s) = meetings[i];
        if(last_e <= s) {
            ans++;
            last_e = e; // e 갱신
        }
    }

    cout << ans;
    return 0;
}