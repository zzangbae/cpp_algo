// 12:03~12:26(23분/17분) - over time: 하다코딩이 이유인가...?
#include <iostream>
#include <vector>
using namespace std;

int n;  // 3~100
vector<pair<int, int>> v;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;   // -1000~1000
        cin >> x >> y;
        v.push_back({x, y});
    }

    // 한 면은 x축에 평행, 다른 한면은 y축에 평행
    // 그러한 삼각형 중 최대 넓이에 2를 곱한 값을 구하라
    // 점 세개를 고른다 -> 조건(평행)에 맞는지 파악한다 -> 맞으면 최대 넓이를 찾아 2를 곱한다.(나누기 안해줘도 된다는뜻)
    int max_size = 0;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            for(int k = j + 1; k < n; k++) {
                int tmp_size = 0;
                // 조건 보기
                pair<int, int> p1 = v[i];
                pair<int, int> p2 = v[j];
                pair<int, int> p3 = v[k];
                // 짧은 두 변 찾기
                int x1 = p1.first;
                int y1 = p1.second;
                int x2 = p2.first;
                int y2 = p2.second;
                int x3 = p3.first;
                int y3 = p3.second;
                // p1과 p2가 y축 평행
                if(x1 == x2) {
                    // p1과 p3가 x축 평행
                    if(y1 == y3) {
                        tmp_size = abs(x1 - x3) * abs(y1 - y2);
                    }
                    // p2와 p3가 x축 평행 
                    else if(y2 == y3) {
                        tmp_size = abs(x2 - x3) * abs(y1 - y2);
                    }
                }
                // p2와 p3가 y축 평행
                else if(x2 == x3) {
                    // p2와 p1이 x축 평행
                    if(y2 == y1) {
                        tmp_size = abs(x2 - x1) * abs(y2 - y3);
                    }
                    // p3와 p1이 x축 평행
                    else if(y3 == y1) {
                        tmp_size = abs(x3 - x1) * abs(y2 - y3);
                    }
                }
                // p3와 p1이 y축 평행
                else if(x3 == x1) {
                    // p3와 p2가 x축 평행
                    if(y3 == y2) {
                        tmp_size = abs(x3 - x2) * abs(y3 - y1);
                    }
                    // p1와 p2가 x축 평행
                    else if(y1 == y2) {
                        tmp_size = abs(x1 - x2) * abs(y3 - y1);
                    }
                }
                max_size = max(max_size, tmp_size);
                // ** 세 점이 한 직선 위에 있어도 너비가 0이 되므로 답에 영향없어서 안걸러줘도됨
            }
    
    cout << max_size;
    return 0;
}

/**
    - 해설이 경우, 신발끈 공식을 이용했다.
*/