#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

/**
 * 20437 - 문자열게임2
 * 1. 알벳 소문자로 이루어진 문자열 w
 * 2. 양의 정수 k
 * 3. 어떤 문자를 정확히 k개를 포함하는 가장 짧은 연속 문자열의 길이 구하기
 * 4. 어떤 문자를 정확하 k개 포함하고, 문자열의 첫 번째와 마지막 글자가 해당 문자로 같은 가장 긴 연속 문자열의 길이를 구한다.
 * 위와 같은 방식으로 T회 진행
*/

/**
 * 3번 4번 구한 연속 문자열의 길이 공백 두고 출력
 * 만족하는 연속 문자열 없다면 -1
*/

int t;  // T는 1부터 100
string w;   // 1 ~ 1만 길이 
int k;  // 1 ~ 1만
map<char, vector<int>> c_idx;

int main() {
    // 0. 입력값 넣기
    cin >> t;
    for(int tc = 0; tc < t; tc++) {
        cin >> w >> k;
        // 초기화
        for(int i = 97; i < 123; i++) {
            c_idx[i] = {};
        }
        // 1. 문자열을 순회하며 문자의 인덱스를 벡터에 넣어주기
        for(int i = 0; i < w.size(); i++) {
            c_idx[w[i]].push_back(i);
        }
        
        // 2. 만들어진 c_idx를 순회하면서 답을 구해보자
        int min_a = 987654321;
        int max_a = -1;
        // cout << "--------------------------\n";
        for(const auto& pair : c_idx) {
            char key = pair.first;
            vector<int> idxs = pair.second;
    
            // idxs의 사이즈가 k보다 크거나 같을 때에만 3번을 구할 수 있다.
            if(idxs.size() < k) continue;
            // cout << "key : " << key << " - ";
            // for(int i = 0; i < idxs.size(); i++) {
            //     cout << idxs[i] << " ";
            // }
            // cout << "\n";
            for(int i = 0; i + k - 1 < idxs.size(); i++) {
                min_a = min(min_a, idxs[i + k - 1] - idxs[i] + 1);
                max_a = max(max_a, idxs[i + k - 1] - idxs[i] + 1);
            }
        }
        if(min_a != 987654321) {
            cout << min_a << " " << max_a << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}