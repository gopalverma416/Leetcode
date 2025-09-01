class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        stack<string> st;
        string temp = "";

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if(ch!=' '){
                temp+=ch;
            }else if(!temp.empty()){
                st.push(temp);
                temp="";
            }
        }
        if(!temp.empty()){
            st.push(temp);
        }
        string result="";
        while(!st.empty()){
            string qwer=st.top();
            st.pop();
            result+=qwer;
            if(!st.empty()){
                result+=" ";
            }
        }
        return result;
    }
};