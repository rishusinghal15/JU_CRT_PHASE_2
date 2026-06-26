#include<iostream>
#include<stack> 
#include<vector>
using namespace std; 

class MinStack {
public:
    stack<int> st1; // all elements insert
    stack<int> st2; // only abhi tkk ka minimum element
    MinStack() {}

    void push(int value) {
        if (st1.size() == 0) {
            st1.push(value);
            st2.push(value);
        } else {
            st1.push(value);
            if (value <= st2.top()) {
                st2.push(value);
            }
        }
    }

    void pop() {
        if (st1.size() == 0) {
            return;
        }
        int ans = st1.top();
        if (ans == st2.top()) {
            st2.pop();
        }
        st1.pop();
    }

    int top() {
        if (st1.size() == 0)
            return -1;

        return st1.top();
    }

    int getMin() {
        if (st2.size() == 0)
            return -1;

        return st2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 int main() {
    MinStack st;

    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);

    cout << "Top Element: " << st.top() << endl;
    cout << "Minimum Element: " << st.getMin() << endl;

    st.pop();
    cout << "\nAfter one pop:" << endl;
    cout << "Top Element: " << st.top() << endl;
    cout << "Minimum Element: " << st.getMin() << endl;

    st.pop();
    cout << "\nAfter another pop:" << endl;
    cout << "Top Element: " << st.top() << endl;
    cout << "Minimum Element: " << st.getMin() << endl;

    st.push(1);
    cout << "\nAfter pushing 1:" << endl;
    cout << "Top Element: " << st.top() << endl;
    cout << "Minimum Element: " << st.getMin() << endl;

    return 0;
}