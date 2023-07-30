#include <iostream>
#include <deque>

using namespace std;

int main() {
  deque<int> myDeque;
  int arr[] = {1,2,3,4,5,6,7};
  int window_size = 3;
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i < arr_size; i++) {
    if (!myDeque.empty() && myDeque.front() == arr[i - window_size]) {
      myDeque.pop_front();
    }

    while (!myDeque.empty() && myDeque.back() < arr[i]) {
      myDeque.pop_back();
    }

    myDeque.push_back(arr[i]);

    if (i >= window_size - 1) {
      cout << myDeque.front() << " ";
    }
  }

  cout << endl;

  return 0;
}
