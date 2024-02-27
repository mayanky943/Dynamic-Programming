#include<bits/stdc++.h>
using namespace std;

int recur(int m,int n){
	if(m==0 and n==0) return 1;
	if(m<0 or n<0) return 0;

	int left=recur(m,n-1);
	int up=recur(m-1,n);

	return left+up;
}
int memoize(int i,int j,vector<vector<int>> &dp){
	if(i==0 and j==0) return 1;
	if(i<0 or j<0) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	int left=memoize(i,j-1,dp);
	int up=memoize(i-1,j,dp);

	return dp[i][j]=left+up;
}
int tabulation(int m,int n){
	vector<vector<int>> dp(m,vector<int>(n,0));
	dp[0][0]=1;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i==0 and j==0) continue;
			else{
				int right=dp[i][j-1];
				int down=dp[i-1][j];
				dp[i][j]=right+down;
			}
		}
	}
	return dp[m-1][n-1];
}
int spaceOptimized(int m,int n){
	vector<int> prev(n,0);
	for(int i=0;i<m;i++){
		vector<int> temp(n,0);
		for(int j=0;j<n;j++){
			if(i==0 and j==0){
				temp[j]=1;
			}
			else{
				
				int up=prev[j];
				int left=temp[j-1];
				temp[j]=up+left;
			}
		}
		prev=temp;
	}
	return prev[n-1];
}

int main(){
	int m,n;
	cin>>m>>n;
	// cout<<recur(m-1,n-1);
	// vector<vector<int>> dp(m,vector<int>(n,-1));
	cout<<spaceOptimized(m,n);
	return 0;
}

 