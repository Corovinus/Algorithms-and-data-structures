	#include <iostream>
	#include <algorithm>
	#include <vector>
	#include <fstream>
	using namespace std;
	int main()
	{
		ifstream in("input.txt");
		ofstream out("output.txt");
		int n;
		cin >> n;
		vector <int> elements(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> elements[i];
		}
		for (int i = 1; i <= n / 2; i++) {
			if (i * 2 <= n) {
				if (elements[i * 2] < elements[i]) {
					out << "No";
					return 0;
				}
			}
			if (i * 2 + 1 <= n) {
				if (elements[i * 2 + 1] < elements[i]) {
					out << "No";
					return 0;
				}
			}
		}
		out << "Yes";
		return 0;
	}
