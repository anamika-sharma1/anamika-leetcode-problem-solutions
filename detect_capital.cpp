class Solution {
public:
    bool detectCapitalUse(string word) {
        int flag = 1;
        char a = word[0];
        char b;
        if(a<97){
            b = word[1];
            if(b<97){
                flag = 0;
            }
        }
        if(flag == 0){
            for(int i=2;i<word.size();i++){
                if(word[i]>=97){
                    return false;
                }
            }
        }
        else{
            for(int i=1;i<word.size();i++){
                if(word[i]<97){
                    return false;
                }
            }         
        }
        return true;
        
    }
};
