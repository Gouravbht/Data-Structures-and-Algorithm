#include <iostream>
#include <queue>

class Stack {
private:
    std::queue<int> queue1;
    std::queue<int> queue2;

public:
    void push(int value) {
        // Move all elements from queue1 to queue2
        while (!queue1.empty()) {
            queue2.push(queue1.front());
            queue1.pop();
        }

        // Push the new value to queue1
        queue1.push(value);

        // Move all elements back to queue1
        while (!queue2.empty()) {
            queue1.push(queue2.front());
            queue2.pop();
        }
    }

    void pop() {
        if (!queue1.empty()) {
            queue1.pop();
        }
    }

    int top() {
        if (!queue1.empty()) {
            return queue1.front();
        }
        return -1; // Stack is empty
    }

    bool empty() {
        return queue1.empty();
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top element: " << stack.top() << std::endl;

    stack.pop();
    stack.pop();

    std::cout << "Top element after pops: " << stack.top() << std::endl;

    return 0;
}
