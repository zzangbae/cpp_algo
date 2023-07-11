#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/**
 * N + 1일째 퇴사하기 위해서 N일 동안 최대한 많은 상담을 하고자한다
 * 퇴사전 최대 수익을 구하는 프로그램
*/

// 특정일에 일을 했을 경우, n일의 최댓값

int n;
int T[1004];
int P[1004];
int dp[1004]; // 해당일에 일을 시작했을 때 벌 수 있는 최대 이익

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> T[i] >> P[i];
    }
    // 뒤에서 부터 생각해보자 - 점화식을 활용하는 것은 아니다.
    int next; // 다음 일을 할 날짜
    for(int i = n; i >= 1; i--) {
        next = i + T[i];
        // 다음 일이 n일을 넘어섰다면
        if(next > n + 1) {
            dp[i] = dp[i + 1];
        }
        else {
            dp[i] = max(dp[i + 1], dp[next] + P[i]);
        }
    }

    cout << dp[1] << "\n";

    return 0;
}