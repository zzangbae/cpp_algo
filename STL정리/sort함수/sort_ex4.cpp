#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<std::vector<int>> arr = {{1, 2}, {2, 3}, {2, 2}, {3, 2}, {4, 5}};

    std::sort(arr.begin(), arr.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        if(a[0] > b[0])
            return true;
        else if (a[0] < b[0])
            return false;
        return a[1] < b[1];
    });

    for(int i = 0; i < arr.size(); i++) {
        std::cout << "[" << arr[i][0] << ", " << arr[i][1] << "] "; 
    }
}