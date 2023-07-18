#include<iostream>
#include<queue>
using namespace std;

// bfs 1차원 버전인듯? queue에 넣어서

int n, k;
int arr[200005];

int main() {
    cin >> n >> k;  // n: 수빈위치, k: 동생위치
    for(int i = 0; i < 200005; i++) arr[i] = -1;
    arr[n] = 0; // 초기값 방문 설정
    queue<int> q;
    q.push(n);
    while(q.size()) {
        int now = q.front();
        // cout << "now : " << now << "\n";
        q.pop();
        if(now == k) break;
        // 범위 확인 및 방문확인 - 범위 안이고, 방문하지 않았던 점
        if(now - 1 >= 0 && now - 1 <= 200004 && arr[now - 1] == -1) {
            arr[now - 1] = arr[now] + 1; // 방문 설정됨
            q.push(now - 1);    // queue에 넣기
        }
        if(now + 1 >= 0 && now + 1 <= 200004 && arr[now + 1] == -1) {
            arr[now + 1] = arr[now] + 1;
            q.push(now + 1);
        }
        if(now * 2 >= 0 && now * 2 <= 200004 && arr[now * 2] == -1) {
            arr[now * 2] = arr[now] + 1;
            q.push(now * 2);
        }
    }
    cout << arr[k];
    return 0;
}