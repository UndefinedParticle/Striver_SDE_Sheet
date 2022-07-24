#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)

// Time Complexity :O(m+n)
// Space Complexity : O(m+n)
double findMedian1(vector<int> &arr1,vector<int> &arr2){
    int m=arr1.size();
    int n=arr2.size();
    vector<int> temp(m+n);
    int i=0,j=0,k=0;
    while(i<m && j<n){
        if(arr1[i]<=arr2[j]){
            temp[k++]=arr1[i++];
        }else{
            temp[k++]=arr2[j++];
        }
    }
    if(i<m){
        while(i<m){
            temp[k++]=arr1[i++];
        }
    }

    if(j<n){
        while(j<n){
            temp[k++]=arr2[j++];
        }
    }

    if((m+n)&1){
        return temp[(m+n+1)/2-1];
    }else{
        return (((double)temp[(m+n)/2 -1] + (double)temp[(m+n)/2])/2);
    }
    

}


// Time Complexity :O(m+n)
// Space Complexity : O(1)
double findMedian2(vector<int> &arr1,vector<int> &arr2){
    int m=arr1.size();
    int n=arr2.size();
    int count=0;
    int i=0,j=0,k=0;
    double x=0,y=0;
    while(i<m && j<n){
        if(arr1[i]<=arr2[j]){
            count++;
            if(count==(m+n+1)/2){
                x=arr1[i];
            }
            if(count==1+(m+n+1)/2){
                y=arr1[i];
            }
            
            i++;
            
        }else{
            count++;
            if(count==(m+n+1)/2){
                x=arr2[j];
            }
            if(count==1+(m+n+1)/2){
                y=arr2[j];
            }
            
            j++;
        }
    }
    if(i<m){
        while(i<m){
            count++;
            if(count==(m+n+1)/2){
                x=arr1[i];
            }
            if(count==1+(m+n+1)/2){
                y=arr1[i];
            }
            
            i++;
            
        }
    }

    if(j<n){
        while(j<n){
            count++;
            if(count==(m+n+1)/2){
                x=arr2[j];
            }
            if(count==1+(m+n+1)/2){
                y=arr2[j];
            }
            
            j++;
            
        }
    }

    if((m+n)&1){
        return x;
    }else{
        return (x + y)/2.0;
    }
    

}


// Time Complexity : O(log(m,n))
// We are applying binary search on the array which has a minimum size.

// Space Complexity: O(1)
double findMedian3(vector<int> &arr1,vector<int> &arr2){
    int m=arr1.size();
    int n=arr2.size();

    if(m>n){//ensuring that binary search happens on minimum size array
        vector<int> temp=arr1;
        arr1=arr2;
        arr2=temp;
        int x=m;
        m=n;
        n=x;
    }
    int low=0,high=m;
    int mid=(m+n+1)/2;
    while(low<=high){
        int cut1=(low+high)>>1;
        int cut2=mid-cut1;
        int l1=(cut1==0)? INT_MIN:arr1[cut1-1];
        int l2=(cut2==0)? INT_MIN:arr2[cut2-1];
        int r1=(cut1==m)? INT_MAX:arr1[cut1];
        int r2=(cut2==n)? INT_MAX:arr2[cut2];
        if(l1<=r2 && l2<=r1){
            if((m+n)&1){
                return max(l1,l2);
            }else{
                return (max(l1,l2)+min(r1,r2))/2.0;
            }
        }else if(l1>r2){
            high=cut1-1;
        }else{
            low=cut1+1;
        }
    }

    return 0.0;



}


int main(){

    cout<<"Array1 size: ";int m;cin>>m;
    cout<<"Array1 Elements:\n";
    vector<int> arr1;
    loop(i,0,m){
        int x;cin>>x;
        arr1.emplace_back(x);
    }

    cout<<"Array2 size: ";int n;cin>>n;
    cout<<"Array2 Elements:\n";
    vector<int> arr2;
    loop(i,0,n){
        int x;cin>>x;
        arr2.emplace_back(x);
    }

    cout<<"The median of two sorted array is "<<fixed<<setprecision(5)<<findMedian1(arr1,arr2)<<endl;
    cout<<"The median of two sorted array is "<<fixed<<setprecision(5)<<findMedian2(arr1,arr2)<<endl;
    cout<<"The median of two sorted array is "<<fixed<<setprecision(5)<<findMedian3(arr1,arr2)<<endl;




    return 0;
}