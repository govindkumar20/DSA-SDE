class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> len(n,1);
        vector<int> cnt(n,1);
        int maxlen=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){  //if its a same sewuence
                    if(len[j]+1>len[i]){
                        len[i]=len[j]+1;
                        cnt[i]=cnt[j];
                    } 
                   else if(len[j]+1==len[i]){ // if its a different sequence
                        cnt[i]+=cnt[j];
                    }
                }
            }
            maxlen=max(maxlen,len[i]);
        }
        int result=0;
        for(int i=0;i<n;i++){
            if(len[i]==maxlen){
                result+=cnt[i];
            }
        }
        return  result;
    }
};