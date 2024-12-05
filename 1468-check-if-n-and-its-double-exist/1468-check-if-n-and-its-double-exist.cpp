class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int> m;
        for(int i=0;i<arr.size();i++) m[arr[i]]=i;
        bool flag=false;
        for(int i=0;i<arr.size();i++){
            if(m.find(2*arr[i])!=m.end() && i!=m[2*arr[i]]) {
                flag= true;
        }
        }
        return flag?true:false;
    }
};