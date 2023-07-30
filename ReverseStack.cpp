#include<iostream>
#include<stack>
using namespace std;

void reverse(stack<int> &st){
    stack<int> st1;
    int n = st.size();
    for(int i=0; i<n; i++){
        int x = st.top();
        st.pop();
        for(int j=0; j<n-i-1; j++){
            int y = st.top();
            st.pop();
            st1.push(y);
        }
        st.push(x);
        while(!st1.empty()){
            int y = st1.top();
            st1.pop();
            st.push(y);
        }
    }
}