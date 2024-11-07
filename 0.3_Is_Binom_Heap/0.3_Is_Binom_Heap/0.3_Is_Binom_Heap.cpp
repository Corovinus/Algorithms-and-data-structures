#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	long long n;
	in >> n;
	long long count = 0;
	while (n != 0) {
		if (n % 2 == 1) {
			out << count << "\n";
		}
		n /= 2;
		count++;
	}
	return 0;
}
