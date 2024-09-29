class Solution {
public:
    int halveArray(vector<int>& nums) {
        int n=nums.size();
        double sum=0;
        for(auto i:nums) sum+=i;
        double half=sum/2;
        multiset<double> s(nums.begin(),nums.end());
        int count=0;
        double currSum=sum;
        while(currSum>half){
         double maxElement=*s.rbegin();
         s.erase(s.find(maxElement));
         double reducedEle=maxElement / 2;
         s.insert(reducedEle);
         currSum-=reducedEle;
         count++;
        }
        return count;
    }
};