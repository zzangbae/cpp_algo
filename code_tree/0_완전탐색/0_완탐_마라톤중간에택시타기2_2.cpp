#include <iostream>
#include <climits>
#include <algorithm>

#define MAX_N 100

using namespace std;

int n;
int x[MAX_N], y[MAX_N];

int main() {
    // 변수 선언 및 입력
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    // 각 i번째 체크 포인트를 건너 뛰었을 떄의 거리를 구하기
    int ans = INT_MAX;  // 최소값을 구하는 것이 목표기 때문에 최댓값에서 시작
    for(int i = 1; i < n - 1; i++) {
        // 거리 구하기
        int dist = 0;
        int prev_idx = 0;
        for(int j = 1; j < n; j++) {
            if(j == i) continue;    // j == i일때, prev_idx는 갱신하지 않아서 i - 1와 i + 1가 비교되게 된다.
            dist += abs(x[prev_idx] - x[j]) + abs(y[prev_idx] - y[j]);
            prev_idx = j;
        }

        // 가능한 거리 중 최솟값을 구해주기
        ans = min(ans, dist);
    }

    // 출력
    cout << ans;
    return 0;
}

/**
    내 풀이와 거의 유사하나 1차원배열을 활용해서 간단하게 풀이를 유도함
*/