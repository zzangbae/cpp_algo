#include<iostream>

using namespace std;

int n;  // 가로길이
int dp[1004];   // dp1. 테이블설정 : i길이 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지

int main() {
    cin >> n;
    // dp3. 초기값 설정
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++) {
        // dp2. 점화식 설정
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= 10007;
    }
    cout << dp[n];
}