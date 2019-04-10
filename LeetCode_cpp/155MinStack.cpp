#include <iostream>
#include <stack>

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack()
    {

    }

    void push(int x)
    {
        _data.push(x);
        if(_min.empty())
            _min.push(x);
        else
        {
            if(x > _min.top())
                x = _min.top();
            _min.push(x);
        }
    }

    void pop()
    {
        _data.pop();
        _min.pop();
    }

    int top()
    {
        return _data.top();
    }

    int getMin()
    {
        return _min.top();
    }
private:
    std::stack<int> _data; //数据栈
    std::stack<int> _min; //最小值栈
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
//测试函数

int main()
{
    MinStack minStack;
    minStack.push(-2);
    std::cout << minStack.top() << "\n";
    std::cout << minStack.getMin() << "\n";
    minStack.push(0);
    std::cout << minStack.top() << "\n";;
    std::cout << minStack.getMin() << "\n";
    minStack.push(-3);
    std::cout << minStack.getMin() << '\n';   //--> 返回 -3.
    minStack.pop();
    std::cout << minStack.top() << '\n';      //--> 返回 0.
    std::cout << minStack.getMin() << '\n';  // --> 返回 -2.
    return 0;
}
