#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void LCS(string X, string Y)
{
    int m = X.length();
    int n = Y.length();

    int dp[100][100] = {0};

    
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    
    string result = "";

    int i = m;
    int j = n;

    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            result = X[i - 1] + result;
            i--;
            j--;
        }
        else if (dp[i - 1][j] >= dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

   
    cout << "\nLCS DP Table:\n";

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nLength of LCS: " << dp[m][n] << endl;
    cout << "Longest Common Subsequence: " << result << endl;
}

int main()
{
    string X, Y;

    cout << "Enter first string: ";
    cin >> X;

    cout << "Enter second string: ";
    cin >> Y;

    LCS(X, Y);

    return 0;
}
