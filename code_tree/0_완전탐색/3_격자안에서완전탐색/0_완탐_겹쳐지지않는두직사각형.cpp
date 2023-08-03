// 4:35~5:45(1시간 10분/3시간) clear but rest in time
#include <iostream>
#include <algorithm>
#include <climits>
#define MAX_N 5
#define MAX_M 5
using namespace std;

int n, m;   // 2~5
int grid[MAX_N][MAX_M];
int visited[MAX_N][MAX_M];

// 시작점이 (x, y) 끝점이 (k, l)일 때 score를 반환하는 함수
int GetScore(int x, int y, int k, int l) {
    int score = 0;
    for(int i = x; i <= k; i++)
        for(int j = y; j <= l; j++)
            score += grid[i][j];
    return score;
}

bool InRange(int a, int b, int c, int d) {
    for(int i = a; i <= c; i++) {
        for(int j = b; j <= d; j++) {
            // 첫번째 상자와 겹치는 부분이 있다면
            if(visited[i][j] == 1) {
                return true;
            }
        }
    }
    return false;
}

int GetSecondMaxScore(int x, int y, int k, int l) {
    // 두번째 사각형의 최대 점수를 구해보자
    int second_max_score = INT_MIN; // 이 값이 유지되면 2번째 값이 없는 것이다.
    // (a, b)는 두번째 사각형의 왼쪽 위점
    for(int a = 0; a < n; a++) {
        for(int b = 0; b < m; b++) {
            // (c, d)는 두번째 사각형 오른쪽 아래점
            for(int c = a; c < n; c++) {
                for(int d = b; d < m; d++) {
                    if(InRange(a, b, c, d)) continue;   // 만약 범위가 겹치면 스킵
                    second_max_score = max(second_max_score, GetScore(a, b, c, d));
                }
            }
        }
    }
    return second_max_score;
}

void visited_clear() {
    for(int i = 0; i < MAX_N; i++)
        for(int j = 0; j < MAX_M; j++)
            visited[i][j] = 0;
}

void visited_fill(int x, int y, int k, int l) {
    for(int i = x; i <= k; i++) 
        for(int j = y; j <=l; j++)
            visited[i][j] = 1;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];
    
    int ans = INT_MIN;  // 마이너스 값이 있으므로 INT_MIN으로 한다.
    // (i, j)가 직사각형 왼쪽 위의 점
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            // (k, l)이 직사각형 오른쪽 아래의 점
            for(int k = i; k < n; k++) {
                for(int l = j; l < m; l++) {
                    // visited 초기화(첫번째 직사각형이 차지하는 공간)
                    visited_clear();
                    // visited 다시 채우기
                    visited_fill(i, j, k, l);
                    int tmp_f_score = GetScore(i, j, k, l);
                    int tmp_s_score = GetSecondMaxScore(i, j, k, l);
                    // 2번째 사각형이 INT_MIN이면 2번째 직사각형을 만들 수 없는 상황이다.
                    if(tmp_s_score == INT_MIN) continue;
                    // (i, j), (k, l)이 첫번째 직사각형의 끝점일 때, 2번째 직사각형 너비와의 합의 최댓값을 반환하는 함수
                    ans = max(ans, tmp_f_score + tmp_s_score);
                }
            }
        }
    }  
    cout << ans;
    
    return 0;
}