#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&arr,int low,int high,int &comp,int &swaps){
  int pivot=arr[high];
  int i=low-1;
  for(int j=low;j<high;j++){
  	if(arr[j]<=pivot){
  		i++;
  		swap(arr[i],arr[j]);
  		swaps++;
	}
	comp++;
  }
  swap(arr[high],arr[i+1]);
  swaps++;
  return i+1;
}

void QuickSort(vector<int>&arr,int low,int high,int &comp,int &swaps){
  if (low>=high){
    return;
  }
  int p_index=partition(arr,low,high,comp,swaps);
  QuickSort(arr,low,p_index-1,comp,swaps);
  QuickSort(arr,p_index+1,high,comp,swaps);
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
    int comp=0,swaps=0;
    QuickSort(arr,0,n-1,comp,swaps);
    for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
    }
    cout<<endl<<"Comparisons: "<<comp<<endl<<"Swaps: "<<swaps<<endl;
  }
}
