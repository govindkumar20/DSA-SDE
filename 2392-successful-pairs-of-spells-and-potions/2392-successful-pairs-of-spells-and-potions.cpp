class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();
        vector<int> pairs(n);
        sort(potions.begin(),potions.end());
        for(int i=0;i<n;i++){
           int s=0;
           int e=m-1;
           int temp=m;
           while(s<=e){
            int mid=s+(e-s)/2;
            if((long long)spells[i]*potions[mid]>=success){
                temp=mid; //calculating the first potions[j] which is eligible , so size-temp is the total length which are eligible
                e=mid-1; // if eligible check whether there exist ans eligible no prev to it
            } else s=mid+1;
           
           }
           pairs[i]=m-temp;
        }
        return pairs;
    }
};