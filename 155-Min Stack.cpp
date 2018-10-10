/*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.

Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.*/

// 包含min函数的栈

// 关键是要找到一种方法来追踪栈中的最小元素。

// #1
// 双栈解法：
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        s1.push(x);
        if (s2.empty() || x <= s2.top()) 
            s2.push(x);
    }
    
    void pop() {
        if(s1.size())
        {
            if (s2.size() && s1.top() == s2.top()) 
                s2.pop();
            s1.pop();
        }
    }
    
    int top() {
        if(s1.size())
            return s1.top();
        else
            return -1;
    }
    
    int getMin() {
        if(s2.size())
            return s2.top();
        else
            return -1;
    }
    
private:
    stack<int> s1, s2;
};

// #2
// stack+1个变量的解法：
// 思路：
// 初始化为min_val整型最小值，然后如果需要进栈的数字小于等于当前最小值min_val，那么将min_val压入栈，并且将min_val更新为当前数字。在出栈操作时，先将栈顶元素移出栈，
// 再判断被移除的栈顶元素是否和min_val相等，相等的话我们将min_val更新为新栈顶元素，再将新栈顶元素移出栈即可
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        min_val = INT_MAX;
    }
    
    void push(int x) {
        if (x <= min_val) {
            st.push(min_val);
            min_val = x;
        }
        st.push(x);
    }
    
    void pop() {
        int t = st.top(); st.pop();
        if (t == min_val) {
            min_val = st.top(); st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_val;
    }
private:
    int min_val;
    stack<int> st;
};

// My solution:
// 基于stack + multiset的实现：
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        min_elements.insert(x);
    }
    
    void pop() {
        if(s.size())
        {
            min_elements.erase(min_elements.find(s.top()));
            s.pop();
        }
    }
    
    int top() {
        if(s.size())
            return s.top();
        else
            return -1;
    }
    
    int getMin() {
        if(min_elements.size())
            return *min_elements.begin();
        else
            return -1;
    }
    
private:
    multiset<int> min_elements;
    stack<int> s;
};





// original template
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        
    }
    
    void pop() {
        
    }
    
    int top() {
        
    }
    
    int getMin() {
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */