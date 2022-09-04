#include <bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)
int arraySum(vector<int> &A,int start,int end){
    int n=A.size();
    int sum=0;
    loop(i,start,end){
        sum+=A[i];
    }
    return sum;
}

void validTriplet(vector<int> &A, int n)
{

    //int n=A.size();




    int ans = -1;

    loop(i,0,n){
        loop(j,0,n){
            loop(k,0,n){
                
                    int value = arraySum(A,0,i+1) - arraySum(A,i,j+1) + arraySum(A,j,k+1) - arraySum(A,k,n);
                    if (value > ans)
                    {
                        ans = value;
                    }
                
            }
        }
    }
    cout <<ans;
}
 

int main(){
     

    cout<<"Array Size: ";int n;cin>>n;
    vector<int> arr;
    cout<<"Array Elements: \n";
    loop(i,0,n){
        int x;cin>>x;
        arr.emplace_back(x);
       
    }
 
    validTriplet(arr, n);
    cout<<endl;
    return 0;
}