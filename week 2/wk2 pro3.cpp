#include <bits/stdc++.h>
using namespace std;

int difference(vector<int>& arr, int k) {
    int n = arr.size();
    int c = 0;
    sort(arr.begin(), arr.end());
    
    int left = 0;
    int right = 1;
    
    while (right < n) {
        if (left == right) {
            right++;
            continue;
        }

        int diff = arr[right] - arr[left];
        
        if (diff == k) {
            c++;
            left++;
            right++;
            // Skip duplicates
            while (left < n && arr[left] == arr[left - 1]) 
		    left++;
            while (right < n && arr[right] == arr[right - 1]) 
		    right++;
        } 
	else if (diff < k) {
            right++;
        } 
	else {
            left++;
        }
    }
    return c;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int k;
        cin >> k;
        int c = difference(arr, k);
        cout << c << endl;
    }
    return 0;
}
