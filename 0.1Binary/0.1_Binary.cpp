#include <iostream>
#include <vector>

using namespace std;

int minIndex(const vector<int>& arr, int x) {
    int left = 0, right = arr.size();

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= x) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}

int maxIndex(const vector<int>& arr, int x) {
    int left = 0, right = arr.size();

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] > x) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int k;
    cin >> k;
    vector<int> cmp(k);
    for (int i = 0; i < k; ++i) {
        cin >> cmp[i];
    }

    for (int i = 0; i < k; ++i) {
        int x = cmp[i];

        int l = minIndex(arr, x);
        int r = maxIndex(arr, x);
        int b = 0;
        if (l < n && arr[l] == x) {
            b = 1;
        }

        cout << b << " " << l << " " << r << endl;
    }

    return 0;
}
