#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool check(string str, int N) {
    for(int i = 1; i <= N; ++i) {
        if(str.find(to_string(i)) == string::npos) {
            return false;
        } 
    }
    return true;
}

int findMaxValue(vector<int> nums) {
    if (nums.empty()) {
        return -1;
    }

    int maxVal = nums[0];   // 초기값은 첫 번째요소
    for(int i = 1; i < nums.size(); ++i) {
        if(nums[i] > maxVal) {
            maxVal = nums[i];
        }
    }
    return maxVal;
}

int solution(string s, int N) {
    vector<int> arr;
    int answer = 0;
    // 숫자로만 이루어진 문자열 s
    // 1부터 N까지 숫자를 하나씩 사용하여 만든 N자리 문자
    for(int i = 0; i + N <= s.length(); i++) {
        string str = s.substr(i, N);
        if(check(str, N)) {
            arr.push_back(stoi(str));
        }
    } 
    
    answer = findMaxValue(arr);

    return answer;
}