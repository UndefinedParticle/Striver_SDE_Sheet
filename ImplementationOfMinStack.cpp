#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define loop(i,a,n) for(int i=a;i<n;i++)


class MinStack1{
    stack<pair<int,int>> st;
    int mini=INT_MAX;
    public:

        void push(int data){
            
            if(st.empty()){
                mini=data;
            }else{
                if(st.top().second < data){
                    mini=st.top().second;
                }else{
                    mini=data;
                }
            }
            st.push({data,mini});
        }

        void pop(){
            st.pop();
        }

        int top(){
            return st.top().first;
        }

        int getMin(){
            return st.top().second;
        }


};





class MinStack2{

    stack<int> st;
    int mini;
    public:
        MinStack2(){
            while(!st.empty()){
                st.pop();
            }
            mini=INT_MAX;
        }

        void push(int data){
            int val=INT_MAX;
            if(st.empty()){
                mini=val;
                st.push(val);
            }else{
                if(val < mini){
                    st.push(2*val -mini);
                    mini=val;
                }else{
                    st.push(val);
                }
            }
        }


        void pop(){
            if(st.empty()){
                return;
            }
            int temp=st.top();
            st.pop();
            if(temp < mini){
                mini=2*mini - temp;
            }
        }

        int top(){
            if(st.empty()){
                return -1;
            }
            int temp=st.top();
            if(temp < mini){
                return mini;
            }
            return temp;
        }

        int getMini(){
            return mini;
        }


};




int main(){




    return 0;
}