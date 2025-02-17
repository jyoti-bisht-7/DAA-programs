#include<bits/stdc++.h>
using namespace std;

void Merge(vector<int>&arr,int low,int mid,int high){
	int n=arr.size();
	int i=low;
	int j=mid+1;
	vector<int>temp;
	while(i<=mid && j<=high){
		if(arr[i]<=arr[j]){
			temp.push_back(arr[i]);
			i++;
		}
		else{
			temp.push_back(arr[j]);
			j++;
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
	
	int k=low;
	for(int i=0;i<temp.size();i++){
		arr[k]=temp[i];
		k++;
	}
}
void MergeSort(vector<int>&arr,int low,int high){
  if (low>=high){
  	return;
  }
  int mid=(low+high)/2;
  MergeSort(arr,low,mid);
  MergeSort(arr,mid+1,high);
  Merge(arr,low,mid,high);
}

bool duplicates(vector<int>arr){
	int n=arr.size();
	for(int i=0;i<n-1;i++){
		if(arr[i]==arr[i+1]){
			return true;
		}
	}
	return false;
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
    MergeSort(arr,0,n-1);
    if(duplicates(arr)){
    	cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
    
  }
}
