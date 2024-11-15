#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, m;
    in >> n >> m;

    vector<vector<int>> List(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        in >> x >> y;
        List[x - 1].push_back(y); 
        List[y - 1].push_back(x); 
    }

    for (int i = 0; i < n; ++i) {
        out << List[i].size();
        for (int x : List[i]) {
            out << " " << x;  
        }
        out << endl;
    }
}