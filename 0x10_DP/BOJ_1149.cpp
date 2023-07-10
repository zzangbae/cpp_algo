#include<iostream>

using namespace std;

/**
 * dp: 테이블, 점화식, 초기값
 * 붙어있는 집과 색이 달라야한다
 * 칠하는 비용 1000이하
 * N <= 1000
 * 모든 집을 칠하는 최소 비용
*/
// dp 추측 : 무엇인가 누적을 찾는다? -> dp 가능성 높음
int n;
int arr[1004][3];
int dp[1004][3];    // dp1. 테이블 설정 i번째 어떤 색 칠하는데 최소비용
// dp2. 점화식
// dp[i][0] = min(dp[i - 1][1] + arr[i][0], dp[i - 1][2] + arr[i][0])

int main() {
    int n;
    cin >> n;
    dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0;   // 시작점은 0
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }
    dp[1][0] = arr[1][0];   // dp3. 초기값 설정
    dp[1][1] = arr[1][1];
    dp[1][2] = arr[1][2];
    for(int i = 2; i <= n; i++) {
        dp[i][0] = min(dp[i - 1][1] + arr[i][0], dp[i - 1][2] + arr[i][0]);
        dp[i][1] = min(dp[i - 1][0] + arr[i][1], dp[i - 1][2] + arr[i][1]);
        dp[i][2] = min(dp[i - 1][0] + arr[i][2], dp[i - 1][1] + arr[i][2]);
    }
    cout << min(dp[n][0], min(dp[n][1], dp[n][2]));
    return 0;
}