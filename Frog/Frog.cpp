#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int temp;
	cin >> n;



	int* fly = new int[n];
	int* jump = new int[n + 1];
	for (int i = 0; i < n; i++) {
		cin >> fly[i];
	}
	if (n == 1) {
		cout << fly[0] << endl << 1;
		return 0;
	}
	if (n == 2) {
		cout << -1;
		return 0;
	}
	jump[0] = fly[n - 1];
	jump[1] = -1;
	jump[2] = fly[n - 1] + fly[n - 3];

	for (int i = 3; i < n; i++)
		jump[i] = max(jump[i - 3], jump[i - 2]) + fly[n - i - 1];

	cout << jump[n - 1] << endl;

	int distance;
	for (int i = 1; i <= n; i += distance) {
		cout << i << " ";	
		if (i == n)
			break;
		else if (n - i == 2) {
			cout << n;
			break;
		}
		if (jump[n - i - 2] >= jump[n - i - 3])
			distance = 2;
		else
			distance = 3;
	}
}