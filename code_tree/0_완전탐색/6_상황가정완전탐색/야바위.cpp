// 7:06 ~ 7:22(16분/15분) 1분 overtime
#include <iostream>
#include <algorithm>
#define MAX_N 100
using namespace std;

int n;  // 1~100
int a[MAX_N];
int b[MAX_N];
int c[MAX_N];

int main() {
    cin >> n;
    int max_cnt = 0;
    int arr[3] = {0,};
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    
    int result = 0;
    // x는 처음있는 위치
    for(int x = 1; x <= 3; x++) {
        int tmp = 0;
        int now_x = x;
        for(int i = 0; i < n; i++) {
            // 현재 위치가 a라면 b로가기
            if(now_x == a[i]) {
                now_x = b[i];
            // 현재 위치가 b라면 a로가기
            } else if(now_x == b[i]) {
                now_x = a[i];
            }
            if(now_x == c[i]) tmp++;
        }
        result = max(result, tmp);
    }
    cout << result;
    return 0;
}