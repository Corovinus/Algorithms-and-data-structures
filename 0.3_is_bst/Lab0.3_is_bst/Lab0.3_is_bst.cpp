#include<iostream>
#include<vector>
#include<fstream>
#include<limits>
using namespace std;

struct TreeVertex {
    int Key;
    int Parent;
    char Direction;
};

int main() {
    ifstream in("bst.in");
    ofstream out("bst.out");

    int n;
    in >> n;

    if (n == 0 or n == 1) {
        out << "YES";
        return 0;
    }

    vector<TreeVertex> tree(n);
    in >> tree[0].Key;
    tree[0].Parent = -1;

    for (int i = 1; i < n; ++i) {
        in >> tree[i].Key >> tree[i].Parent >> tree[i].Direction;
        tree[i].Parent--;
    }

    vector<long long> minValue(n, LLONG_MIN);
    vector<long long> maxValue(n, LLONG_MAX);

    for (int i = 1; i < n; ++i) {
        int parent = tree[i].Parent;
        if (tree[i].Direction == 'L') {
            if (tree[i].Key >= tree[parent].Key) {
                out << "NO";
                return 0;
            }
            maxValue[i] = tree[parent].Key;
            minValue[i] = minValue[parent];
        }
        else if (tree[i].Direction == 'R') {
            if (tree[i].Key < tree[parent].Key) {
                out << "NO";
                return 0;
            }
            minValue[i] = tree[parent].Key;
            maxValue[i] = maxValue[parent];
        }

        if (tree[i].Key < minValue[i] || tree[i].Key >= maxValue[i]) {
            out << "NO";
            return 0;
        }
    }

    out << "YES";
    return 0;
}