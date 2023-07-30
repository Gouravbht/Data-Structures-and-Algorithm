#include <iostream>
#include <deque> //deque header

using namespace std;

int main() {
  deque<int> deque;
  deque.push_back(1);
  deque.push_back(2);
  deque.push_back(3);

  cout << "The front element is: " << deque.front() << endl;
  cout << "The rear element is: " << deque.back() << endl;

  deque.pop_front();
  deque.pop_back();

  cout << "The size of the deque is: " << deque.size() << endl;

  return 0;
}
