/*
Runtime: 16 ms, faster than 97.15% of C++ online submissions for Min Stack.
Memory Usage: 16.2 MB, less than 91.95% of C++ online submissions for Min Stack.
*/

/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.
*/


class MinStack {
public:
    /** initialize your data structure here. */
    MinStack():
    m_p(-1),
    m_min(0)
    {}
    
    void push(const int val) {
        
        const int volume = m_stack.size();
        
        if ( m_min > val || m_p == -1 )
            m_min = val;
        
        if ( m_p + 1 == volume )
        {
            m_stack.push_back(val);
            m_p++;
        }
        else
        {
            m_p++;
            m_stack[m_p] = val;
        }
    }
    
    void pop() 
    {
        if (m_p == -1) return;
        
        m_p--;
        
        if ( m_stack[m_p + 1] != m_min ) return;
        
        m_min = m_stack[0];
        for ( int i = 0; i <= m_p; i++)
        {
            if (m_min > m_stack[i]) m_min = m_stack[i];
        }
    }
    
    int top() 
    {
        return m_stack[m_p];
    }
    
    int getMin() 
    {
        return m_min;
    }
private:
    
    int m_p;
    int m_min;
    vector<int> m_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
