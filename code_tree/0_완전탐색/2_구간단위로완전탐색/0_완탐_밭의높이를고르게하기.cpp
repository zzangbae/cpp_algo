// 11:28~11:42(14분 소요)
#include <iostream>
#include <algorithm>
#include <climits>
#define MAX_N 100
using namespace std;

// n개의 밭, h높이 만들기, 연속하게 t번 이상
// 밭의 높이 0~200
int n, h, t;    // n,h:1~100, t:min(n, 10) - t는 최대 10
int arr[MAX_N];
int main() {
    cin >> n >> h >> t;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    // 시작점 i
    int min_cost = INT_MAX;
    for(int i = 0; i + t - 1 < n; i++) {
        int tmp_cost = 0;
        for(int j = i; j < i + t; j++) {
            tmp_cost += abs(arr[j] - h);
        };
        min_cost = min(min_cost, tmp_cost);
    }

    cout << min_cost;
    return 0;
}