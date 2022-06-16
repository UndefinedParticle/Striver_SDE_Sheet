#include<bits/stdc++.h>
using namespace std;

vector<int> findTheAns1(vector<int>& a,int n){//count Sort
    vector<int> count(n+1,0);
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(count[a[i]]==1)
            ans.emplace_back(a[i]);
        else
            count[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(count[i]==0){
            ans.emplace_back(i);
            break;
        }
    }
    return ans;
}

vector<int> findTheAns2(vector<int>& a,int n){
    int s1=(n*(n+1))/2;
    int s2=(n*(n+1)*(2*n+1))/6;
    int sum1=0,sum2=0;
    int x,y;
    for(int i=0;i<n;i++){
        sum1=sum1+a[i];
        sum2=sum2+(a[i]*a[i]);
    }
    y=(((s2-sum2)/(s1-sum1))-s1+sum1)/2;
    x=s1-sum1+y;
    vector<int> ans={y,x};
    return ans;
}

vector<int> XorMethod(vector<int>& a,int n){
    int xor1=a[0];
    for(int i=1;i<n;i++){
        xor1=xor1^a[i];
    }
    for (int i = 1; i <=n; i++){
        xor1=xor1^i;
    }
    int rightBit=xor1 & ~(xor1-1);
    int mis=0,rep=0;
    
    for(int i=0;i<n;i++){
        if(a[i]&rightBit)
            mis=mis^a[i];
        else
            rep=rep^a[i];
    }
    for(int i=1;i<=n;i++){
        if(i & rightBit)
            mis=mis^i;
        else
            rep=rep^i;
    }
    int mis_count=0;
    for(int i=0;i<n;i++){
        if(a[i]==mis){
            mis_count++;
            break;
        }     
    }
    if(mis_count==0)
        return {rep,mis};
    return {mis,rep};
    
}

int main(){

    cout<<"Array Size:";
    int n;cin>>n;
    cout<<"Array Elements:\n";
    vector<int> a;
    //int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        //maxi=max(maxi,x);
        a.emplace_back(x);
    }
    cout<<"Using count sort:\n";
    vector<int> ans1=findTheAns1(a,n);
    cout<<"Repeating No: "<<ans1[0]<<endl;
    cout<<"Missing No: "<<ans1[1]<<endl;

    cout<<"Using Math:\n";
    vector<int> ans2=findTheAns2(a,n);
    cout<<"Repeating No: "<<ans2[0]<<endl;
    cout<<"Missing No: "<<ans2[1]<<endl;

    cout<<"Using XOR Method:\n";
    vector<int> ans3=XorMethod(a,n);
    cout<<"Repeating No: "<<ans3[0]<<endl;
    cout<<"Missing No: "<<ans3[1]<<endl;



    return 0;
}