#include<bits/stdc++.h>
using namespace std;

int ninjaTraining(int day,int last,vector<vector<int>> &points){
	if(day==0){
		int maxi=INT_MIN;
		for(int i=0;i<3;i++){
			if(i!=last){
				maxi=max(maxi,points[0][i]);
			}
		}
		return maxi;
	}
	int maxi=INT_MIN;
	for(int i=0;i<3;i++){
		if(i!=last){
			int pts=points[day][i]+ninjaTraining(day-1,i,points);
			maxi=max(maxi,pts);
		}
	}
	return maxi;
}

int memoize(int day,int last,vector<vector<int>> &points,vector<vector<int>> &dp){
	if(day==0){
		int maxi=INT_MIN;
		for(int i=0;i<3;i++){
			if(i!=last){
				maxi=max(maxi,points[0][i]);
			}
		}
		return maxi;
	}
	if(dp[day][last]!=-1){
		return dp[day][last];
	}
	int maxi=INT_MIN;
	for(int i=0;i<3;i++){
		if(i!=last){
			int pts=points[day][i]+memoize(day-1,i,points,dp);
			maxi=max(maxi,pts);
		}
	}
	return dp[day][last]=maxi;
}

int tabulation(int n,vector<vector<int>> &points){
	vector<vector<int>> dp(n,vector<int>(4,INT_MIN));
	//base-cases
	dp[0][0]=max(points[0][1],points[0][2]);
	dp[0][1]=max(points[0][0],points[0][2]);
	dp[0][2]=max(points[0][0],points[0][1]);
	dp[0][3]=max(points[0][1],max(points[0][0],points[0][2]));

	for(int day=1;day<n;day++){
		for(int last=0;last<4;last++){
			int maxi=INT_MIN;
			for(int task=0;task<3;task++){
				if(task!=last){
					int pts=points[day][task]+dp[day-1][task];
					maxi=max(maxi,pts);
				}
			}
			dp[day][last]=maxi;
		}
	}
	return dp[n-1][3];
}

int spaceOptimized(int n,vector<vector<int>> &points){
	vector<int> prev(4,0);
	prev[0]=max(points[0][1],points[0][2]);
	prev[1]=max(points[0][0],points[0][2]);
	prev[2]=max(points[0][0],points[0][1]);
	prev[3]=max(points[0][1],max(points[0][0],points[0][2]));

	for(int day=1;day<n;day++){
		vector<int> temp(4,0);
		for(int last=0;last<4;last++){
			temp[last]=0;
			for(int task=0;task<3;task++){
				if(task!=last){
					temp[last]=max(temp[last],points[day][task]+prev[task]);
				}
			}
			
		}
		prev=temp;
	}
	return prev[3];

}

void print(vector<vector<int>> &points){
	for(auto k:points){
		for(auto m:k){
			cout<<m<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>> points(n,vector<int>(3,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin>>points[i][j];
		}
	}
	// cout<<ninjaTraining(n-1,3,points);
	// vector<vector<int>> dp(n,vector<int>(4,-1));
	// cout<<memoize(n-1,3,points,dp);
	// cout<<tabulation(n,points);
	cout<<spaceOptimized(n,points);
	return 0;
}