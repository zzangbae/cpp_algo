#include <iostream>
#include <algorithm>

#define MAX_NUM 100

using namespace std;

int n, k;
int arr[MAX_NUM + 1];

int main() {
    // 입력
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; char c;
        cin >> x >> c;
        
        if(c == 'G')
            arr[x] = 1;
        else
            arr[x] = 2;
    }
    
    // 모든 구간의 시작점을 잡아봅니다.
    int max_len = 0;
    for(int i = 0; i <= MAX_NUM; i++) {
		for(int j = i + 1; j <= MAX_NUM; j++) {
			// i와 j 위치에 사람이 있는지 확인합니다.(***)
			if(arr[i] == 0 || arr[j] == 0)
				continue;
			
			// 해당 구간 내 g와 h의 개수를 구합니다.
			int cnt_g = 0;
			int cnt_h = 0;
			
			for(int k = i; k <= j; k++) {
				if(arr[k] == 1)
					cnt_g++;
				if(arr[k] == 2)
					cnt_h++;
			}
			
			// 조건을 만족할 때 구간의 길이를 구해 최댓값과 비교합니다.(****)
			if(cnt_g == 0 || cnt_h == 0 || cnt_g == cnt_h) {
				int len = j - i;
				max_len = max(max_len, len);
			}
		}
    }
                        
    cout << max_len;
	
    return 0;
}

/**
 * 해설에서 배워야할 점
 * 시작점과 끝점이 같은 경우, 0이므로 여차피 정답에 영향이없다.
 * -> j의 범위를 i+1로 잡았다.
 * 시작점이나 끝점에 사람이 없는 경우
 * -> 미리 처리해준다.(***표시)
 * -> 그리고, 조건을 다음에 놓아줌으로써, 간결하게 사용할 수 있다.(****표시)
 * 하지만, 거의 유사하다.
*/