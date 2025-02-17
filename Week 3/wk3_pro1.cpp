#include<bits/stdc++.h>
using namespace std;

void InsertionSort(vector<int>&arr,int &comp,int &shift){
  int n=arr.size();
  for(int i=1;i<n;i++){
    int j=i-1;
    int key=arr[i];
    while(j>=0 && key<arr[j]){
      arr[j+1]=arr[j];
      shift++;
      comp++;
      j--;
    }
    arr[j+1]=key;
    shift++;
  }
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
    int comp=0,shift=0;
    InsertionSort(arr,comp,shift);
    for(auto it:arr){
      cout<<it<<" ";
    }
    cout<<endl<<"Comparisons: "<<comp<<endl<<"Shifts: "<<shift<<endl;
  }
}
