class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s=="" && t==""){
            return true;
        }
        int count = 0;
        char c = s[count];
        for(int i=0;i<t.length();i++){
            if(c==t[i]){
                c=s[++count];
            }
            if(count==s.length()){
                return true;
            }
        }
        return false;
    }
};
