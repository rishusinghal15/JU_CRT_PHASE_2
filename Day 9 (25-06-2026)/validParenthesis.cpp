#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            // opening
            if (ch == '(' || ch == '[' || ch == '{')
            {
                st.push(ch);
            }
            else
            {
                // closing bracket
                // pre-check -> stack empty
                // agar Stack empty hua jse example: (){}
                // in this case stack will be empty
                if (st.empty())
                {
                    // no match
                    return false;
                }
                if (ch == ')' && st.top() != '(')
                {
                    return false;
                }
                else if (ch == ']' && st.top() != '[')
                {
                    return false;
                }
                else if (ch == '}' && st.top() != '{')
                {
                    return false;
                }
                else
                {
                    // match
                    st.pop();
                }
            }
        }

        // // yhaa prr m galti krta hu and bhul jaata hu
        // if(st.empty()){
        //     // iska mtlb saare bracket cancel out hogye
        //     return true;
        // } else {
        //     // cancel out hogye but still something left
        //     return false;
        // }
        return st.empty();
    }
};

int main()
{
    Solution obj;

    string s;

    cout << "Enter the string: ";
    cin >> s;

    if (obj.isValid(s))
        cout << "Valid Parentheses" << endl;
    else
        cout << "Invalid Parentheses" << endl;

    return 0;
}