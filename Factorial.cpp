#include <iostream>
#include <vector>

using namespace std;
int factorial(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = i * dp[i - 1];
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "\nThe " << n << "th factorial is " << factorial(n) << endl;

    return 0;
}
