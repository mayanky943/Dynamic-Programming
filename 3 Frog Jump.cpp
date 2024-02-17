#include<bits/stdc++.h>
using namespace std;

int recur(int n,vector<int> &heights){
	if(n==0){
		return 0;
	}

	int jump1=abs(heights[n-1]-heights[n])+recur(n-1,heights);
	int jump2=INT_MAX;
	if(n>1)
		jump2=abs(heights[n-2]-heights[n])+recur(n-2,heights);
	return min(jump1,jump2);
} 

int memoize(int n,vector<int> &heights,vector<int> &dp){
	if(n==0){
		return 0;
	}

	if(dp[n]!=-1) return dp[n];

	int jump1=abs(heights[n-1]-heights[n])+recur(n-1,heights);
	int jump2=INT_MAX;
	if(n>1)
		jump2=abs(heights[n-2]-heights[n])+recur(n-2,heights);
	return dp[n]=min(jump1,jump2);
}

int tabulation(int n,vector<int> &heights){
	vector<int> dp(n,-1);
	dp[0]=0;
	for(int i=1;i<n;i++){
		int jump1=dp[i-1]+abs(heights[i]-heights[i-1]);
		int jump2=INT_MAX;
		if(i>1)
			jump2=dp[i-2]+abs(heights[i]-heights[i-2]);
		dp[i]=min(jump1,jump2);
	}
	return dp[n-1];
}

int spaceOptimized(int n,vector<int> heights){
	int prev=0;
	int prev2=0;
	for(int i=1;i<n;i++){
		int jump1=prev+abs(heights[i]-heights[i-1]);
		int jump2=INT_MAX;
		if(i>1)
			jump2=prev2+abs(heights[i]-heights[i-2]);
		int curr=min(jump1,jump2);

		prev2=prev;
		prev=curr;
	}
	return prev;
}

int main(){
	int n;
	cin>>n;
	vector<int> heights(n);
	for(int i=0;i<n;i++){
		cin>>heights[i];
	}
	// cout<<recur(n-1,heights);
	// vector<int> dp(n+1,-1);
	// cout<<memoize(n-1,heights,dp);
	// cout<<tabulation(n,heights);
	cout<<spaceOptimized(n,heights);
	return 0;
}