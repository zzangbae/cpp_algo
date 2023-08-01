#include <iostream>
#include <algorithm>

#define MAX_N 100

using namespace std;

int n, m;
int arr1[MAX_N], arr2[MAX_N];
int tmp[MAX_N];

int main() {
    // 입력
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr1[i];
	for(int i = 0; i < m; i++)
        cin >> arr2[i];
	
	sort(arr2, arr2 + m);
	
    // 모든 구간의 시작점을 잡아봅니다.
    int cnt = 0;
    for(int i = 0; i <= n - m; i++) {
        for(int j = 0; j < m; j++)
            tmp[j] = arr1[i + j];
		sort(tmp, tmp + m);
		
		bool issame = true;
		for(int j = 0; j < m; j++)
			if(tmp[j] != arr2[j]) {
				issame = false;
				break;
			}
		
		if(issame)
			cnt++;
    }
                        
    cout << cnt;
    return 0;
}

/**
 * 해설에서 배워야할 점
 * 크기가 같은 두 배열의 원소가 동일한지 비교해야 하는 상황
 * -> 두 배열을 sort함수를 통해서 정렬시키고 비교한다.
 * -> 단, 원 배열의 모양이 유지될 수 있도록, tmp배열을 하나 만들어서 활용한다. 
*/