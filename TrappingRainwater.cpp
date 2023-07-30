#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int rain_water(vector<int> a) {
  stack<int> st;
  int n = a.size(), ans = 0;
  for (int i = 0; i < n; i++) {
    while (!st.empty() && a[st.top()] <= a[i]) {
      int cur = st.top();
      st.pop();
      if (st.empty()) {
        break;
      }
      int diff = i - st.top() - 1;
      ans += (min(a[st.top()], a[i]) - a[cur]) * diff;
    }
    st.push(i);
  }
  return ans;
}

int main() {
  vector<int> a = {3, 0, 2, 0, 4};
  int water = rain_water(a);
  cout << "Total Water Trapped: " << water << endl;
  return 0;
}
