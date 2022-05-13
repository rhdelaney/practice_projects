class MyQueue {
public:
    stack<int> st;
    stack<int> en;
    MyQueue() {
    }

    void push(int x) {
        while(!st.empty()) {
            en.push(st.top());
            st.pop();
        }
        en.push(x);
        while(!en.empty()) {
            st.push(en.top());
            en.pop();
        }
    }

    int pop() {
        int curr = st.top();
        st.pop();
        return curr;
    }

    int peek() {
        return st.top();
    }

    bool empty() {
        return st.empty() && en.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
