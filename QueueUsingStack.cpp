#include <bits/stdc++.h>
using namespace std;

class que {
  stack<int> s1;
  stack<int> s2;

public:
  void push(int x) {
    s1.push(x);
  }

  int pop() {
    if (s1.empty() && s2.empty()) {
      throw runtime_error("queue is empty!");
    }

    if (s2.empty()) {
      while (!s1.empty()) {
        int top_val = s1.top();
        s2.push(top_val);
        s1.pop();
      }
    }

    int top_val = s2.top();
    s2.pop();
    return top_val;
  }

  bool empty() {
    return s1.empty() && s2.empty();
  }
};

int main() {
  que q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  cout << q.pop() << endl;
  q.push(5);
  cout << q.pop() << endl;
  cout << q.pop() << endl;
  cout << q.pop() << endl;
  cout << q.pop() << endl;
  cout << q.empty() << endl;
  return 0;
}
