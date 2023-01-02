class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int>st;
        for(auto it: tokens){
            if(it=="+"){
                long long int a=st.top();
                st.pop();
                long long int b=st.top();
                st.pop();
                long long int c=b+a;
                st.push(c);
            }
            else if(it=="-"){
                long long int a=st.top();
                st.pop();
                long long int b=st.top();
                st.pop();
                long long int c=b-a;
                st.push(c);
            }
            else if(it=="*"){
                long long int a=st.top();
                st.pop();
                long long int b=st.top();
                st.pop();
                long long int c=b*a;
                st.push(c);
            }
            else if(it=="/"){
                long long int a=st.top();
                st.pop();
                long long int b=st.top();
                st.pop();
                long long int c=b/a;
                st.push(c);
            }
            else {
                long long int a=stoi(it);
                st.push(a);
            }
        }
        return st.top();
    }
};
