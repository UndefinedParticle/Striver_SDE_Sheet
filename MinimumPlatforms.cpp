#include<bits/stdc++.h>
using namespace std;
struct platform{
    int a;
    int d;
    int num;
};

//comparator
bool static comp(platform m1,platform m2){
    if(m1.d < m2.d)
        return true;
    else if(m1.d > m2.d)
        return false;
    else if(m1.num < m2.num)
        return true;
    return false;
}

// Time Complexity: O(n log n)
// Space Complexity: O(n)
int minPlatforms(int s[],int e[],int n){
    struct platform train[n];
    for(int i=0;i<n;i++){
        train[i].a=s[i];
        train[i].d=e[i];
        train[i].num=i+1;
    }
    sort(train,train+n,comp);
    vector<int> ans;
    int time=train[0].d;
    ans.push_back(train[0].num);

    for(int i=1;i<n;i++){
        if(train[i].a < time){
            time=train[i].d;
            ans.push_back(train[i].num);
        }
    }
    


    return ans.size();

}



int main(){

    cout<<"Number of platforms: ";int n;cin>>n;
    cout<<"Arriviing time: \n";
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<"Deparature time:\n";
    int d[n];
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    cout<<"Minimum number of Platforms required "<<minPlatforms(a,d,n)<<endl;




    return 0;
}