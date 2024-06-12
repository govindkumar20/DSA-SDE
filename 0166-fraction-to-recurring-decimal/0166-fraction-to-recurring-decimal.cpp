class Solution {
public:
    string fractionToDecimal(int64_t n, int64_t d) { // overflow ke liye int64_t
        if(n==0) return "0";
        string ans;
        if(n<0 ^ d<0) ans+='-'; // ^ will check if ans sting begin with - or not
        n=abs(n);
        d=abs(d);
        ans+=to_string(n/d);
        if(n%d==0) return ans;
        ans+='.';
        unordered_map<int,int> m;
        for(int64_t r=n%d;r;r%=d){   //if rem is repeating means decimal part is repeating
            if(m.find(r)!=m.end()){
                ans.insert(m[r],"(");  // insert ( at m[r] index // new thing
                ans+=")";
                break;
            }
            m[r]=ans.size();
            r*=10;    // agge division krne ke liye hm rem  ke piche 0 lgate hain
            ans+=to_string(r/d);  // bss mil gya final ans
        }
       return ans; 
    }
};