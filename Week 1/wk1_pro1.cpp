#include<bits/stdc++.h>
using namespace std;

void LinearSearch(vector<int>arr,int key){
	int i,cnt=0;
	int n=arr.size();
	for(i=0;i<=n-1;i++){
		cnt++;
		if(arr[i]==key){
			cout<<"Present "<<cnt<<endl;
			return;
		}
	}
	cout<<"Not present"<<cnt<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,i,key;
		cin>>n;
		vector<int>arr(n);
		for(i=0;i<n;i++){
			cin>>arr[i];
		}
		cin>>key;
		LinearSearch(arr,key);
	}
}
