#include<bits/stdc++.h>
using namespace std;
void find_triplet(vector<int>arr){
	int n=arr.size();
    int i,j,k;
    i=0;
    while(i<n){
    	j=i+1;
    	while(j<n){
    		k=j+1;
    		while(k<n){
    			if(arr[i]+arr[j]==arr[k]){
    				cout<<i+1<<" "<<j+1<<" "<<k+1<<endl;
    				return;
				}
				else if(arr[i]+arr[j]<arr[k]){
					break;
				}
				else{
					k++;
				}
			}
			j++;
		}
		i++;
	}
	cout<<"No sequence found"<<endl;
}
        
int main(){
    int t ;
    cin>>t;
    while(t--){
        int  n;
        cin>>n;
        vector<int>arr(n);
        for(int i = 0;i<n;i++){
          cin>>arr[i];
        }
        find_triplet(arr);
    }
    return 0;
}
