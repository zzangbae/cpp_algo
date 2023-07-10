#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 이 문제는 백트래킹으로도 가능하다
 * 하지만 백트래킹은 O(2^N)이므로 N=300이면 어림도 없음
 * DP가 훨씬 빠르다!
*/

/**
 * 계단은 한단계 혹은 2단계씩 오를 수 있음.
 * 연속된 3개의 계단을 모두 밟아선 안된다. 단, 시작점 계단X
 * 마지막 계단은 무조건 밟아야한다.
 * 계단에 쓰여진 점수가 주어질 때, 얻을 수 있는 총 점수의 최댓값
 * 계단에 쓰여 있는 점수는 10,000이하의 자연수
*/
int arr[305];   // 계단의 점수를 담을 배열
int dp[305];    // dp1.테이블설정 - i번계단까지 올라오는데 얻는 최대 점수

int main() {
    int n;
    cin >> n;   // 계단의 갯수
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    dp[1] = arr[1]; // 첫번째 계단은 그 점수 자체 - dp3.초기값
    // dp2.점화식 설정
    // dp[i]는 2개중 큰값
    // 1. dp[i - 2] + arr[i]
    // 2. dp[i - 3] + arr[i - 1] + arr[i]
    for(int i = 2; i <= n; i++) {
        dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
    }
    cout << dp[n];
}