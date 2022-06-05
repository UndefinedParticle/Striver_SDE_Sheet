#include<bits/stdc++.h>
using namespace std;


int kadanesAlgo(vector<int>& a,vector<int>& subarray){

    int n=a.size();
    int maxSum=a[0];
    int currentSum=0;
    int i=0;
    for(int j=0;j<n;j++){

        currentSum=currentSum+a[j];
        
        if(currentSum > maxSum){
            subarray.clear();
            maxSum=currentSum;
            
            subarray.push_back(i);
            subarray.push_back(j);
        }
        if(currentSum<0){
            currentSum=0;
            i=j+1;
        }


    }

    return maxSum;
}

int maxSubArraySum(int a[], int size)
{
   int max_so_far = a[0];
   int curr_max = a[0];
 
   for (int i = 1; i < size; i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}



int main(){

    cout<<"Array size: ";
    int n;cin>>n;
    cout<<"Array Elements: ";
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.push_back(x);
    }
    
    vector<int> subarray;
    cout << "The longest subarray with maximum sum is " << kadanesAlgo(a,subarray) << endl;
    cout << "The subarray is: " << endl;
    for (int i = subarray[0]; i <= subarray[1]; i++) 
        cout << a[i] << " ";
    
    cout<<endl;


    return 0;
}