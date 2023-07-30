#include<iostream>
using namespace std;

int main(){
    // int array[4]={13,20,31,17};
    // cout<<array[0]<<endl;
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
      cin>>array[i];
    } 
    for(int i=0;i<n;i++){
        cout<<array[i]<<" "<<endl;
    }
}