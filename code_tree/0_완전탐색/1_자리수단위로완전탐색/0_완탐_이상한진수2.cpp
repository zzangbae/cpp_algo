#include <iostream>
#include <string>
// 9:35~10:03
using namespace std;

string str;

int main() {
    cin >> str;
    int s_len = str.size();
    // 맨 앞은 0이 아니다.
    // 앞에서부터 0인게 발견되면 1로 치환하고
    // 모든 숫자가 1인 경우도 생각해야한다.
    bool all_one = true;  // 모든 숫자가 1인 경우 true
    for(int i = 0; i < s_len; i++) {
        // 숫자가 하나라도 0인 경우 all_one를 false로 하고, 해당 하는 숫자를 1로 바꿔준다.
        if(str[i] == '0') {
            all_one = false;
            str[i] = '1';
            break;
        }
    }

    // 모든 숫자가 1인 경우 - 해당 숫자를 10진수로 바꾸고 -2해주기
    // 이유 : 모든 숫자가 1이면 1111 이런 꼴이다.
    // 1111 = 10000 - 1이다.(2진수)
    // 하지만 1110이 정답이므로 -2를 해줘야한다.
    if(all_one) {
        int result = 1;
        for(int i = 0; i < s_len; i++) {
            result *= 2;
        }
        result -= 2;
        cout << result;
        return 0;
    }

    // 하나라도 0이 있는 경우 - 앞서서 맨 앞의 0을 1로 바꿨다.
    int result = 0;
    for(int i = 0; i < s_len; i++) {
        int nn = 1; // 2진수를 10진수로 특정 자릿수를 변환한 것
        if(str[i] == '0') continue;
        // 1인 경우
        // i = 0일 때, 2**(s_len - 1) 즉, 2를 s_len - 1번만큼 곱해야함
        for(int j = 0; j < s_len - i - 1; j++) {
            nn *= 2;
        }
        result += nn;
    }
    cout << result;
    return 0;
}