#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	string x;
	in >> x;
	int n = x.size();
	string y = x;
	reverse(y.begin(), y.end());
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
	out << count << endl;
	string ans;
	int i = n, j = n;
	int p = count % 2 == 0 ? count / 2 : count / 2 + 1;

	while (i > 0 && j > 0) {
		if (x[i - 1] == y[j - 1]) {
			ans += x[i-1];
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
	out << ans;
}
