#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
/**
 * 1143 문제와는 동일하다
 * 하지만 N을 1로 만드는 방법에 포함되어 있는 수를 공백으로 구분해서 출력해야함
 * 정답이 여러 가지인 경우에는 아무거나 출력한다.
*/

/**
 * 1. X가 3으로 나누어 떨어지면, 3으로 나누기
 * 2. X가 2로 나누어 떨어지면, 2로 나누기
 * 3. 1을 빼기
*/

/**
 * 이 문제의 요점은 어떻게 연산과정을 저장할 것인가가 포인트!
 * 즉, 경로 추적이 포인트이다! - 따로 pre 배열을 둬도 풀 수 있음!
*/

int n;
int dp[1000005][2];    // i번재 수를 1로 만드는 연산 최소 횟수, 2열에는 다음 수가 들어간다.
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + 1;
        dp[i][1] = i - 1;
        if(i % 3 == 0) {
            if(dp[i][0] > dp[i / 3][0]) {
                dp[i][0] = dp[i / 3][0] + 1;
                dp[i][1] = i / 3;
            }
        }
        if(i % 2 == 0) {
            if(dp[i][0] > dp[i / 2][0]) {
                dp[i][0] = dp[i / 2][0] + 1;
                dp[i][1] = i / 2;
            }
        }
    }

    cout << dp[n][0] << "\n";
    cout << n << " ";
    while(n != 1) {
        // dp[n][1] 은 다음 숫자
        cout << dp[n][1] << " ";
        n = dp[n][1]; 
    }
    return 0;
}