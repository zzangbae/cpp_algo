// 11:22~12:20(1시간/25분) 엄청 오바
#include <iostream>
#include <algorithm>
#include <tuple>
#define MAX_N 100000
using namespace std;

int n, m;   // n:1~10만 , m:1~10억
tuple<double, int, int> t[MAX_N];

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;

        double c = (double)v/ (double)w;
        t[i] = make_tuple(c, v, w); 
    }

    sort(t, t + n);

    double result = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(m == 0) break;   // 무게가 더이상 남지 않았다면 끝
        // 남은 무게가 보석의 무게보다 크거나 같다면 보석 다담기
        if(m >= get<2>(t[i])) {
            result += get<1>(t[i]);
            m -= get<2>(t[i]);
        }
        // 남은 무게가 보석의 무게보다 작다면
        else {
            result += get<0>(t[i]) * m;
            m = 0;
            break;
        }
    }
    cout.setf(ios::fixed);
    cout.precision(3);
    cout << result;

    return 0;
}

// 0/1인 경우 문제찾아서 풀기