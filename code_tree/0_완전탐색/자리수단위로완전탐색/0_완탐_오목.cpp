#include <iostream>
// 5:38~6:00 (22분, but 모든 경우를 온전하게 생각하지 못했음)
#define INT_N 19
using namespace std;

// 검은색 win -> 1 : 검은색 바둑알
// 흰색 win -> 2 : 흰색 바둑알
// 아직 승부 결정x -> 0
// 추가 출력 : 이겼을 경우, 이긴 바둑알의 가로줄 번호와 세로줄 번호
int arr[INT_N][INT_N];
int main() {
    for(int i = 0; i < INT_N; i++)
        for(int j = 0; j < INT_N; j++)
            cin >> arr[i][j];
    
    // 한 칸씩 아래로 가면서 5개의 연속된 칸을 확인 + 대각선
    for(int i = 0; i < INT_N; i++) {
        for(int j = 0; j + 4 < INT_N; j++) {
            if(arr[i][j] == 1 && arr[i][j + 1] == 1 && arr[i][j + 2] == 1 && arr[i][j + 3] == 1 && arr[i][j + 4] == 1) {
                cout << 1 << "\n";
                cout << i + 1 << " " << j + 3;
                return 0;    
            }
            if(arr[i][j] == 2 && arr[i][j + 1] == 2 && arr[i][j + 2] == 2 && arr[i][j + 3] == 2 && arr[i][j + 4] == 2) {
                cout << 2 << "\n";
                cout << i + 1 << " " << j + 3;
                return 0;
            }
        }
    }

    // 한 칸씩 오른쪽으로 가면서 5개의 연속된 칸을 확인(오른쪽 아래 대각선)
    for(int i = 0; i + 4< INT_N; i++) {
        for(int j = 0; j + 4 < INT_N; j++) {
            if(arr[j][i] == 1 && arr[j + 1][i] == 1 && arr[j + 2][i] == 1 && arr[j + 3][i] == 1 && arr[j + 4][i] == 1) {
                cout << 1 << "\n";
                cout << j + 3 << " " << i + 1;
                return 0;    
            }
            if(arr[j][i] == 2 && arr[j + 1][i] == 2 && arr[j + 2][i] == 2 && arr[j + 3][i] == 2 && arr[j + 4][i] == 2) {
                cout << 2 << "\n";
                cout << j + 3 << " " << i + 1;
                return 0;    
            }
        }
    }

    // 왼쪽 아래로 가는 대각선
    for(int i = 4; i < INT_N; i++) {
        for(int j = 0; j + 4 < INT_N; j++) {
            if(arr[i][j] == 1 && arr[i - 1][j + 1] == 1 && arr[i - 2][j + 2] == 1 && arr[i - 3][j + 3] == 1 && arr[i - 4][j + 4] == 1) {
                cout << 1 << "\n";
                cout << i - 1 << " " << j + 3;
                return 0;
            }
            if(arr[i][j] == 2 && arr[i - 1][j + 1] == 2 && arr[i - 2][j + 2] == 2 && arr[i - 3][j + 3] == 2 && arr[i - 4][j + 4] == 2) {
                cout << 2 << "\n";
                cout << i - 1 << " " << j + 3;
                return 0;
            }
        }
    }

    // 오른쪽 아래로 가는 대각선
    for(int i = 0; i + 4< INT_N; i++) {
        for(int j = 0; j + 4< INT_N; j++) {
            if(arr[i][j] == 1 && arr[i + 1][j + 1] == 1 && arr[i + 2][j + 2] == 1 && arr[i + 3][j + 3] == 1&& arr[i + 4][j + 4] == 1) {
                cout << 1 << "\n";
                cout << i + 3 << " " << j + 3;
                return 0;
            }
            if(arr[i][j] == 2 && arr[i + 1][j + 1] == 2 && arr[i + 2][j + 2] == 2 && arr[i + 3][j + 3] == 2 && arr[i + 4][j + 4] == 2) {
                cout << 2 << "\n";
                cout << i + 3 << " " << j + 3;
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}