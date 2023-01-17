class Solution {
public:
    int minFlipsMonoIncr(string s) {
        queue<pair<int,int>> q;
        int count=0, count_0to1=0, count_1to0=0, x=0, y=0, k=0, i=0;
        pair<int,int> p;
        if(s[0]=='1'){
            count++;
        }
        for(int i=1;i<s.size();i++){
            if(s[i]=='1'){
                count++;
            }
            if(s[i]=='0' && s[i-1]=='1'){
                q.push(make_pair(i,count));
                count=0;
            }
        }
        if(q.empty()!=true){
            while(q.empty()!=true){
                p = q.front();
                x = p.first;
                y = p.second;
                q.pop();
                count = 0;
                    k = count_1to0;
                    count_1to0 = count_1to0 + y;
                    if(q.empty()==true){break;}
                    else{
                        p = q.front();
                        count = p.first - p.second - x;
                        if(count_0to1 + count < k + count){
                            count_0to1 = count_0to1 + count;
                        }
                        else{
                            count_0to1 = k + count;
                        }
                    }
             }
             count = 0;
             if(x!=s.size()-1){
                 i = x;
                 while(i<s.size()){
                     if(s[i]=='0'){
                         count++;
                         i++;
                     }
                     else{
                         break;
                     }
                 }
                if(count_0to1 + count < k + count){
                    count_0to1 = count_0to1 + count;
                }
                else{
                    count_0to1 = k + count;
                }
             }
             else{
                 if(count_0to1 + 1 < k + 1){
                    count_0to1 = count_0to1 + 1;
                }
                else{
                    count_0to1 = k + 1;
                }
             }
        }
        return count_0to1 < count_1to0 ? count_0to1 : count_1to0;        
    }
};
