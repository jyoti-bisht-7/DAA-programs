#include<bits/stdc++.h>
using namespace std;

void intersection(vector<int>A,vector<int>B){
  int i=0,j=0;
  int m=A.size(),n=B.size();
  vector<int>ans;
  while(i<m && j<n){
    if(A[i]==B[j]){
      ans.push_back(A[i]);
      i++;
      j++;
    }
    else if(A[i]<B[j]){
      i++;
    }
    else{
      j++;
    }
  }
  for(auto it:ans){
    cout<<it<<" ";
  }
}

int main(){
    int m,n;
    cin>>m;
    vector<int> A(m);
    for(int i=0;i<m;i++){
      cin>>A[i];
    }
    cin>>n;
    vector<int> B(n);
    for(int i=0;i<n;i++){
      cin>>B[i];
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    intersection(A,B);
  
}
