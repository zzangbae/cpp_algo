// 해설 코드 공부
#include <iostream>
#include <algorithm>

#define MAX_N 1000

using namespace std;

int n, b;
int p[MAX_N];

int main() {
    cin >> n >> b;

    for(int i = 0; i < n; i++)
        cin >> p[i];

    int ans = 0;

    // i번째 학생에 선물 쿠폰을 쓸 때 선물 가능한 학생의 최대 명수를 구한다.
    for(int i = 0; i < n; i++) {
        int tmp[MAX_N] = {};
        for(int j = 0; j < n; j++)
            tmp[j] = p[j];
        tmp[i] /= 2;

        sort(tmp, tmp + n);

        int student = 0;    // 선물받은 학생의 수
        int cnt = 0;        // 현재까지 쓴 돈

        for(int j = 0; j < n; j++) {
            if(cnt + tmp[j] > b) break; // 다음 학생의 선물을 사주면 예산을 초과하게 되는 경우
            cnt += tmp[j];
            student++;
        }

        ans = max(ans, student);
    }

    cout << ans;

    return 0;
}
/**
    해설은 원래 배열을 복사해서 사용함.
    나의 경우, 원래 배열의 값을 바꾸고 다시 원상복귀시켰다.
    + 비용의 경우, 나는 복사된 값을 사용했는데, 해설의 경우 cnt라는 변수를 통해서 현재까지 쓴 돈을 체크함
    - 로직은 동일, 구현 변수 활용이 조금 달랐다.
*/