#include "header.h"

/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
  private:
    stack<int> minStack;
    stack<int> secondaryStack;

  public:
    MinStack() {
        minStack.push(INT_MAX);
    }

    void push(int val) {
        secondaryStack.push(val);
        if (val < minStack.top()) {
            minStack.push(val);
        } else {
            minStack.push(minStack.top());
        }
    }

    void pop() {
        secondaryStack.pop();
        minStack.pop();
    }

    int top() {
        return secondaryStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
