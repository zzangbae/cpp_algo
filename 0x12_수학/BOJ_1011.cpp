#include<iostream>

using namespace std;

/**
 * dp문제네. 딱 보자마자 점화식
 * x지점에서 y지점을 향해 최소한의 작동 횟수로 이동하고자 함
 * y지점에 도착하기 바로 직전의 이동거리는 반드시 1광년
*/
// 최소한의 공간이동 장치 작동횟수
// 1 - 1 1 - 1 2 1 ... 파스칼 삼각형 꼴

int T;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    cin >> T;
    int x, y;
    while(T--) {
        cin >> x >> y;
        // 차이를 구하자
        int z = y - x;
        long long i = 1;    // int면 틀림
        int answer;
        while(true) {
            long long isqr = i * i;
            if(isqr >= z) {
                if(z > i * i - i) answer = i * 2 - 1;
                else answer = (i - 1) * 2;
                break;
            }
            i++;
        }
        cout << answer << "\n";
    }
    return 0;
}