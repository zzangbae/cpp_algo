// 6:14~6:29(15분, 나이스한 클리어)
#include <iostream>
#include <climits>
#include <algorithm>
#define MAX_N 20
using namespace std;

int n;
int arr[MAX_N][MAX_N];
int main() {
    // 입력
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    
    int max_coin = INT_MIN;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j + 2 < n; j++) {
            // 첫 번째 격자의 코인 갯수 확인
            int first_coin = arr[i][j] + arr[i][j + 1] + arr[i][j + 2];

            int second_coin = 0;
            for(int k = i; k < n; k++) {
                // 두 격자가 같은 라인에 있는 경우
                if(k == i) {
                    for(int l = j + 3; l + 2 < n; l++) {
                        second_coin = max(second_coin, arr[k][l] + arr[k][l + 1] + arr[k][l + 2]);
                    }
                }
                // 두 격자가 다른 라인에 있는 경우
                else {
                    for(int l = 0; l + 2 < n; l++) {
                        second_coin = max(second_coin, arr[k][l] + arr[k][l + 1] + arr[k][l + 2]);
                    }
                }
            }
            max_coin = max(max_coin, first_coin + second_coin);
        }
    }
    cout << max_coin;
    return 0;
}