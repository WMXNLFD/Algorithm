#include <stack>
#include <iostream>

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue()
    {

    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        std::stack<int> temp_stack;
        while(!_data.empty())
        {
            temp_stack.push(_data.top());
            _data.pop();
        }
        temp_stack.push(x);
        while(!temp_stack.empty())
        {
            _data.push(temp_stack.top());
            temp_stack.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int x = _data.top();
        _data.pop();
        return x;
    }

    /** Get the front element. */
    int peek()
    {
        return _data.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return _data.empty();
    }
private:
    std::stack<int> _data;
};


/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


 //²âÊÔº¯Êý
 int main()
 {
    MyQueue Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    std::cout << Q.peek();
    Q.pop();
    std::cout << Q.peek();
    Q.push(5);
    std::cout << Q.peek();
    return 0;
 }
