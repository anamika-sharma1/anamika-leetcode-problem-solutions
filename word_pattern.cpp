class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<char> v;
        for(int i = 0; i < pattern.size(); i++){
            v.push_back(pattern[i]);
        }
        vector<string> r;
        string a ="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=32){
                a = a + s[i];
            }
            else{
                r.push_back(a);
                a="";
            }
        }
        r.push_back(a);
        if(v.size()!=r.size()){
            return false;
        }
    
        unordered_map<char,string> m1;
        unordered_map<string,char> m2;
        m1[v[0]] = r[0];
        m2[r[0]] = v[0];
        for(int i=1;i<v.size();i++){
            if(m1.find(v[i])!=m1.end()){
                if(m1[v[i]]!=r[i]){
                    return false;
                }
            }
            else if(m2.find(r[i])!=m2.end()){
                if(m2[r[i]]!=v[i]){
                    return false;
                }
            }
            else{
                 m1[v[i]] = r[i]; 
                 m2[r[i]] = v[i]; 
             }
        }
        return true;
    }
};
