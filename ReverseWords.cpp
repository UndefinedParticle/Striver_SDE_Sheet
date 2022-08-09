#include<bits/stdc++.h>
using namespace std;

string reverse1(string s){
    int n=s.size();
    vector<string> temp;
    int j=n-1;
    for(int i=n-1;i>=0;i--){
        if(s[i]==' ' || i==0){
            if(i==0)
                temp.push_back(s.substr(i,j-i+1));
            else
                temp.push_back(s.substr(i+1,j-i));
            j=i-1;
        }
    }

    string ans="";
    for(int i=0;i<temp.size();i++){
        ans += temp[i];
        if(i!= temp.size()-1){
            ans+=" ";
        }
    }

    return ans;
}

string reverse2(string s){
    
    stack<string> st;
    string str="";
    s += " ";
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]==' ' && str != ""){
            st.push(str);
            str="";
        }else{
            str += s[i];
        }
    }

    string ans="";
    while(st.size() != 1){
        ans += st.top()+" ";
        st.pop();
    }
    ans += st.top();
    return ans;


}

string reverse3(string s){
    int left=0;
    int right=s.length()-1;
    
    string temp="";
    string ans="";

    while(left<=right){
        char ch=s[left];
        if(ch != ' '){
            temp += ch;
        }else if(ch == ' '){
            if(ans !=""){
                ans =temp + " " + ans;
            }else{
                ans=temp;
            }
            temp="";
        }left++;
    }
    if(temp != ""){
        if(ans != ""){
            ans =temp + " " + ans; 
        }else{
            ans=temp;
        }
    }

    string str="";
    //vector<string> st;
    string ans2="";
    for(int i=0;i<ans.size();i++){
        if(ans[i] != ' '){
            str += ans[i];
        }else if(ans[i]==' ' && str !=""){
            ans2+=str+" ";
            //st.push_back(str);
            str="";
        }
    }
    if(str!=""){
        ans2+=str;
        //st.push_back(str);
    }
    /*ans="";
    for(int i=0;i<st.size()-1;i++){
        ans += st[i]+" ";
    }
    ans+=st[st.size()-1];*/
    
    



    return ans2;

}


int main(){

    cout<<"Give a String: ";
    string s;getline(cin,s);

    cout<<"After reversing words: "<<endl;
    cout<<reverse1(s)<<endl;
    cout<<reverse2(s)<<endl;    








    return 0;
}