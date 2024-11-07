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

    bool unite(int x, int y) {
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
            return true;
        }
        return false;
    }
};

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, q;
    in >> n >> q;

    Union uf(n);

    for (int i = 0; i < q; ++i) {
        int u, v;
        in >> u >> v;
        uf.unite(u, v);
        out << uf.components << endl;
    }

    return 0;
}
