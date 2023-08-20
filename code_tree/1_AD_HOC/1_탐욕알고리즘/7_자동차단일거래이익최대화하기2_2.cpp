#include <iostream>

#define MAX_NUM 100000

using namespace std;

int main() {
    int n;
    int price[MAX_NUM];

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> price[i];
    
    int max_profit = 0;
    int min_price = price[0];
    for(int i = 0; i < n; i++) {
        int profit = price[i] - min_price;
        if(profit > max_profit)
            max_profit = profit;
        
        if(min_price > price[i])
            min_price = price[i];
    }
    cout << max_profit;
    return 0;
}