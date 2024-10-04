// Header Files
#include <chrono>
#include <iostream>
#include <thread>
#include "StringData.h"
using namespace std::chrono;
using namespace std;


// Linear Search
int linearSearch(vector<string> stringData, string element) {
    for (int i = 0; i < stringData.size(); i++) {
        if (stringData[i] == element) {
            return i;
        }
    }
    // If not found
    return -1;
}
int binarySearch(vector<string> stringData, string element) {
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

    auto start = high_resolution_clock::now();
    this_thread::sleep_for(chrono::seconds(6));
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
    cout << duration.count() << endl;



    return 0;
}