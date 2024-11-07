#include <iostream>
#include <set>
#include <fstream>
#include <vector>
#include <limits>
using namespace std;
int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n;
	cin >> n;
	vector <int> array(n);
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}
	set <int> sorted_array;
	for (int i = 0; i < n; i++) {
		auto it = sorted_array.lower_bound(array[i]);
		if (it != sorted_array.end()) {
			sorted_array.erase(it);
		}
		sorted_array.insert(array[i]);
	}
	cout << sorted_array.size();
}
