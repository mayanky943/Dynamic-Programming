#include<bits/stdc++.h>
using namespace std;

int recur(int n,int k,vector<int> &heights){
	if(n==0){
		return 0;
	}
	int mmSteps=INT_MAX;
	for(int i=1;i<=k;i++){
		if(n-i>=0){
			int jump=abs(heights[n]-heights[n-i])+recur(n-i,k,heights);
			mmSteps=min(mmSteps,jump);
		}
	}
	return mmSteps;	
}

int memoize(int idx,int k,vector<int> &heights,vector<int> &dp){
	if(idx==0) return 0;

	if(dp[idx]!=-1) return dp[idx];
	int mmSteps=INT_MAX;
	for(int i=1;i<=k;i++){
		if(idx-i>=0){
			int jump=memoize(idx-i,k,heights,dp)+abs(heights[idx]-heights[idx-i]);
			mmSteps=min(mmSteps,jump);
		}
	}
	return dp[idx]=mmSteps;
}

int tabulation(int n,int k,vector<int> &heights){
	vector<int> dp(n,INT_MAX);
	dp[0]=0;
	for(int i=1;i<n;i++){
		for(int j=1;j<=k;j++){
			if(i-j>=0){
				int jump=dp[i-j]+abs(heights[i]-heights[i-j]);
				dp[i]=min(dp[i],jump);
			}
		}
	}
	return dp[n-1];
}

int main(){
	int n,k;
	cin>>n>>k;
	vector<int> heights(n);
	for(int i=0;i<n;i++){
		cin>>heights[i];
	}
	// cout<<recur(n-1,k,heights);
	// vector<int> dp(n,-1);
	// cout<<memoize(n-1,k,heights,dp);
	cout<<tabulation(n,k,heights);
	return 0;
}