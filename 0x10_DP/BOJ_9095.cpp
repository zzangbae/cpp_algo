#include<iostream>

using namespace std;

int dp[11];
int main() {
    // 테이블 정하기 -> 점화식 만들기 -> 초기값 만들기
    // 정수 n이 주어졌을 때, 1, 2, 3의 합으로 나타내는 방법의 수
    // dp[i] : 1, 2, 3의 합으로 i를 만드는 방법
    // 점화식 : dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    // 초기값 : dp[1] = 1, dp[2] = 2, dp[3] = 3
    int T;
    cin >> T;
    for(int tc = 0; tc < T; tc++) {
        // dp 테이블 초기화
        for(int i = 0; i < 11; i++) dp[i] = 0;
        // 초기값
        dp[1] = 1; 
        dp[2] = 2; 
        dp[3] = 4;
        int n;  // n은 양수이며 11보다 작은 수
        cin >> n;
        for(int i = 4; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        cout << dp[n] << "\n";
    }

    return 0;
}