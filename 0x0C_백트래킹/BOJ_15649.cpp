#include<iostream>
#include<vector>
#include<algorithm> // find()함수를 포함한다.
// 10:00 ~ 10:35
using namespace std;

/**
 * N, M이 주졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램
 * 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
 * 1 <= M <= N <= 8
*/
int N, M;
// permutation : M개가 되면 출력하기
// v는 현재 만들어진 수열, k는 추가되는 수
void permutation(vector<int> v, int k) {
    v.push_back(k);
    // 길이가 M인 수열이 완성된 경우
    if(v.size() == M) {
        for(int w : v) {
            cout << w << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 1; i <= N; i++) {
        // v에 i가 없다면 수열돌리기
        if(find(v.begin(), v.end(), i) == v.end()) {
            permutation(v, i);
        }
    }
}
int main() {
    cin >> N >> M;
    vector<int> v;
    for(int i = 1; i <= N; i++) {
        permutation(v, i);
    }
    return 0;
}