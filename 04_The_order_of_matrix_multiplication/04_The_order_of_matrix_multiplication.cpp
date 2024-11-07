#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <climits>

using namespace std;
int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n;
    in >> n;
    vector <int> matrix(n+1);
    vector <vector<int>> dp (n + 1,vector<int>(n + 1));
    int temp;
    for (int i = 0; i < n; i++) {
        in >> matrix[i] >> temp;
    }
    matrix[n] = temp;
    for (int length = 2; length < n + 1; length++) {
        for (int i = 1; i < n - length + 2; i++) {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int q = dp[i][k] + dp[k + 1][j] + matrix[i - 1] * matrix[k] * matrix[j];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                }
            }
        }
    }
    out << dp[1][n];
}
