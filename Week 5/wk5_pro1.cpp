#include<bits/stdc++.h>
using namespace std;

void max_occurrence(vector<char>str){
  int hash[256]={0};
  for(int i=0;i<str.size();i++){
    hash[str[i]]++;
  }
  int max_occ=1;//1 occurrence is minimum as we need duplicates
  char alpha;
  for(int i=0;i<256;i++){
    if(hash[i]>max_occ){
      max_occ=hash[i];
      alpha=char(i);
    }
  }
  if(max_occ==1){
    cout<<"No duplicates present"<<endl;
  }
  else{
    cout<<alpha<<" - "<<max_occ<<endl;
  }
}


int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<char> str(n);
    for(int i=0;i<n;i++){
      cin>>str[i];
    }
    max_occurrence(str);
  }
}
