#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int LCS(const string &x, const string &y, string &lcsString) {
    int m = x.length();
    int n = y.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int i = m, j = n;
    lcsString = "";
    while (i > 0 && j > 0) {
        if (x[i - 1] == y[j - 1]) {
            lcsString += x[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(lcsString.begin(), lcsString.end());

    return dp[m][n];
}

int main() {
    string x, y, lcsString;

    cout << "Enter the first string: ";
    cin >> x;
    cout << "Enter the second string: ";
    cin >> y;

    int lcsLength = LCS(x, y, lcsString);
    cout << "Length of LCS is " << lcsLength << endl;
    cout << "LCS string is \"" << lcsString << "\"" << endl;

    return 0;
}
