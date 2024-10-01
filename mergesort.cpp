#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int>& arrayList, int number) {
    for (int i = 0; i < number; i++) {
        cout << arrayList[i] << " ";
    }
    cout << endl;
}

void merge(vector<int>& arrayList, int left, int mid, int right) {
    int leftArrayNumber = mid - left + 1;
    int rightArrayNumber = right - mid;

    // Create temporary arrays
    vector<int> leftArray(leftArrayNumber), rightArray(rightArrayNumber);

    // Copy data to temporary arrays
    for (int i = 0; i < leftArrayNumber; i++) {
        leftArray[i] = arrayList[left + i];
    }
    for (int i = 0; i < rightArrayNumber; i++) {
        rightArray[i] = arrayList[mid + 1 + i];
    }

    // Merge the temporary arrays back into arrayList
    int i = 0, j = 0, k = left;
    while (i < leftArrayNumber && j < rightArrayNumber) {
        if (leftArray[i] <= rightArray[j]) {
            arrayList[k] = leftArray[i];
            i++;
        } else {
            arrayList[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArray, if any
    while (i < leftArrayNumber) {
        arrayList[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArray, if any
    while (j < rightArrayNumber) {
        arrayList[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergesort(vector<int>& arrayList, int left, int right) {
    if (left >= right) {
        return;  // Fixed base case condition
    }
    int mid = left + (right - left) / 2;

    // Recursively sort first and second halves
    mergesort(arrayList, left, mid);
    mergesort(arrayList, mid + 1, right);

    // Merge the sorted halves
    merge(arrayList, left, mid, right);
}

int main() {
    int number, input;
    vector<int> arrayList;

    cout << "Enter the number of elements: ";
    cin >> number;

    cout << "Enter the elements: ";
    for (int i = 0; i < number; i++) {
        cin >> input;
        arrayList.push_back(input);
    }


    mergesort(arrayList, 0, number - 1);


    printArray(arrayList, number);

    return 0;
}
