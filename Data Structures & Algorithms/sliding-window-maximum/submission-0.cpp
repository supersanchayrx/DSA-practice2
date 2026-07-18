class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        //DEQUE APPROACH
        deque<int> dq;
        vector<int> answers;

        //current i is where the window ends
        //the start of this window would be i-k+1
        //0 1 2 3 4 5 6 7
        //^   ^
        //for i = 2 and k = 3
        //staring of this window or i and k values above would be i-k+1 = 2-3+1 = 0
        //now if we move i to right by one,
        //anything which was i-k+1 or lesser is not in this window
        //since we're moving by 1 we can just check for == i-k //having < wouldn't be making a difference
        for(int i=0; i<nums.size(); i++)
        {
            if(!dq.empty() && dq.front()<=i-k) // same as dq.front()<=i-k
                dq.pop_front(); //this clears out the not in window elements from dq
            //now for greater element check
            while(!dq.empty() && nums[dq.back()]<nums[i]) // we clear out all elements that are smaller
                dq.pop_back();

            // then finally add this element to queue
            dq.push_back(i);

            //check to process atleast k elements 
            if(i-k>=-1)
                answers.push_back(nums[dq.front()]);
            
        }

        return answers;
    }
};
