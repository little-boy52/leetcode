#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; ++i)
        {
            dp[0][i] = i;
        }
        for (int i = 1; i <= m; ++i)
        {
            dp[i][0] = i;
        }
        dp[0][0] = 0;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (word1[i - 1] != word2[j - 1])
                    dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
                else
                    dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1] - 1)) + 1;

            }

        }
        return dp[m][n];

    }
};

int main(void)
{

    return 0;
}
