// 11:10 ~ 11:58(48분/180분) - clear
#include <iostream>
#include <algorithm>
#define MAX_N 20
using namespace std;

// ** n = 1일 때의 상황 다시 보기
int n, m;   // 1~20, 금한개의 가격은 m , 시간복잡도 대략 O(N^3)으로 해도 풀 수 있겠다.
int arr[MAX_N][MAX_N];
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    // k는 배수
    int max_gold = 0;
    for(int k = 0; k <= 2 * n - 2; k++) {
        int cost = k * k + (k + 1) * (k + 1);
        // 마름모의 중심점(i, j)
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                // 뻗어나가는 좌표(a, b)
                int gold_cnt = 0;
                for(int a = i - k; a <= i + k; a++) {
                    for(int b = j - k; b <= j + k; b++) {
                        if(a < 0 || a >= n || b < 0 || b >= n) continue; // 범위를 넘어감
                        if(abs(a - i) + abs(b - j) > k) continue; // 마름모의 범위 설정 ** 이부분이 스킬
                        if(arr[a][b] == 1) gold_cnt++;
                    }
                }
                // 비용비교(손해를 안보는 경우)
                if(gold_cnt * m >= cost) {
                    max_gold = max(max_gold, gold_cnt);
                } // 만약 손해라면 max_gold를 갱신할 필요없다.
            }
        }
    }
    cout << max_gold;
    
    return 0;
}