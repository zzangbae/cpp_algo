// 10:18~10:40(22분/100분) - on time
#include <iostream>
#include <climits>
#include <algorithm>
#define MAX_N 200
#define MAX_M 200
using namespace std;

int n, m; // 3~200 n*m크기의 영역
int arr[MAX_N][MAX_M];
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];

    int max_p = INT_MIN;
    // 시작점의 위치(i, j)로 하여, 모든 점을 순회하고, 각 상황마다 범위를 벗어나는지 여부를 판단하자
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int tmp_1 = 0;
            // 1. 가로 일자형 케이스
            if(j + 2 < m) {
                tmp_1 += arr[i][j] + arr[i][j + 1] + arr[i][j + 2];
            }
            // 2. 세로 일자형
            int tmp_2 = 0;
            if(i + 2 < n) {
                tmp_2 += arr[i][j] + arr[i + 1][j] + arr[i + 2][j];
            }
            // 2. ㄱ자형 케이스 - 결국 네모에서 한 칸을 빼는 것이라 생각하면 된다.
            int tmp_3 = 0;
            if(i + 1 < n && j + 1 < m) {
                // 4칸 중 가장 작은 칸을 빼는 것이 이익
                int min_p = min(arr[i][j], min(arr[i][j + 1], min(arr[i + 1][j], arr[i + 1][j + 1])));
                tmp_3 = arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1] - min_p;
            }
            int tmp_p = max(tmp_1, max(tmp_2, tmp_3));
            max_p = max(max_p, tmp_p);
        }
    }
    cout << max_p;
    return 0;
}