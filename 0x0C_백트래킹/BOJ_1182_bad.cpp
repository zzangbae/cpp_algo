#include<iostream>
using namespace std;

/* 중복나는 코드 */

/**
 * 부분수열의 합
 * N개의 정수로 이루어진 수열이 있을 때,
 * 크기가 양수인 부분 수열 중에서 그 수열의 원소를 다 더한 값이 S가 되는 경우의 수
 * N : 1 ~ 20
 * S : -100만 ~ 100만
 * 주어지는 정수의 절대값은 10만을 넘지 않는다.
 * 부분 수열의 합이 S가 되는 부분수열 개수를 출력하는 것이 목표
*/
// 10만 * 20해도 200만 이므로 int안에서 해결이 가능
int n, s;
int arr[20];
bool isused[20];    // 결과값을 어떻게 저장해나갈 것인가.
int cnt;

// i번째 값을 넣어주고 빼면서 백트래킹
// k는 요소들의 값을 더한 값
void func(int k) {
    // 모든 값에 대해서 OX 여부를 결정했다면 끝
    if(k == n) {
        // 모두 다 더한 값을 확인하고, 맞으면 cnt++, 아니면 끝내기
        int res = 0;
        for(int i = 0; i < n; i++) {
            cout << isused[i] << " ";
            if(isused[i]) {
                res += arr[i];
            }
        }
        cout << "\n";
        if(res == s) cnt++;
        return;
    }
    for(int i = k; i < n; i++) {
        isused[i] = 1;
        func(k + 1);
        isused[i] = 0;
        func(k + 1);
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> arr[i];
    func(0);
    cout << cnt;
}