#include<bits/stdc++.h>
using namespace std;

int recur(int n){
	if(n==0) return 1;
	if(n<0) return 0;
	return recur(n-1)+recur(n-2);
}

int memoize(int n,vector<int> &dp){
	if(n==0) return 1;
	if(n<0) return 0;
	if(dp[n]!=-1) return dp[n];
	return dp[n]=memoize(n-1,dp)+memoize(n-2,dp);
}



int main(){
	int n;
	cin>>n;
	// cout<<recur(n);
	vector<int> dp(n+1,-1);
	cout<<memoize(n,dp);
	// cout<<tabulation(n);
	// cout<<spaceOptimized(n);
	return 0;
}