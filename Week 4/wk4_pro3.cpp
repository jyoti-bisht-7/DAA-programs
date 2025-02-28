#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&arr,int low,int high){
  int pivot=arr[high];
  int i=low-1;
  for(int j=low;j<high;j++){
  	if(arr[j]<=pivot){
  		i++;
  		swap(arr[i],arr[j]);
	}
  }
  swap(arr[high],arr[i+1]);
  return i+1;
}

int findKth(vector<int>&arr,int low,int high,int k){
  if (low>high){
    return -1;
  }
  int p_index=partition(arr,low,high);
  if (k-1 > p_index)
    return  findKth(arr,p_index+1,high,k);
  else if (k-1 < p_index)
    return findKth(arr,low,p_index-1,k);
  else
    return arr[p_index];
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
    int k;
    cin>>k;
    int ans=findKth(arr,0,n-1,k);
    cout<<ans<<endl;
  }
}
