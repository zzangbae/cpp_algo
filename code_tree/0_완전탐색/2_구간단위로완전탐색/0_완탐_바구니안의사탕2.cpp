// 10:36~
#include <iostream>
#include <climits>
#include <algorithm>
#define MAX_N 100

using namespace std;

int n, k; // n:1~100, k:1~200
int arr[MAX_N + 1];

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int c, b;
        cin >> c >> b;
        arr[b] += c; // 바구니 위치에 사탕갯수, 바구니가 겹쳐있을 수 있으므로, 추가
    }
    // 중심점의 범위
    int max_candy = INT_MIN;
    for(int i = 0; i <= 100 - 2 * k; i++) {
        int tmp_candy = 0;
        for(int j = 0; j <= 2 * k; j++) {
            tmp_candy += arr[i + j];
        }
        max_candy = max(max_candy, tmp_candy);
    }
    int mm_candy = 0;
    if(k > 50) {
        for(int i = 0; i <= 100; i++) {
            mm_candy += arr[i];
        }
        cout << mm_candy;
        return 0;
    }
    cout << max_candy;
    return 0;
}