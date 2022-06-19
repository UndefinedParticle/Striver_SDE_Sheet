#include<bits/stdc++.h>
using namespace std;


    // Time Complexity: O(log n)
    // Space Complexity: O(1)
double myPow(double x, int n) {
  double ans = 1.0;
  long long nn = n;
  if (nn < 0) nn = -1 * nn;
  while (nn) {
    if (nn % 2) {
      ans = ans * x;
      nn = nn - 1;
    } else {
      x = x * x;
      nn = nn / 2;
    }
  }
  if (n < 0) ans = (double)(1.0) / (double)(ans);
  return ans;
}

int main(){

    cout<<"X: ";int x;cin>>x;
    cout<<"N: ";int n;cin>>n;
    float ans=1;

    // Time Complexity: O(N)
    // Space Complexity: O(1)
    for(int i=0;i<abs(n);i++){
        ans=ans*2;
    }
    if(n<0)
        cout<<"Ans(1): "<<(float)(1/ans)<<endl;
    else
        cout<<"Ans(1): "<<ans<<endl;
    cout<<"Ans(2): "<<myPow(x,n)<<endl;



    return 0;
}