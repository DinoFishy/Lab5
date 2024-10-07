// Header Files
#include <chrono>
#include <iostream>
#include <thread>
#include "StringData.h"
using namespace std::chrono;
using namespace std;


// Linear Search
int linearSearch(vector<string>& stringData, string element) {
    for (int i = 0; i < stringData.size(); i++) {
        if (stringData[i] == element) {
            return i;
        }
    }
    // If not found
    return -1;
}
int binarySearch(vector<string>& stringData, string element) {
    int low = 0;
    int high = stringData.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (stringData[mid] == element) {
            return mid;
        }else if(stringData[mid] < element) {
            low = mid + 1;
        }else {
            high = mid - 1;
        }
    }
    // If not found
    return -1;
}

int main() {
    vector<string>dataset = getStringData();
    vector<string>elementSearch = vector<string>{"not_here", "mzzzz", "aaaaa"};
    // Linear Search
    for (int i = 0; i < elementSearch.size(); i++) {
        auto start = high_resolution_clock::now();
        int index = linearSearch(dataset, elementSearch[i]);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Linear search for " << elementSearch[i] << ". Time took " << (static_cast<float>(duration.count()))/1000000 << " seconds." << endl;
    }

    // Binary Search
    for (int i = 0; i < elementSearch.size(); i++) {
        auto start = high_resolution_clock::now();
        int index = binarySearch(dataset, elementSearch[i]);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Binary search for " << elementSearch[i] << ". Time took " << (static_cast<float>(duration.count()))/1000000 << " seconds." << endl;
    }
    return 0;
}