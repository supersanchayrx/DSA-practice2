class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //std::reverse(tokens.begin(),tokens.end());

        stack<int> nums;
        
        for(auto& it : tokens)
        {
            if(it=="+")
            {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                nums.push(a+b);
            }
            else if(it=="*")
            {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                nums.push(a*b);
            }
            else if(it=="-")
            {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                nums.push(b-a);
            }
            else if(it=="/")
            {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                nums.push(b/a);
            }
            else
            {
                int num = convertToInt(it);
                nums.push(num);
            }
        }

        return nums.top();
    }

    int convertToInt(string number)
    {
        int ans = 0;
        bool isNegative = false;
        for(auto& it : number)
        {
            if(it=='-')
            {
                isNegative = true;
                continue;
            }

            int num = it-'0';
            ans=ans*10 + num;
        }

        if(isNegative)
            return -ans;
        
        return ans;
    }
};
