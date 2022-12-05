#include <bits/stdc++.h>
using namespace std;
#define loop(i, a, n) for (int i = a; i < n; i++)

/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/


bool knows(int a, int b)
{
    if (a == b)
        return true;
    return false;
}

int findCelebrity1(int n) {
 	int candidate=0;
    for(int i=1;i<n;i++){
        if(knows(candidate,i)==1){
            candidate=i;
           }
     }
    for(int i=0;i<n;i++){
        if(i!=candidate && (knows(candidate,i)==1 || knows(i,candidate)==0))return -1;
       }
   return candidate;
}

int findCelevrity2(int n){

    stack<int> st;
    loop(i, 0, n){
        st.push(i);
    }
    int candidate=0;
    while (st.size() >= 2){

        int c = st.top();
        st.pop();
        int i = st.top();
        st.pop();

        if (knows(c, i) == 0){
            st.push(c);
            candidate=c;
        }else{
            st.push(i);
            candidate=i;
        }
    }

    loop(i,0,n){
        if(i != candidate){
            if(knows(i,candidate)==0 || knows(candidate,i)==1){
                return -1;
            }
        }
    }

    return candidate;
}

int main(){

    return 0;
}