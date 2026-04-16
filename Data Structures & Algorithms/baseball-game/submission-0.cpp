class Solution {
public:
    int calPoints(vector<string>& operations) {
        
        stack<int> scores;
        for(auto& it : operations)
        {
            if(it=="+")
            {
                int b = scores.top();
                scores.pop();
                int a = scores.top();
                scores.push(b);
                scores.push(a+b);
            }
            else if(it=="D")
            {
                int a = scores.top();
                scores.push(2*a);
            }
            else if(it=="C")
            {
                scores.pop();
            }
            else
                scores.push(convertToInt(it));
        }

        int sum = 0;
        while(!scores.empty())
        {
            sum+=scores.top();
            scores.pop();
        }

        return sum;
    }

    int convertToInt(string str)
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
            return -num;
        
        return num;
    }
};