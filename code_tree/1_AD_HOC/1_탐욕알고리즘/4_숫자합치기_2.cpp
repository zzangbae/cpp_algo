#include <iostream>
#include <queue>

#define MAX_N 100000

using namespace std;

int n;
int arr[MAX_N];

priority_queue<int> pq;
int ans;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    // 우선순위 큐에 원소를 전부 넣어준다.
    // 작은숫자가 골라질 수 있도록 -를 붙여줘야한다.
    for(int i = 0; i < n; i++)
        pq.push(-arr[i]);
    
    // 원소가 2개 이상이면 계속
    // 가장 작은 숫자를 2개를 골라서 합치는 것을 반복
    while(pq.size() > 1) {
        int x1 = pq.top(); pq.pop();
        int x2 = pq.top(); pq.pop();
        x1 = -x1;   // 원래값으로 바꿔주기
        x2 = -x2;   // 원래값으로 바꿔주기

        ans += (x1 + x2);
        pq.push(-(x1, x2)); // 다시 음의 값으로 넣어주기
    }

    cout << ans;
    return 0;
}