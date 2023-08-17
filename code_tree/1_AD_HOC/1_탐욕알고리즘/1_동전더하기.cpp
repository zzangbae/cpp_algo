// 10:34~10:47(13분/10분) over time
#include <iostream>
#include <algorithm>
#define MAX_N 10

using namespace std;

int n;  // 1~10
int k;  // 1~1억
int arr[MAX_N];

bool descendingComparator(int a, int b) {
    return a > b; // '>' 연산자로 비교하여 내림차순 정렬
}

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    // 배수 상황 -> 큰게 많은 수록 좋습니다.
    // 큰 것부터 내림차순으로 바꾸기
    sort(arr, arr + n, descendingComparator);

    int cnt = 0;    // 동전 개수
    int money = 0;  // 지금까지 만든 돈
    for(int i = 0; i < n; i++) {
        if(money >= k) break;
        int tmp_cnt = (k - money) / arr[i]; // 필요한 동전 개수
        money += tmp_cnt * arr[i];
        cnt += tmp_cnt;
    }
    cout << cnt;
    return 0;
}
// sort함수을 썼으나, 사실 뒤에서부터 for문을 돌리면 되는 문제였다.