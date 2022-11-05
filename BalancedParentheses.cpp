#include<iostream>
#include<string>
#include<stack>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)


bool checkParentheses(string s){
    int n=s.size();
    stack<char> st;
    loop(i,0,n){
        char ch;
        if(s[i]==')' || s[i]=='}' || s[i]==']'){
            if(st.size()==0) return false;
            switch(s[i]){
                case ')':
                    ch='(';
                    if(ch!=st.top()){
                        return false;
                    }st.pop();
                    break;
                case '}':
                    ch='{';
                    if(ch!=st.top()){
                        return false;
                    }st.pop();
                 break;
                case ']':
                    ch='[';
                    if(ch!=st.top()){
                        return false;
                    }st.pop();
                    break;
            }
        }else{
            st.push(s[i]);
        }
    }

    return st.empty();
}




int main(){


    cout<<"String: ";string s;cin>>s;

    cout<<"Ans: "<<checkParentheses(s)<<endl;





    return 0;
}