class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        vector<int> r1,r2;
        int sum=0;
        for(auto i:nums){
            sum+=i;
            if(i%3==1) r1.push_back(i);
            if(i%3==2) r2.push_back(i);
        }
        sort(r1.begin(),r1.end());
        sort(r2.begin(),r2.end());
        
        if(sum%3==1){
            int temp1=r1.size()>=1?r1[0]:INT_MAX;
            int temp2=r2.size()>=2?r2[0]+r2[1]:INT_MAX;
            sum-=min(temp1,temp2);
        }else if(sum%3==2){
            int temp1=r2.size()>=1?r2[0]:INT_MAX;
            int temp2=r1.size()>=2?r1[0]+r1[1]:INT_MAX;
            sum-=min(temp1,temp2);
        }
        return sum;
    }
};