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

int tabulation(){

}

int spaceOptimized(){

}

int main(){
	int n;
	cin>>n;
	vector<int> heights(n);
	for(int i=0;i<n;i++){
		cin>>heights[i];
	}
	// cout<<recur(n-1,heights);
	vector<int> dp(n+1,-1);
	cout<<memoize(n-1,heights,dp);
	return 0;
}