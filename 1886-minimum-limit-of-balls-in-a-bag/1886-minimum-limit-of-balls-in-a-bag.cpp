class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int s=1;
        int e=*max_element(nums.begin(),nums.end());
        while(s<=e){
            int mid=s+(e-s)/2;
            int operations=0;
            for(auto i:nums) operations+=(i-1)/mid;
            if(operations>maxOperations) s=mid+1;
            else e=mid-1;
        }
        return s;
    }
};