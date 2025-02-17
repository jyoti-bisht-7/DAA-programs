#include <bits/stdc++.h>
using namespace std;
int floor(vector<int>arr, int target){
	int n=arr.size();
    int low=0;
    int high=n-1;
    int floor=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]<=target){
            if(arr[mid]==target)
               floor=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return floor;
}
int ceil(vector<int>arr, int target){
	int n=arr.size();
    int low=0;
    int high=n-1;
    int ceil=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=target){
            if(arr[mid]==target)
               ceil=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ceil;
}
int count(vector<int>arr, int target) {
	int first=ceil(arr,target);
	if(first==-1)
        return 0;
	int last=floor(arr,target);
	return last-first+1;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int target;
		cin>>target;
		cout<<target<<" - "<<count(arr,target)<<endl;
	}
	return 0;
}
