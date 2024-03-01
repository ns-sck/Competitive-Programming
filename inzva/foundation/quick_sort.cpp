#include <iostream>
#include <vector>
using namespace std;

// Function to partition the array into two halves and return the index of the pivot element
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1; // Index of the smaller element

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            // If the current element is smaller than the pivot, swap arr[i+1] and arr[j]
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    // Swap arr[i+1] and arr[high] to place the pivot in its correct position
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to implement the Quick Sort algorithm
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Find the partition index such that elements on the left are smaller and on the right are larger
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the subarrays on the left and right of the pivot
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    vector<int> arr = {5, 6, 8, 4, 3, 7, 9, 2, 1, 0};
    int n = arr.size();

    cout << "Original array: ";
    for (auto &element : arr) {
        cout << element << ' ';
    }

    quickSort(arr, 0, n - 1);

    cout << "\nSorted array: ";
    for (auto &element : arr) {
        cout << element << ' ';
    }

    return 0;
}
