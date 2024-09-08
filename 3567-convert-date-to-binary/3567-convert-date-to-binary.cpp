class Solution {
public:
    string toBinary(int num){
        if(num==0) return "0";
        string binary="";
        while(num>0){
            binary=(num%2==0?"0":"1")+binary;
            num/=2;
        }
        return binary;

    }

    string convertDateToBinary(string date) {
        string year=date.substr(0,4);
        string month=date.substr(5,2);
        string day=date.substr(8,2);
        string ans="";
        ans=toBinary(stoi(year))+"-"+toBinary(stoi(month))+"-"+(toBinary(stoi(day)));
        return ans;
    }
};