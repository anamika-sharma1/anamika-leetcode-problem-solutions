class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char,int> m;

        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        string substring = "";
        int length = 0,flag = 0; 
        int start = 0;
        for(int i=0;i<s.size();i++){
            if(m[s[i]] > 0 && m[s[i]] < k){
                substring = s.substr(start,i-start);
                length = max(length, longestSubstring(substring, k));
                start = i+1;
                flag = 1;
            }
        }
        if(flag == 0){
            return s.length();
        }
        else{
            return max(length, longestSubstring(s.substr(start, s.size()-start), k));
        }   
    }
};
