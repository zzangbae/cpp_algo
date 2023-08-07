// 12:51~13:09(18분/37분) - on time
#include <iostream>
#include <vector>
#define MAX_N 100

using namespace std;

int n;  // 1~100
int arr[MAX_N]; // 겹쳐짐 여부 표시
vector<pair<int, int>> v;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x1, x2;
        cin >> x1 >> x2;
        v.push_back({x1, x2});
    }

    // x1기준으로 sort를 한다? -> 비교하는 갯수가 줄어들지만 sort도 시간비용이 든다. -> 나는 안함
    // 생각해보면 sort하는게 더 나을것같다. -> 아니!! 안해도 충분!
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            // x1은 작은데 x2는 큰경우 -> 겹친다.
            if(v[i].first < v[j].first && v[i].second > v[j].second) {
                arr[i] = 1;
                arr[j] = 1;
                continue;
            } 
            // x1은 큰데 x2는 작은 경우 -> 겹친다.
            else if(v[i].first > v[j].first && v[i].second < v[j].second) {
                arr[i] = 1;
                arr[j] = 1;
                continue;
            }
        }
    }

    int result = 0; // 겹치지 않은 선분만 세기
    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) result++;
    }
    cout << result;
    return 0;
}

/**
    처음에 arr[j]이면 j를 스킵하게 했다.
    그러면 원래 해당 j와 겹칠 수 있었던 선분이 안겹친 것으로 판단될 수 있다
*/

/**
 * 해설풀이가 더 나은점
 * 일차원배열로 x1, x2를 나타내서 훨씬 코드가 간결하다.
 * -> vector의 경우 pair과 함께 쓰면 너무 길어짐
 * 또한, 조합을 겹치는 여부 판단만 하면 되기 때문에
 * 범위가 0~n -> 0~n으로 2중포문하면된다.(i == j만 빼면됨)
 * 나처럼 굳이 arr[] 배열을 둘 필요가 없었다.
*/