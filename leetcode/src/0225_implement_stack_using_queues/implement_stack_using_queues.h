#include <iostream>
#include <queue>
using namespace std;
// 请你仅使用两个队列实现一个后入先出（LIFO）的栈，
// 并支持普通栈的全部四种操作（push、top、pop 和 empty）
class MyStack {
public:
    // queue的基本操作: push,pop,back,front
    std::queue<int> q1;
    std::queue<int> q2;
    int current = 1;
    /* queue是先进先出(并且只能从先进pop)
     * stack是后进先出
     * 设计:
     *   q1负责push,在push前需要把所有变量放到q1
     *   q2负责pop，在pop前需要把所有变量放到q1再pop
     *   stack中top是取后进的元素,利用q2实现
     *   empty
     * */
    MyStack() {}

    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    int pop() {
        int result = q1.front();
        q1.pop();
        return result;
    }
    int top() {
        return q1.front();
    }
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
