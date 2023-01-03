class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        char a = 'A';
        int count = 0;
        int n = strs.size();
        int m = strs[0].size();
        for(int i=0;i<m;i++){
            a = 'A';
            for(int j=0;j<n;j++){
                if(strs[j][i]<a){
                    count++;
                    break;
                }
                else{
                    a = strs[j][i];
                }
            }
        }
        return count;
    }
};
