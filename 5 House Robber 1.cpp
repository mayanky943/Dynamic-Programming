#include<bits/stdc++.h>
using namespace std;

int recur(int idx,vector<int> &houses){
	if(idx==0){
		return houses[idx];
	}
	int notPick=0+recur(idx-1,houses);
	int pick=INT_MIN;
	if(idx>1)
		pick=houses[idx]+recur(idx-2,houses);
	return max(pick,notPick);
}

int memoize(int idx,vector<int> &houses,vector<int> &dp){
	if(idx==0){
		return houses[idx];
	}
	if(dp[idx]!=-1) return dp[idx];
	int notPick=0+recur(idx-1,houses);
	int pick=INT_MIN;
	if(idx>1)
		pick=houses[idx]+recur(idx-2,houses);
	return dp[idx]=max(pick,notPick);
}

int tabulation(int n,vector<int> &houses){
	vector<int> dp(n,INT_MIN);
	dp[0]=houses[0];
	for(int i=1;i<n;i++){
		int notPick=dp[i-1];
		int pick=houses[i];
		if(i>1){
			pick+=dp[i-2];
		}
		dp[i]=max(pick,notPick);
	}
	return dp[n-1];
}

int spaceOptimized(int n,vector<int> &houses){
	int prev=houses[0];
	int prev2=0;
	for(int i=1;i<n;i++){
		int pick=houses[i];
		if(i>1){
			pick+=prev2;
		}
		int notPick=prev;
		int curr=max(pick,notPick);
		prev2=prev;
		prev=curr;
	}
	return prev;
}


int main(){
	int n;
	cin>>n;
	vector<int> houses(n);
	for(int i=0;i<n;i++){
		cin>>houses[i];
	}
	// cout<<recur(n-1,houses);
	// vector<int> dp(n,-1);
	// cout<<memoize(n-1,houses,dp);	
	// cout<<tabulation(n,houses);
	cout<<spaceOptimized(n,houses);
	return 0;
}