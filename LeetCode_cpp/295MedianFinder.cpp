#include <iostream>
#include <vector>
#include <stack>
#include <queue>

class MedianFinder {
public:
    /** initialize your data structure here. */
    std::priority_queue<int,std::vector<int>,std::greater<int>> small_queue;//最小堆
    std::priority_queue<int,std::vector<int>,std::less<int>> big_queue;//最大堆
    MedianFinder() {

    }

    void addNum(int num)
    {
        if(big_queue.empty())
        {
            big_queue.push(num);
            return;
        }
        if(big_queue.size() == small_queue.size())
        {
            if(num < big_queue.top())
                big_queue.push(num);
            else
                small_queue.push(num);
        }
        else if(big_queue.size() > small_queue.size())
        {
            if(num > big_queue.top())
                small_queue.push(num);
            else
            {
                small_queue.push(big_queue.top());
                big_queue.pop();
                big_queue.push(num);
            }
        }
        else if(big_queue.size() < small_queue.size())
        {
            if(num < small_queue.top())
                big_queue.push(num);
            else
            {
                big_queue.push(small_queue.top());
                small_queue.pop();
                small_queue.push(num);
            }
        }
    }

    double findMedian()
    {
        if(big_queue.size() == small_queue.size())
            return (big_queue.top() + small_queue.top()) / 2.0;//除以2.0 保留小数
        else if(big_queue.size() > small_queue .size())
            return big_queue.top();
        else
            return small_queue.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


//测试函数
int main()
{
    MedianFinder M;
    int test[] = {6,10,1,7,99,4,33};
    for(int i = 0; i < 7; i++)
    {
        M.addNum(test[i]);
        std::cout << M.findMedian() << '\n';
    }
    return 0;
}
