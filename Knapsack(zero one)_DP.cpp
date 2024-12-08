#include <iostream>
using namespace std;

int knapsack_dp(const int weights[], const int values[], int capacity, int item) {
    int dp[item + 1][capacity + 1];

    for (int i = 0; i <= item; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[item][capacity];
}

int main() {
    int item, capacity;
    cout << "Enter the number of items: ";
    cin >> item;
    int weights[item], values[item];
    cout << "Enter the weights of the items:\n";
    for (int i = 0; i < item; i++) {
        cin >> weights[i];
    }
    cout << "Enter the values of the items:\n";
    for (int i = 0; i < item; i++) {
        cin >> values[i];
    }
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    cout << "Maximum value (DP): " << knapsack_dp(weights, values, capacity, item) << endl;

    return 0;
}
