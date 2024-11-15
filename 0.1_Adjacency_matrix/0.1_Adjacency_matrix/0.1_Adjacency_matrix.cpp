#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n,m;
	in >> n >> m;
	vector <vector <int>> a(n, vector <int>(n, 0));
	for (int i = 0; i < m; i++) {
		int x, y;
		in >> x >> y;
		a[x - 1][y - 1] = 1;
		a[y - 1][x - 1] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			out << a[i][j] << " ";
		}
		out << endl;
	}
	return 0;
}