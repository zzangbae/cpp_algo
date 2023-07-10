#include<iostream>

using namespace std;

int dp[11]; // 1. 테이블 설정. i를 1, 2, 3으로 합으로 만드는 방법
int main() {
    // dp를 한번만 계산하기
    // 3. 초기값 설정
    dp[1] = 1; dp[2] = 2; dp[3] = 4;
    for(int i = 4; i < 11; i++) {
        // 2. 점화식 찾기
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    int T;
    cin >> T;
    for(int tc = 0; tc < T; tc++) {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }

    return 0;
}