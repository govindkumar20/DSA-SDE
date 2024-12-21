class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        vector<pair<int,int>> v;
        int sum=0;
        for(auto i:skill) sum+=i;
        int teamSum=sum/(n/2);
        cout<<teamSum;

        map<int,int> m;
        for(int i=0;i<n;i++) m[skill[i]]++;
        //m[skill[0]]--;
        for(int i=0;i<n;i++){
            int num=teamSum-skill[i];
            if(m[skill[i]]>0 && m[num]>0){
                if (skill[i] == num && m[skill[i]] < 2) continue;
                v.push_back({skill[i],num});
                m[skill[i]]--;
                m[num]--;
            }
        }
        cout<<endl;
        cout<<v.size();
        if(v.size()!=(n/2)) return -1;
        long long ans=0;
        for(auto i:v){
            ans+=(i.first*i.second);
        }
        return ans;
    }
};