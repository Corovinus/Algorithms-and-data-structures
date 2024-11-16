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

    vector<vector<int>> array(n, vector<int>(n, 0));
    vector <int> ans(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int temp;
            in >> temp;
            if (temp == 1) {
                ans[j] = i + 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        out << ans[i] << " ";
    }
    return 0;
}