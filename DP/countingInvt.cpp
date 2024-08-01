#include <iostream>
#include <vector>

using namespace std;

long long merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays to store the left and right subarrays
    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    // Copy data to temporary arrays leftArr[] and rightArr[]
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    long long inversions = 0;
    int i = 0, j = 0, k = left;

    // Merge the two subarrays back into the original array arr[]
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
            // Count inversions
            inversions += (n1 - i);
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[], if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    return inversions;
}

long long mergeSort(vector<int>& arr, int left, int right) {
    long long inversions = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Divide the array into two halves and count inversions
        inversions += mergeSort(arr, left, mid);
        inversions += mergeSort(arr, mid + 1, right);

        // Merge the two sorted halves and count split inversions
        inversions += merge(arr, left, mid, right);
    }
    return inversions;
}

long long countInversions(vector<int>& arr) {
    return mergeSort(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {1, 20, 6, 4, 5};

    long long inversions = countInversions(arr);

    cout << "Number of inversions: " << inversions << endl;

    return 0;
}
