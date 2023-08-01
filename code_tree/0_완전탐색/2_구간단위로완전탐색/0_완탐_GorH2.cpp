// 10:56~11:18(22분/38분)
#include <iostream>
#include <algorithm>
#define MAX_N 100
using namespace std;

int n;
int arr[MAX_N + 1];

// 1. only G
// 2. only H
// 3. 정확히 두 개가 같게
// 최대 사진의 크기
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a;
        char c;
        cin >> a >> c;
        if(c == 'G') arr[a] = 1;
        else if(c == 'H') arr[a] = 2;
    }

    int max_size = 0;
    // i는 시작 위치
    for(int i = 0; i <= MAX_N; i++) {
        if(arr[i] == 0) continue;   // 시작점이 0인 경우는 제외한다.
        // j는 끝위치
        for(int j = i; j <= MAX_N; j++) {
            if(arr[j] == 0) continue;   // 끝점이 0인 경우는 제외한다.
            int g_cnt = 0;
            int h_cnt = 0;
            // i ~ j 인 동안에
            for(int k = i; k <= j; k++) {
                if(arr[k] == 1) g_cnt++;
                else if(arr[k] == 2) h_cnt++;
            }
            if(g_cnt == 0 && h_cnt == 0) {
                continue;
            }
            else if(g_cnt == 0 && h_cnt != 0) { // h뿐 없는 경우
                max_size = max(max_size, j - i);
            } 
            else if(g_cnt != 0 && h_cnt == 0) {
                max_size = max(max_size, j - i);
            }
            else if(g_cnt == h_cnt) {
                max_size = max(max_size, j - i);
            }
        }
    }
    cout << max_size;

    return 0;
}