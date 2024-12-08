#include <bits/stdc++.h>
using namespace std;

struct Item {
    int profit, weight;
    Item(int profit, int weight)
    {
        this->profit = profit;
        this->weight = weight;
    }
};
static bool cmp(Item a, Item b)
{
    double r1 = (double)a.profit / (double)a.weight;
    double r2 = (double)b.profit / (double)b.weight;
    return r1 > r2;
}
double fractionalKnapsack(int W, vector<Item>& arr, int N)
{
    sort(arr.begin(), arr.end(), cmp);

    double finalvalue = 0.0;
    for (int i = 0; i < N; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalvalue += arr[i].profit;
        }
        else {
            finalvalue += arr[i].profit * ((double)W / (double)arr[i].weight);
            break;
        }
    }

    return finalvalue;
}

int main()
{
    int W, N;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;
    cout << "Enter the number of items: ";
    cin >> N;
    vector<Item> arr;
    cout << "Enter the profit of each item:\n";
    for (int i = 0; i < N; i++) {
        int profit;
        cin >> profit;
        arr.push_back(Item(profit, 0));
    }

    cout << "Enter the weight of each item:\n";
    for (int i = 0; i < N; i++) {
        int weight;
        cin >> weight;
        arr[i].weight = weight;
    }
    double maxProfit = fractionalKnapsack(W, arr, N);
    cout << "Maximum profit that can be obtained: " << maxProfit << endl;

    return 0;
}



