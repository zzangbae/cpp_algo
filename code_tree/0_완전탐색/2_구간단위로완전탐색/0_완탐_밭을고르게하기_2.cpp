#include <iostream>
#include <algorithm>
#include <climits>

#define MAX_N 100

using namespace std;

int n, h, t;
int arr[MAX_N];

int main() {
    // 입력
    cin >> n >> h >> t;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    // 모든 구간의 시작점을 잡아봅니다.
    int min_cost = INT_MAX;
    for(int i = 0; i <= n - t; i++) {
        // 해당 구간을 고르게 할 때의 비용을 구합니다.
        int cost = 0;
        for(int j = i; j < i + t; j++)
            cost += abs(arr[j] - h);
        
        // 최솟값을 구합니다.
        min_cost = min(min_cost, cost);
    }
                        
    cout << min_cost;
    return 0;
}

/**
 * 해설에서 배울점
 * 범위를 잡을 때
 * 해설의 경우 i가 n - t까지 잡았다.
 * -> 여차피 직접 다뤄지는 j가 i + t 전까지 다뤄진다.
 * 따라서 j의 범위가 n - 1까지 될 수 있고,
 * i + t = n까지 가능하다.
 * 즉, i <= n - t까지 가능하다.
 * ** 실제 배열 인덱스로 돌아가는 변수(j)를 활용해서 j를 다루는 i의 범위를 파악하기
 * ** index overflow가 안되도록 하는 범위를 나아감
*/