class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums[0]>=target){
            return 1;
        }
        int i=0,j=0,sum=0,count=INT_MAX,temp=0;
        while(i<nums.size()){
            if(sum<=target){
                sum += nums[i];
                temp++;
            }
            else if(sum > target){
                sum -= nums[j];
                j++;
                temp--;
            }
            if(sum<=target)i++;
            if(sum>=target){
                if(count > temp){
                    count = temp;
                }
            }
            cout<<sum<<" ";
        }
        if(count==INT_MAX)return 0;
        return count;
    }
};
