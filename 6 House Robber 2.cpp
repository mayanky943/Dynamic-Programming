#include<bits/stdc++.h>
using namespace std;

int spaceOptimized(int n,vector<int> &houses){
    int prev=houses[0];
    int prev2=0;
    for(int i=0;i<n;i++){
        int take=houses[i];
        if(i>1){
            take+=prev2;
        }
        int notTake=prev;
        int curr=max(take,notTake);
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
    vector<int> house1,house2;
    for(int i=0;i<n;i++){
        if(i!=0) house1.push_back(houses[i]);
        if(i!=n-1) house2.push_back(houses[i]);
    }
    cout<<max(spaceOptimized(n-1,house1),spaceOptimized(n-1,house2));
    return 0;
}