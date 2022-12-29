class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int> m1,m2;
        for(int i=0;i<nums.size();i++){
            m1[nums[i]]=0;
            m2[nums[i]]=0;
        }
        sort(nums.begin(),nums.end());
        
        int val1,target,m,n;
        vector<int> r;
        vector<vector<int>> result;

        for(int i=0;i<nums.size();i++){
            val1 = nums[i];
            target = 0 - nums[i];
            m = i+1;
            n = nums.size()-1;
            if(m2[val1]==0){
                while(m<n){
                if(m1[nums[m]]==1){
                    m++;
                }
                else if(m1[nums[n]]==1){
                    n--;
                }
                else if(nums[m]+nums[n]==target){
                    r.push_back(nums[m]);
                    r.push_back(nums[n]);
                    r.push_back(val1);
                    m1[nums[m]]=1;
                    m1[nums[n]]=1;
                    m++;
                    n--;
                    result.push_back(r);
                    r.clear();
                }
                else if(nums[m]+nums[n]>target){
                    n--;
                }
                else if(nums[m]+nums[n]<target){
                    m++;
                }
            }
            }    
            m2[val1]=1;
            for(int i=0;i<nums.size();i++){
            m1[nums[i]]=0;
        }
        }
        return result;
    }
};
