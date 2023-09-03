#include <iostream>
#include <vector>

using namespace std;

int n = 3;
vector<int> answer;

void Print() {
    for(int i = 0; i < answer.size(); i++)
        cout << answer[i];
    cout << "\n";
    return;
}

void Choose(int curr_num) {
    if(curr_num == n + 1) {
        Print();
        return;
    }
    answer.push_back(0);
    Choose(curr_num + 1);
    answer.pop_back();

    answer.push_back(1);
    Choose(curr_num + 1);
    answer.pop_back();

    return;
}

int main() {
    Choose(1);
    return 0;
}