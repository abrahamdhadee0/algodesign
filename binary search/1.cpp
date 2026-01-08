//loer bound
#include <bits/stdc++.h>
using namespace std;    
int main(){
    vector<int> arr = {1, 2, 4, 4, 5, 6, 8};
    int target = 4;
    int left = 0, right = arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    if (left < arr.size() && arr[left] == target)
        cout << "Lower bound index: " << left << endl;
    else
        cout << "Target not found, insert position: " << left << endl;
}