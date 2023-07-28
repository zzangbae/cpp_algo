#include <iostream>
#include <climits>

using namespace std;
// 이렇게 풀면, 문제를 그대로 푸는 것
// 즉, 앞에서부터 1/0을 바꿔가면서 최대의 십진수를 찾는 방향이다.

int main() {
    //변수 선언 및 입력
    string binary;
    cin >> binary;

    // 각 i번째 자릿수를 바꾸었을 때의 십진수 값을 구해준다.
    int ans = INT_MIN;
    for(int i = 0; i < (int) binary.size(); i++) {
        // i번째 자릿수를 바꾸기
        binary[i] = '0' + '1' - binary[i];
        // cout << binary[i];
        // 십진수로 변환
        int num = 0;
        for(int j = 0; j < (int) binary.size(); j++)
            num = num * 2 + (binary[j] - '0');  // 쉬프트연산자를 떠올리면 이해할 수 있다.
            // 추가적으로 binary[j] = '1' 혹은 '0'이다.
            // 자동으로 int로 변환되게 되는데, '1'은 49로 변환된다. 따라서 '0'을 빼줘서 48을 빼준 int 1로서
            // 활용할 수 있다.

        // 가능한 십진수 값 중 최댓값을 구하기
        ans = max(ans, num);

        // i번째 자릿수를 원래대로 되돌리기
        binary[i] = '0' + '1' - binary[i];
    }

    cout << ans;

    return 0;
}