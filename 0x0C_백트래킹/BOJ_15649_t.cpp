#include<iostream>
using namespace std;

int n, m;
int arr[10];
int isused[10];

// k번째 값을 채우는 백트래킹
void func(int k) {
    if(k == m) {
        for(int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << "\n";
        return;
    }
    // 이 부분이 백트래킹 부분
    for(int i = 1; i <= n; i++) {
        if(!isused[i]) {
            arr[k] = i;
            isused[i] = 1;
            func(k + 1);
            isused[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0);
}