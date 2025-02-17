#include<bits/stdc++.h>
using namespace std;

void SelectionSort(vector<int>&arr,int &comp,int &swaps){
  int n=arr.size();
  for(int i=0;i<n-1;i++){
    int mini=i;
    for(int j=i+1;j<n;j++){
      if(arr[j]<arr[mini]){
        mini=j;
      }
      comp++;
    }
    swap(arr[i],arr[mini]);
    swaps++;
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
    int comp=0,swaps=0;
    SelectionSort(arr,comp,swaps);
    for(auto it:arr){
      cout<<it<<" ";
    }
    cout<<endl<<"Comparisons: "<<comp<<endl<<"Swaps: "<<swaps<<endl;
  }
}
