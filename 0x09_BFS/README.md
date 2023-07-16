## BFS(너비우선 탐색)

* BFS -> 큐, while문을 통해서 그래프나 그리드를 탐색
* 삼성 기출 문제로 자주 등장
* 다양한 문제를 풀면서 환경에 익숙해지자

### BFS 의의

* 완전 탐색을 할 때, 어떻게 접근해야하는지에 대한 기반 논리 중 하나임을 기억하자
* queue를 활용하여 순서대로 다 나아가는 방법을 익히는 것

### 알고리즘

* BFS(Breadth First Search)

* 다차원 배열에서 각 칸을방문할 때 너비를 우선으로 방문하는 알고리즘

* 자료구조에서 모든 노드를 방문하기 위해서 만들어진 알고리즘

* 알고리즘 대략 과정

  * 시작점을 queue에 넣는다.

  * 시작점을 방문처리 한다.

  * (반복)

    * 큐에서 front를 뺀다(pop)
    * 상하좌우 4방향에 대해서 갈 수 있는지 여부와 문제의 조건을 판단한다.(방문한 점 안가기, 벽 안가기 등)
    * 다음 점으로 선정 가능한 점을 큐에 넣고, 방문처리를 한다

  * **주의점

    * 시작점을 우선 방문처리하기

      => 시작점을 2번 방문할 수 있음

    * 다음 점으로 선정한 가능한 점을 큐에 넣을 때 방문처리하기(push)

      => 큐에서 빼는 순간 방문처리하는 경우, 같은 칸이 큐에 여러 번 들어가게 되어, 시간초과나 메모리 초과가 발생할 수 있음(1, 2, 3이 ㄱ자로 인접한다고 할 때, 1, 3칸이 먼저 큐에서 나오면 2가 2번 큐에 들어갈 수 있음)

    * 이웃한 원소가 범위를 벗어났는지 체크하기

* 시간복잡도 : O(N), O(RC) - R : 행, C : 열

### 코드 예시

```cpp
#include<iostream>
#include<queue>
using namespace std;

int board[502][502];
bool vis[502][502];
int n, m;   // 입력값으로 주어짐 - 일반적으로 r, c
int dx[4] = {-1, 0, 1, 0};  // 상하좌우
int dy[4] = {0, 1, 0, -1};  // 상하좌우

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // 입력으로 그리드 환경이 주어짐
    queue<pair<int, int>> q;
    vis[0][0] = 1;  // 시작점 방문처리 ** 중요 **
    q.push({0, 0});
    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();    // cur : 현재점
        int x = cur.first;
        int y = cur.second;
        // 상 하 좌 우 판단 - 다음점
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // 범위 체크
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            // 방문 체크, 1은 예시 - 벽
            if(vis[nx][ny] || board[nx][ny] != 1) continue;
            vis[nx][ny] = 1;    // 다음 점 방문체크 ** 중요 **
            q.push({nx, ny});   // 큐에 넣기
        }
    }
}
```


