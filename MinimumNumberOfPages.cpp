#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &book,int bound,int b){
    int n=book.size();
    int student=1;
    int pages=0;
    for(int i=0;i<n;i++){
        if(pages+book[i] > bound){
            student++;
            pages=book[i];
        }else{
            pages += book[i];
        }
    }

    if(student > b){
        return false;
    }else{
        return true;
    }

}

int minNumber(vector<int> &book,int b){
    int n=book.size();
    if(b>n){
        return -1;
    }
    int low=*max_element(book.begin(),book.end());
    int high=0;
    for(int i=0;i<n;i++){
        high+=book[i];
    }
    //cout<<low<<" "<<high<<endl;
    while(low<=high){
        int mid=(low+high)>>1;
        if(isPossible(book,mid,b)){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }

    return low;

}






int main(){

    cout<<"Array Size: ";int n;cin>>n;
    cout<<"Array Elements:\n";
    vector<int> book;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        book.emplace_back(x);
    }
    cout<<"Numer of students: ";int b;cin>>b;

    cout << "Minimum Possible Number is " << minNumber(book,b)<<endl;





    return 0;
}