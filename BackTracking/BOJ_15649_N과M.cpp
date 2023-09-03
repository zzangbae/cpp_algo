#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> answer;
bool isused[10];

void Print() {
    for(int i = 0; i < answer.size() - 1; i++)
        cout << answer[i] << " ";
    cout << answer[answer.size() - 1];
    cout << "\n";
    return;
}

void Choose(int curr_num) {
    if(curr_num == m + 1) {
        Print();
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!isused[i]) {
            answer.push_back(i);
            isused[i] = 1;
            Choose(curr_num + 1);
            answer.pop_back();
            isused[i] = 0;
        }
    }
    return;
}

int main() {
    cin >> n >> m;
    // 1부터 N까지 자연수 중에서 '중복없이' M개 고른 수열
    Choose(1);
    return 0;
}