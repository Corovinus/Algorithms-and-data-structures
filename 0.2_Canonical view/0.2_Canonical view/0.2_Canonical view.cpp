#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n;
	in >> n;
	
	if (n == 1) {
		out << 0 << endl;
		return 0;
	}

	vector <int> P(n,0);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		in >> x >> y;
		P[y - 1] = x; 
	}
	for (int i = 0; i < n; i++)
	{
		out << P[i] << " ";
	}
	return 0;
}