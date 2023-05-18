#include<iostream> 
#include<vector> 
using namespace std; 
int main(){ 
int n; 
cout<<"Enter the size of array"<<endl; cin>>n; 
cout<<"Enter the elements of array"<<endl; vector<int> arr; 
for(int i=0; i<n; i++){ 
int elm; 
cin>>elm; 
arr.push_back(elm); 
} 
int res=-1; 
vector<int> dp(n,-1); 
dp[0]=1; 
for(int i=1; i<n; i++){ 
int val = 0; 
for(int j=0; j<i; j++){ 
if(arr[i]>arr[j]){ 
val=max(val,dp[j]); 
} 
} 
dp[i]=val+1; 
res=max(res,dp[i]); 
} 
cout<<res<<endl; 
return 0;
} 
