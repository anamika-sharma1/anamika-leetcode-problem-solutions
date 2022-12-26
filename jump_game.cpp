class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1){
            return true;
        }
        int x,i,m;
        int visited[nums.size()];
        for(i=0;i<nums.size();i++){
            visited[i]=0;
        }
        stack<int> s;
        s.push(0);
        while(s.empty()!=true){
            x = s.top();
            s.pop();
            visited[x]=1;
            if(x==nums.size()-1){
                return true;
            }
            for(i=1;i<=nums[x];i++){
                m = x + i;
                if(m<=nums.size()-1){
                    if(visited[m]==0){
                    s.push(m);
                    }
                }
            }
        }
        return false;      
    }
};
