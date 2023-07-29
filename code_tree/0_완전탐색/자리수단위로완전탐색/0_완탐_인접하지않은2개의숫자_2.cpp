#include <iostream>
#include <climits>
#include <algorithm>
#include <cstdlib>

#define MAX_N 100

using namespace std;

int n;
int a[MAX_N];

int main() {
    // 입력
    cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
    
    // 인접하지 않은 모든 쌍을 다 잡아봅니다.
	int ans = INT_MIN;
    for(int i = 0; i < n; i++)
        for(int j = i + 2; j < n; j++)
            if(ans < a[i] + a[j])   // 이렇게 하면 내가했던 것처럼 tmp를 따로 둘 필요가 없다.
                ans = a[i] + a[j];
    
    cout << ans;
	
    return 0;
}