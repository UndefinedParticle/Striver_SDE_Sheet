#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)

class StockSpanner {
    stack<pair<int,int>> st;
    public:
        StockSpanner() {
        
        }
    
    int next(int price) {
        int cnt = 1;
    while (!st.empty() && st.top().first <= price) {
        cnt += st.top().second;
        st.pop();
    }
    st.push({price, cnt});
    return cnt;
    }
};



int main(){






    return 0;
}