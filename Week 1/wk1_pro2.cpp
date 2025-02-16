#include<bits/stdc++.h>
using namespace std;

void BinarySearchrec(vector<int>arr,int low,int high,int &cnt,int key){
	if(low>high){
		cout<<"Not Present"<<cnt<<endl;
		return;
	}
	int mid=(low+high)/2;
	if(arr[mid]==key){
		cout<<"Present"<<cnt<<endl;
		return;
	}
	else if(arr[mid]>key){
		cnt++;
		BinarySearchrec(arr,low,mid-1,cnt,key);
	}
	else{
		cnt++;
		BinarySearchrec(arr,mid+1,high,cnt,key);
	}
}

void BinarySearch(vector<int>arr,int key){
	int i,cnt=0;
	int n=arr.size();
	int low=0,high=n-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(arr[mid]==key){
			cout<<"Present"<<cnt<<endl;
			return;
		}
		else if(arr[mid]>key){
			high=mid-1;
		}
		else{
			low=mid+1;
		}
		cnt++;
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
		int cnt=0;
		BinarySearchrec(arr,0,n-1,cnt,key);
	}
}
