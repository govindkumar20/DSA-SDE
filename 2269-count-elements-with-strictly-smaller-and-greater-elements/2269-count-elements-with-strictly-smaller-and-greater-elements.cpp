class Solution {
public:
    int countElements(vector<int>& nums) {
      int maxi=*max_element(nums.begin(),nums.end());
      int mini=*min_element(nums.begin(),nums.end());
      int n=nums.size();
      int count=0;
      for(int i=0;i<n;i++){
        if(nums[i]>mini && nums[i]<maxi) count++;
      }
      return count;
        
    }
};