#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int> waterList) {
    int left = 0, right = waterList.size() - 1;
    int maxArea = 0;

    while (left < right) {
        // Calculate the current area between left and right pointers
        int height = min(waterList[left], waterList[right]);
        int width = right - left;
        int currentArea = height * width;

        // Update the maximum area found so far
        maxArea = max(maxArea, currentArea);

        // Move the pointer with the smaller height
        if (waterList[left] < waterList[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxArea;
}

int main() {
    int numberSize, inputVector;
    vector<int> waterList;

    // Input the size of the vector
    cin >> numberSize;

    // Fill the vector with input values
    for (int i = 0; i < numberSize; i++) {
        cin >> inputVector;
        waterList.push_back(inputVector);
    }

    // Call the maxArea function and print the result
    cout << maxArea(waterList) << endl;

    return 0;
}
