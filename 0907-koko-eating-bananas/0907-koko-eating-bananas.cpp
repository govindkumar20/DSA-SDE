class Solution {
public:
    bool isPossible(vector<int>& piles,int k,int h){
        int hours=0;
        for(auto i:piles){
            int temp=i/k;
            hours+=temp;
            if(i%k!=0) hours++;
        }
        return hours<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int e=10000000000;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isPossible(piles,mid,h)) e=mid-1;
            else s=mid+1;
        }
        return s;
    }
};