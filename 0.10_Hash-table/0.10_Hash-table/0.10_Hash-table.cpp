#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

class HashTable {
	int cellSize;
	int c;
	int i = 0;
	vector<int> cell;
public:
	HashTable(int size, int c) : cell(size,-1){
		cellSize = size;
		this->c = c;
	}

	int hash(int key) {
		return ((key % cellSize) + i * c) % cellSize;
	}
	int add(int key, int iteration) {
		if (iteration == 0) {
			i = 0;
		}
		int index = hash(key);
		if (cell[index] == -1) {
			cell[index] = key;
			return index;
		}
		if (cell[index] == key) {
			return index;
		}
		else {
			i++;
			return add(key, iteration + 1);
		}
	}
	void coutCells() {
		for (int i = 0; i < cellSize; i++) {
			out << cell[i] << " ";
		}	
	}
};
int main()
{
	int m, c, n;
	in >> m >> c >> n;
	HashTable hashTable(m, c);
	for (int i = 0; i < n; i++) {
		int key;
		in >> key;
		hashTable.add(key,0);
	}
	hashTable.coutCells();
	return 0;
}