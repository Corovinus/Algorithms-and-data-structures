#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> y[i];
	}
	vector <vector<int>> dp(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (x[i - 1] == y[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	int count = dp[n][n], temp = count;
	cout << count << endl;
	vector<int> indicesX, indicesY;
	int i = n, j = n;

	while (i > 0 && j > 0) {
		if (x[i - 1] == y[j - 1]) {
			indicesX.push_back(i - 2);
			indicesY.push_back(j - 2);
			i--;
			j--;
		}
		else if (dp[i - 1][j] >= dp[i][j - 1]) {
			i--;
		}
		else {
			j--;
		}
	}
	reverse(indicesX.begin(), indicesX.end());
	reverse(indicesY.begin(), indicesY.end());
	for (int idx : indicesX) {
		cout << idx + 1 << " ";
	}
	cout << endl;
	for (int idx : indicesY) {
		cout << idx + 1 << " "; 
	}
}
