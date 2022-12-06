#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)

string writeAsYouSpeak(int n){

    string ans="1";
    if(n==1) return ans;
    int cnt=0;
    loop(i,2,n+1){
        cnt=1;
        string str="";
        for(int j=0;j<ans.size();j++){
            if(ans[j]==ans[j+1]){
                cnt++;
            }else{
                str += to_string(cnt)+ans[j];
                cnt=1;
            }
        }
        ans=str;

    }
    return ans;

}



int main(){

    cout<<"Number of iteration: ";int n;cin>>n;

    cout<<"Ans: "<<writeAsYouSpeak(n)<<endl;




    return 0;
}