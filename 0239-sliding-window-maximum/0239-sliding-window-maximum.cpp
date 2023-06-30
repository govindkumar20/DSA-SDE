class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      deque <int> dq;
      vector<int> ans;
      for(int i=0;i<k;i++)              // for 1st k elements
      {
         while(!dq.empty() && dq.back()<nums[i])
         {
             dq.pop_back();
         }

          dq.push_back(nums[i]);
          
      } 
       ans.push_back(dq.front());
      for(int i=k;i<nums.size();i++)               // for rest of the elements
      {
          if(dq.front()==nums[i-k]) dq.pop_front();   //if element of prev subarray is present then we have to remove it bcz it is of no use for next subarray
           while(!dq.empty() && dq.back()<nums[i])
         {
             dq.pop_back();
         }

          dq.push_back(nums[i]);
          ans.push_back(dq.front());
      }
      return ans;
    }
};