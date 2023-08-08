// 7:36~7:43(7분/15분)
#include <iostream>
#include <algorithm>
#define MAX_N 1000
using namespace std;

int n, b;  // 1~1000 학생수, 예산 1~1000
int p[MAX_N];

int main() {
    cin >> n >> b;
    for(int i = 0; i < n; i++)
        cin >> p[i];
    
    // 선물 가능한 학생의 최대 명수를 구하자
    // 1. 먼저 sort를 하자
    sort(p, p + n);
    int max_student = 0;
    // 2. i번째를 반값으로 했을 때 가장 많이 줄 수 있는 학생 수
    for(int i = 0; i < n; i++) {
        int tmp_student = 0;
        int tmp_b = b;
        p[i] /= 2;  // 반값 시전
        for(int j = 0; j < n; j++) {
            if(tmp_b < p[j]) break; // 더이상 선물을 사주지 못한다면 break
            tmp_b -= p[j];
            tmp_student++;
        }
        max_student = max(max_student, tmp_student);
        p[i] *= 2;  // 원래 값으로 되돌리기
    }

    cout << max_student;
    return 0;
}