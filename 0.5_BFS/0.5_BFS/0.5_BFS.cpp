#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;
    in >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            in >> graph[i][j];
        }
    }

    vector<int> marks(n, 0);
    int currentLabel = 1;

    queue<int> q;

    for (int start = 0; start < n; start++) {
        if (marks[start] == 0) {
            q.push(start);
            marks[start] = currentLabel++;
        }

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int i = 0; i < n; ++i) {
                if (graph[v][i] == 1 and marks[i] == 0) {
                    marks[i] = currentLabel++;
                    q.push(i);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        out << marks[i] << " ";
    }

    return 0;
}
