#include<bits/stdc++.h>
using namespace std;
void LinearSearch(vector<int>arr,int i,int j,int cnt,int key){
	int ind;
	int n=arr.size();
	//if j is out of bound
	j=(j>=n)?n-1:j;
	for(ind=i;ind<=j;ind++){
		if(arr[ind]==key){
			cout<<"Present "<<cnt<<endl;
			return;
		}
	}
	cout<<"Not present"<<endl;
}
void JumpSearch(vector<int>arr,int key){
	int i,cnt=0;
	int n=arr.size();
	for(i=0;i<n;i++){
		int indi=pow(2,i-1);
		int indj=pow(2,i-1+1);
		cnt++;
		//edge cases
		if(indi>=n || arr[indi]>key){
			cout<<"Not Present"<<endl;
			return;
		}
		//key found
		if(arr[indi]==key){
			cout<<"Present "<<cnt<<endl;
			return;
		}
	    else{
	    	//arr[indi]<key
	    	// arr[indi]<key<arr[indj]
	    	if(indj>=n || arr[indj]>key){
	    		LinearSearch(arr,indi+1,indj,cnt,key);
	    		return;
			}
		}
	}
	cout<<"Not present"<<endl;
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
		JumpSearch(arr,key);
	}
}
