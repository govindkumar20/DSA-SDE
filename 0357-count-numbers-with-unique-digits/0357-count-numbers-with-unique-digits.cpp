class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        //motherfucker ques no use at all
      // to fill first pos we have 9 choice(exclude 0)
      // to fill second pos we have 9 choices( exclude number used in 1st pos)
      // similarly for 3rd pos we have 8 choices 
      // now observe trend ---- 9*9*8
        if(n==0) return 1;
        int count=9,temp=9,ans=10;// for n=2 count=10
        for(int i=0;i<n-1;i++){
            count*=temp;
            ans+=count;
            temp--;
        }
        return ans;
    }
};