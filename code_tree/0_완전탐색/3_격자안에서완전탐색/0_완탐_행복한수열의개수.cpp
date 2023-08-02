// 9:43~10:17(34분/180분) - clear
#include <iostream>
#define MAX_N 100
using namespace std;

int n, m;   // m <= n : 1 ~ 100
int arr[MAX_N + 1][MAX_N + 1];
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    
    int beauty_cnt = 0;
    // 행을 내려가며 분석
    // 시작점의 행
    for(int i = 0; i < n; i++) {
        // 시작점의 열
        for(int j = 0; j < n; j++) {
            bool is_beauty = true;
            if(j + m > n) break;    // 해당 행에선 더이상 m개의 수열이 있을 수 없다.
            for(int k = j; k < j + m - 1; k++) {
                if(arr[i][k + 1] != arr[i][k]) {
                    is_beauty = false;
                    break;
                }
            }
            if(is_beauty) {
                beauty_cnt++;
                break;
            }
        }
    }

    // 2. 열을 지나가며 분석
    // 시작점의 열
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < n; i++) {
            bool is_beauty = true;
            if(i + m > n) break;
            for(int k = i; k < i + m - 1; k++) {
                if(arr[k + 1][j] != arr[k][j]) {
                    is_beauty = false;
                    break;
                }
            }
            if(is_beauty) {
                beauty_cnt++;
                break;  // 해당 열은 더이상 확인하지 않아도 된다.
            }
        }
    }
    cout << beauty_cnt;
    return 0;
}

/**
 * 해설에서 배울점
 * 범위를 지정하고 따로 변수를 둠
 * 그리고 가로든 세로든 수열을 하나씩 아름다운 수열인지 판단함
 * 그리고 연속된 숫자의 개수를 활용할 때 쓰는 방법을 유의하자
 * 15 - 22줄
*/