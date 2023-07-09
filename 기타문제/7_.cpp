#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * [30, 30, 60, 90, 60, 15, 15, 60]이란 vector<int>가 주어졌을 때, 연속된 원소를 선택하지 않으면서 합이 가장 큰 부분집합을 선택하는 방법을 알려줘
*/

int findMaxSubsetSum(const std::vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return nums[0];
    }

    std::vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[n - 1];
}


int solution(vector<int> schedules) {
    int answer = 0;
    
    answer = findMaxSubsetSum(schedules);

    return answer;
}