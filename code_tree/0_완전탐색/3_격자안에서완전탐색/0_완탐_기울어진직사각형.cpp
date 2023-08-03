// 2:22~3:50(1시간 30분정도/3시간) on time but rest in test
#include <iostream>
#include <algorithm>
#define MAX_N 20
using namespace std;

int n;  // 3~20
int arr[MAX_N][MAX_N];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    
    // 시작점을 잡고
    // 시작점에서 시작해서 만들 수 있는 기울어진 직사각형...
    // 시작점은 그냥 점범위로 잡고, 안되는 범위를 필터링해서 풀어보자
    // (i, j)가 제일 아래의 점
    int max_pt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // k : 오른쪽 위로 몇 칸 올라가는지 세는 것 - 한칸 늘어날 때마다 다른 케이스이므로 세줘야함
            int tmp_pt = 0;
            int tmp_pt_2 = 0;
            int tmp_pt_3 = 0;
            int tmp_pt_4 = 0;
            for(int k = 1; i - k > 0 && j + k < n; k++) {
                tmp_pt += arr[i - k][j + k];
                tmp_pt_2 = 0;
                for(int l = 1; i - k - l >= 0 && j + k - l >= 0; l++) {
                    tmp_pt_2 += arr[i - k - l][j + k - l];
                    // 1, 2까지는 정해졌기 때문에 3, 4도 이제 정해진다.
                    tmp_pt_3 = 0;
                    for(int u = 1; u <= k; u++) {
                        if(i - k - l + k >= n || j + k - l - k < 0) continue;
                        tmp_pt_3 += arr[i - k - l + u][j + k - l - u];
                        tmp_pt_4 = 0;
                        for(int m = 1; m <= l; m++) {
                            tmp_pt_4 += arr[i - k - l + u + m][j + k - l - u + m];
                        }
                    }
                    if(tmp_pt * tmp_pt_2 * tmp_pt_3 * tmp_pt_4 != 0) {
                        max_pt = max(max_pt, tmp_pt + tmp_pt_2 + tmp_pt_3 + tmp_pt_4);
                    }
                }
            }
        }
    }
    cout << max_pt;
    return 0;
}

// 해설은 dx, dy와 거리를 잡고 문제를 풀 수 있도록 했다.
// 범위함수도 따로 빼줬다. -> 가독성이 올라가고, 초기화가 간단해진다.