/*Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
Example 1:
Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.*/
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int> st;
        vector<bool> marked(n, false);
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (st.empty()) {
                    marked[i] = true;
                } else {
                    st.pop();
                }
            }
        }
        
        while (!st.empty()) {
            marked[st.top()] = true;
            st.pop();
        }
        
        string result = "";
        for (int i = 0; i < n; ++i) {
            if (!marked[i]) {
                result += s[i];
            }
        }
        
        return result;
    }
};