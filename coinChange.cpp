#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int findMinCoins(vector<int>& coins, int value) {
    int count = 0;
    vector<int> ans;
    sort(coins.rbegin(), coins.rend());

    for (int i = 0; i < coins.size(); i++) {
        while (value >= coins[i]) {
            value -= coins[i];
            ans.push_back(coins[i]);
            count++;
        }
        if (value == 0) {
            break;
        }
    }

    if (value > 0) {
        cout << "It is not possible to make the target value with the given coins.\n";
        return -1;
    }

    cout << "Total Coins Needed = " << count << endl;
    cout << "Coins used: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return count;
}

int main() {
    int size, value;
    cout << "Enter the number of coin: ";
    cin >> size;

    vector<int> coins(size);
    cout << "Enter the coin: ";
    for (int i = 0; i < size; i++) {
        cin >> coins[i];
    }
    cout << "Enter the target value: ";
    cin >> value;
    int minCount = findMinCoins(coins, value);

    return 0;
}

