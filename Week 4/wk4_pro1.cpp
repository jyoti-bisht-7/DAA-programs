#include<bits/stdc++.h>
using namespace std;

void Merge(vector<int>&arr,int low,int mid,int high,int &comp,int &inv){
  int i=low,j=mid+1;
  vector<int>temp;
  while(i<=mid && j<=high){
    if(arr[i]<=arr[j]){
      temp.push_back(arr[i]);
      comp++;
      i++;
    }
    else{
      temp.push_back(arr[j]);
      comp++;
      j++;
      inv+=(mid-i+1);
    }
  }
  while(i<=mid){
    temp.push_back(arr[i]);
    i++;
  }
  while(j<=high){
    temp.push_back(arr[j]);
    j++;
  }
  j=low;
  for(int i=0;i<temp.size();i++){
    arr[j]=temp[i];
    j++;
  }
}

void MergeSort(vector<int>&arr,int low,int high,int &comp,int &inv){
  if (low>=high){
    return;
  }
  int mid=(low+high)/2;
  MergeSort(arr,low,mid,comp,inv);
  MergeSort(arr,mid+1,high,comp,inv);
  Merge(arr,low,mid,high,comp,inv);
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
    int comp=0,inv=0;
    MergeSort(arr,0,n-1,comp,inv);
    for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
    }
    cout<<endl<<"Comparisons: "<<comp<<endl<<"Inversions: "<<inv<<endl;
  }
}
