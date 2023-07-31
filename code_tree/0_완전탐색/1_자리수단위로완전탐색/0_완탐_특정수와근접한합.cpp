// 10:10 ~ 10:19
#include <iostream>
#include <climits>
#include <algorithm>
#define MAX_N 100

using namespace std;

int n, s;   // s와 가까워지도록 n: 3~100, s:1~1만
int arr[MAX_N];

int main() {
    cin >> n >> s;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    // 조합으로 2개씩 빼주기
    int min_m = INT_MAX;    // 최저의 차이
    int tmp_m = 0;  // 차이를 저장할 값
    int tmp_sum = 0;    // 조합으로 나온 수를 저장할 값
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            tmp_sum = 0;
            tmp_m = 0;
            for(int k = 0; k < n; k++) {
                if(k == i || k == j) continue;  // 빼기로 선정한 값들은 빼주기
                tmp_sum += arr[k];  // 나머지 값들을 더하기
            }
            tmp_m = abs(tmp_sum - s);
            min_m = min(min_m, tmp_m);
        }
    }
    cout << min_m;
    
    // 고수 풀이의 경우 sum을 한번만 구하고, 빼기를 수행한다.
    // 즉, 내 풀이보다 더 계산 수가 더 적다.
    return 0;
}