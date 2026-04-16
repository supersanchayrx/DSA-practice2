class Solution {
public:
    stack<int> buffer;
    int evalRPN(vector<string>& tokens) {
        
        for(auto& it : tokens)
        {
            if(it=="+")
            {
                int a = GetBufferValues('a');
                int b = GetBufferValues('b');

                buffer.push(a+b);
            }
            else if(it == "-")
            {
                int a = GetBufferValues('a');
                int b = GetBufferValues('b');

                buffer.push(a-b);
            }
            else if(it =="*")
            {
                int a = GetBufferValues('a');
                int b = GetBufferValues('b');

                buffer.push(a*b);
            }
            else if (it =="/")
            {
                int a = GetBufferValues('a');
                int b = GetBufferValues('b');

                buffer.push(a/b);
            }
            else
            {
                buffer.push(ConvertToInt(it));
            }
        }

        return buffer.top();
        
    }

    int GetBufferValues(char ch = 'a')
    {
        if(ch == 'a')
        {
            int b = buffer.top();
            buffer.pop();
            int a = buffer.top();
            buffer.pop();
            buffer.push(b);
            return a;
        }

        int b = buffer.top();
        buffer.pop();
        return b;
    }

    int ConvertToInt(string str)
    {
        int num = 0;
        bool isNegative = false;
        for(auto& s : str)
        {
            if(s=='-')
            {
                isNegative = true;
                continue;
            }
                
            int n = s-'0';
            num=num*10 + n;
        }

        if(isNegative)
            return (-num);
        
        return num;
    }

    
};
