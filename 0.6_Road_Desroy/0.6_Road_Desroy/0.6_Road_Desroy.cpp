#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Union {
public:
    vector<int> parent, rank;
    int components;

    Union(int n) : components(n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            }
            else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            }
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            components--;
        }
    }
};

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, m, q;
    in >> n >> m >> q;

    vector<pair<int, int>> edges(m + 1);
    vector<int> earthquakes(q);
    vector<bool> destroyed(m + 1, false);

    for (int i = 1; i <= m; ++i) {
        in >> edges[i].first >> edges[i].second;
    }

    for (int i = 0; i < q; ++i) {
        in >> earthquakes[i];
        destroyed[earthquakes[i]] = true;
    }

    Union uf(n);

    for (int i = 1; i <= m; ++i) {
        if (!destroyed[i]) {
            uf.unite(edges[i].first, edges[i].second);
        }
    }

    vector<bool> result(q);

    for (int i = q - 1; i >= 0; --i) {
        int edgeIndex = earthquakes[i];
        int u = edges[edgeIndex].first;
        int v = edges[edgeIndex].second;

        result[i] = (uf.components == 1);
        uf.unite(u, v);
    }

    for (bool res : result) {
        out << res;
    }
    out << endl;

    return 0;
}
