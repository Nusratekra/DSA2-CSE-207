#include <iostream>
using namespace std;

int knapsack_recursive(const int weights[], const int values[], int capacity, int item) {
    if (item == 0 || capacity == 0)
        return 0;
    if (weights[item-1] > capacity)
        return knapsack_recursive(weights, values, capacity, item-1);
    return max(
        values[item-1] + knapsack_recursive(weights, values, capacity - weights[item-1], item-1),
        knapsack_recursive(weights, values, capacity, item-1)
    );
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
    cout << "Maximum value (recursive): " << knapsack_recursive(weights, values, capacity, item) << endl;
    return 0;
}
