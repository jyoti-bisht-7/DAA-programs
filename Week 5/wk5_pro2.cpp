#include<bits/stdc++.h>
using namespace std;

void sum_of_two(vector<int>arr,int key){
  sort(arr.begin(),arr.end());
  int n=arr.size();
  int left=0,right=n-1;
  while(left<right){
    if(arr[left]+arr[right]>key){
      right--;
    }
    else if(arr[left]+arr[right]<key){
      left++;
    }
    else{
      cout<<arr[left]<<" "<<arr[right]<<endl;
      return;
    }
  }
  cout<<"No such element exist"<<endl;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    int key;
    cin>>key;
    sum_of_two(arr,key);
  }
}
