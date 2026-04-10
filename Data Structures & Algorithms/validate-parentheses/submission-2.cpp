class Solution {
public:
    bool isValid(string s) {
        
        stack<char> brackets;

        for(auto& i : s)
        {
            if(i=='(' || i=='{' || i=='[')
                brackets.push(i);
            else
            {
                if(brackets.size()==0)
                    return false;
                    
                if(i==')')
                {
                    if(brackets.top()=='(')
                    {
                        brackets.pop();
                        continue;
                    }
                    return false;
                }
                else if(i=='}')
                {
                    if(brackets.top()=='{')
                    {
                        brackets.pop();
                        continue;
                    }
                    return false;
                }
                else if(i==']')
                {
                    if(brackets.top()=='[')
                    {
                        brackets.pop();
                        continue;
                    }
                    return false;
                }
            }
        }

        if(brackets.size()!=0)
            return false;

        return true;
    }
};
