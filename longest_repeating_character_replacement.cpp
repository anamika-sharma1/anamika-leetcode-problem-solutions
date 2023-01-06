class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> m;
        /*for(int i = 0; i < s.size(); i++){
            m[s[i]]++;
        }
        for(auto x : m){
            cout<<x.first<<" "<<x.second<<endl;
        }*/
        int n = s.size();
        char a;
        int max_freq = INT_MIN,count = 0, j = 0;
        for(int i = 0; i < s.size(); i++){
            m[s[i]]++;
            max_freq = INT_MIN;
            for(auto x : m){
                if(x.second > max_freq){
                    max_freq = x.second;
                    a = x.first;
                }
            }
            if(i+1 - max_freq <= k){
                count = i+1;
            }
            else{
                while(i-j+1 - max_freq > k){
                    max_freq = INT_MIN;
                    m[s[j]]--;
                    j++;
                    for(auto x : m){
                        if(x.second > max_freq){
                            max_freq = x.second;
                            a = x.first;
                         }
                     }
                 }
                 count = max(count, i-j+1);
            }
           // cout<<a<<" "<<max_freq<<"-"<<count<<endl;
        }
        return count;
    }
};
