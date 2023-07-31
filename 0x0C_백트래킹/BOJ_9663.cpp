#include<iostream>

using namespace std;

/**
 * 그 유명한 N퀸 문제
 * N x N 체스판에서 퀸 N개를 서로 공격하지 못하는 위치에 놓는 경우의 수를 구하는 문제
*/
int N;  // N : 1 ~ 15
bool isused1[40];   // 열             -> 위에서 아래로의 열
bool isused2[40];   // 행 + 열         -> 오른쪽 위로 향하는 대각선
bool isused3[40];   // 행 - 열 + N - 1 -> 오른쪽 아래로 향하는 대각선
int cnt;

void func(int cur) {
    if (cur == N) {
        cnt++;
        return;
    }
    for(int i = 0; i < N; i++) {
        if(isused1[i] || isused2[i + cur] || isused3[cur - i + N - 1]) continue;
        isused1[i] = 1;
        isused2[i + cur] = 1;
        isused3[cur - i + N - 1] = 1;
        func(cur + 1);
        isused1[i] = 0;
        isused2[i + cur] = 0;
        isused3[cur - i + N - 1] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    func(0);
    cout << cnt;
}