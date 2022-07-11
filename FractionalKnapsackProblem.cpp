#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)

struct Item{
    int value;
    int weight;
};

bool comp(Item a,Item b){
    double r1=(double)(a.value)/(double)(a.weight);
    double r2=(double)(b.value)/(double)(b.weight);
    return (r1>=r2);
}

// Time Complexity: O(n log n + n);  O(n log n) to sort the items and O(n) to iterate through all the items for calculating the answer.
// Space Complexity: O(1), no additional data structure has been used.
double fractionalKnapsack(int w,Item a[],int n){

    sort(a,a+n,comp);

    double value=0.0;
    double weight=0.0;

    for(int i=0;i<n;i++){
        double r=w-weight;
        if(weight<=w){
            if(r>=a[i].weight){
                value +=(double)(a[i].value);
                weight += a[i].weight;
            }else{
                value +=((double)(a[i].value)/(double)(a[i].weight))*r;
                weight += r;
            }

        }else{
            break;
        }
    }



    return value;

}


int main(){
    cout<<"Number of input: ";int n;cin>>n;
    cout<<"Weight: ";int w;cin>>w;
    struct Item a[n];
    loop(i,0,n){
        cin>>a[i].value>>a[i].weight;
    }
    double ans=fractionalKnapsack(w,a,n);
    cout << "The maximum value is "<<ans<<endl;



    return 0;
}