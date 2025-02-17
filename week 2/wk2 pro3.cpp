#include<bits/stdc++.h>
using namespace std;
int difference(vector<int>arr,int k){
	int n=arr.size();
	int c=0;
	sort(arr.begin(),arr.end());
    int left = 0;
    int right = 1;
    while(left<n && right <n){
        if(arr[right]-arr[left] == k ){
    		left++;
        	right++;
        	c++;
        }
      	else if(arr[right] - arr[left] < k){
            right++;
        }
        else{
            left++;
        }
    }
    return c;
}
int main(){
    int t ;
    cin>>t;
    while(t--){
        int  n;
        cin>>n;
        vector<int>arr(n);
        for(int i = 0;i<n;i++){
          cin>>arr[i];
        }
        int k,c; 
        cin>>k;
        c=difference(arr,k);
        cout<<c<<endl;
    }
    return 0;
}
