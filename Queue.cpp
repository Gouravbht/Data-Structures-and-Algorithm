#include<iostream>
using namespace std;

class queue {
  int* arr;
  int front;
  int back;
  int n; // added size of the queue

public:
  queue() {
    n = 100; // set the size of the queue
    arr = new int[n];
    front = -1;
    back = -1;
  }

  void push(int x) {
    if (back == n - 1) { // corrected comparison operator
      cout << "Queue overflowed" << endl;
      return;
    }
    back++;
    arr[back] = x;
    if (front == -1) {
      front++;
    }
  }

  void pop() {
    if (front == -1 || front > back) {
      cout << "No elements in queue" << endl;
      return;
    }
    front++;
  }

  int peek() { // changed the return type from void to int
    if (front == -1 || front > back) {
      cout << "No elements in queue" << endl;
      return -1;
    }
    return arr[front];
  }

  bool empty() {
    if (front == -1 || front > back) {
      return true;
    }
    return false;
  }
};

int main() {
  queue q;
  q.push(13);
  q.push(3);
  q.push(30);
  q.push(1);
  cout << q.peek() << endl;
  q.pop();
  cout << q.peek() << endl;
  q.pop();
  cout << q.peek() << endl;
  q.pop();
  cout << q.peek() << endl;
  q.pop();
  cout << q.empty() << endl;

  return 0; // added the missing return statement for the main function
}
