#include<bits/stdc++.h>
using namespace std;

struct Job { 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

bool comp(struct Job j1,Job j2){
    return (j1.profit>=j2.profit);
}

// Time Complexity: O(N log N) + O(N*M).
// O(N log N ) for sorting the jobs in decreasing order of profit. O(N*M) since we are iterating through all N jobs and for every job we are checking from the last deadline, say M deadlines in the worst case.

// Space Complexity: O(M) for an array that keeps track on which day which job is performed if M is the maximum deadline available.
vector<int> jobScheduling(Job a[],int n){
    sort(a,a+n,comp);
    int maxi=a[0].dead;
    for(int i=1;i<n;i++)
        maxi=max(maxi,a[i].dead);


    int day[maxi];
    for(int i=1;i<=maxi;i++)
        day[i]=-1;
    
    day[a[0].dead]=a[0].dead;

    int maxProfit=a[0].profit;
    int count=1;
    for(int i=1;i<n;i++){
        int j=a[i].dead;
        while(j>=1){
            if(day[j]==-1){
                maxProfit += a[i].profit;
                count++;
                day[j]=a[i].dead;
                break;
            }
            j--;
        }
    }

    return {count,maxProfit};




}


int main(){
    cout<<"Number of jobs: ";int n;cin>>n;
    Job a[n];
    cout<<"Id,Deadline and Profit:\n";
    for(int i=0;i<n;i++){
        cin>>a[i].id>>a[i].dead>>a[i].profit;
    }
    vector<int> ans=jobScheduling(a,n);
    cout<<"Ans: "<<ans[0]<<" "<<ans[1]<<endl;


    return 0;
}