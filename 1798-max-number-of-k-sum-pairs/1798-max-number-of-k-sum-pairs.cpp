class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // gonna use two pointer approach
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        int j=n-1;
        int count=0;
        while(i<j){
            if(nums[i]+nums[j]==k){
                i++; j--;
                count++;
            } else if(nums[i]+nums[j]<k){
                i++;
            } else {
                j--;
            }
        }
        return count;
    }
};