#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Tree {
public:
    Tree(long long n) : size(n) {
        tree.assign(n + 1, 0);
    }

    void add(long long index, long long value) {
        index++;
        for (;index <= size; index += index & -index) {
			tree[index] += value;
		}
    }

    long long prefix_sum(long long index) {
        index++;
        long long result = 0;
        for (; index > 0; index -= index & -index) {
            result += tree[index];
        }
        return result;
    }

    long long range_sum(long long left, long long right) {
        if (left == 0) {
            return prefix_sum(right - 1);
        }
        if (left == right) {
			return prefix_sum(left - 1);
		}
        return prefix_sum(right - 1) - prefix_sum(left - 1);
    }


private:
    long long size;
    vector<long long> tree;
};

long long main() {
    long long n;
    cin >> n;

    vector<long long> array(n);
    for (long long i = 0; i < n; i++) {
        cin >> array[i];
    }

    Tree tree(n);
    for (long long i = 0; i < n; i++) {
        tree.add(i, array[i]);
    }

    long long q;
    cin >> q;
    vector<long long> results;

    for (long long j = 0; j < q; j++) {
        string function;
        cin >> function;

        if (function == "FindSum") {
            long long l, r;
            cin >> l >> r;
            results.push_back(tree.range_sum(l, r));
        }
        else if (function == "Add") {
            long long i, x;
            cin >> i >> x;
            tree.add(i, x);
        }
    }

    for (long long result : results) {
        cout << result << "\n";
    }

    return 0;
}
