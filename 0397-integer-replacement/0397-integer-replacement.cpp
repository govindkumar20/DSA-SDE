class Solution {
public:
    int integerReplacement(int n) {
        if(n==INT_MAX) return 32;
        int count=0;
        while(n>1){
            if(n%2==0) n/=2;
            else{
                if((n+1)%4==0 && (n-1)!=2) n++; //we aim to divide as much as possible
                                                //if(n+1) is divisible by 4 go for n++ bcz we can divide in next operation
                                                // edge case if n-1=2 then go for n-- bcz n-- will give 2 which is closer to 1
                else n--;
            }
            count++;
        }
        return count;
    }
};