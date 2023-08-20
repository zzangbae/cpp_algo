#include <iostream>
#include <algorithm>
#include <tuple>
#include <queue>

#define MAX_N 10000
#define MAX_T 10000

using namespace std;

// 변수 선언
int n;
pair<int, int> bombs[MAX_N];

// 폭탄 번호가 주어졌을 때
// 해당 폭탄의 시간제한을 반환합니다.
int GetTimeLimit(int bomb_idx) {
    int time_limit;
    tie(time_limit, ignore) = bombs[bomb_idx];

    return time_limit;
}

// 폭탄 번호가 주어졌을 때
// 해당 폭탄 해체시 얻게 되는 점수를 반환합니다.
int GetScore(int bomb_idx) {
    int score;
    tie(ignore, score) = bombs[bomb_idx];
    
    return score;
}

int main() {
    // 입력:
    cin >> n;
    for(int i = 0; i < n; i++) {
        int score, time_limit;
        cin >> score >> time_limit;
        // 시간을 기준으로 정렬해야 하므로
        // time_limit을 첫 번째 자리에 넣어줍니다.
        bombs[i] = make_pair(time_limit, score);
    }

    // 시간을 기준으로 오름차순 정렬해줍니다.
    sort(bombs, bombs + n);

    // MAX_T부터 1까지 보며
    // 해당 시간에 해체했을 때 가장 점수를 많이 얻을 수 있는 폭탄을 골라줍니다.
    // 이렇게 진행하는 방법이 항상 최선의 답을 구해줌을 이용합니다.
    // 이때 가능한 폭탄 중 최대 점수를 갖는 폭탄을 빠르게 골라주기 위해
    // 우선순위 큐를 이용합니다.
    priority_queue<int> pq;
    int bomb_idx = n - 1;
    int ans = 0;

    for(int t = MAX_T; t >= 1; t--) {
        // t초에 해체가 가능한 폭탄들을
        // 전부 우선순위 큐에 담아줍니다.
        while(bomb_idx >= 0 && GetTimeLimit(bomb_idx) >= t) {
            pq.push(GetScore(bomb_idx));
            bomb_idx--;
        }

        // 현재 시간에 해체 가능한 폭탄이 존재한다면
        // 그 중 가장 높은 점수를 얻을 수 있는 폭탄을 해체해줍니다.
        if(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;
    return 0;
}