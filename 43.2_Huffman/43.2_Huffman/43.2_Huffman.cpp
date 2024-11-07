#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

long long calculate(const vector<int>& chastota) {
    int n = chastota.size();
    vector<long long> combinedChastota(n - 1); 

    int originalIndex = 0, combinedIndex = 0; 
    long long totalLength = 0;

    for (int i = 0; i < n - 1; ++i) {
        long long left = (originalIndex < n && (combinedIndex >= i || chastota[originalIndex] <= combinedChastota[combinedIndex])) ?
            chastota[originalIndex++] : combinedChastota[combinedIndex++];
        long long right = (originalIndex < n && (combinedIndex >= i || chastota[originalIndex] <= combinedChastota[combinedIndex])) ?
            chastota[originalIndex++] : combinedChastota[combinedIndex++];

        long long merged = left + right;
        totalLength += merged;

        combinedChastota[i] = merged;
    }

    return totalLength;
}

int main() {
    ifstream in("huffman.in");
    ofstream out("huffman.out");

    int n;
    in >> n;

    vector<int> chastota(n);
    for (int i = 0; i < n; ++i) {
        in >> chastota[i];
    }

    long long result = calculate(chastota);
    out << result << endl;

    return 0;
}
