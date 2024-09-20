class Solution {
public:
    string compressedString(string word) {
        string comp="";
        int i=0,j;
        while(i<word.size()){
            char temp=word[i];
            int count=1;
            for( j=i+1;j<word.size();j++){
                if(word[j]==temp){
                    count++;
                } else{
                    break;
                }
            }
            if(count<=9) comp+=to_string(count)+word[i]; 
            else {
                while(count>9){
                comp+=to_string(9)+word[i];
                count=count-9;
                }
                if(count) comp+=to_string(count)+word[i];
            }
            count=0;
            i=j;
        }
        return comp;
    }
};