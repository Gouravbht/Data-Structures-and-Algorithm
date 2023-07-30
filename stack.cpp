#include<iostream>
using namespace std;
class Stack{
    private:
    int* array;
    int size;
    int top;

    public:
    Stack(int size){
        this->size = size;
        array = new int[size];
        top = -1;
    }

    void push(int value){
        if(top ==size -1){
            cout<<"Stack is full"<<endl;
        }
        top++;
        array[top] = value;
    }
    int pop(){
        if(top == -1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        int value = array[top];
        top--;
        return value;
    }
    int peek(){
        if(top == -1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return array[top];
    }
    bool isEmpty(){
        return top == -1;
    }

    bool isFull(){
        return top == size -1;
    }

    ~Stack(){
        delete[] array;
    }
};

int main(){
    Stack stack(10);
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout<<"top element "<<stack.peek()<<endl;
    int value = stack.pop();
    cout<<"popped element "<<value<<endl;
    if(stack.isEmpty()){
        cout<<"Stack is empty "<<endl;
    }else{
        cout<<"Stack is not empty "<<endl;

    }
    return 0;
}
