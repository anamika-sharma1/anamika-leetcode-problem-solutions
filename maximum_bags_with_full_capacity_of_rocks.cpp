class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        int arr[n];
        int i;
        for(i=0;i<n;i++){
            arr[i] = capacity[i] - rocks[i];
        }
        sort(arr,arr+n);
        int x = additionalRocks, count = 0;
        for(i=0;i<n;i++){
            if(arr[i]<=x){
                x = x - arr[i];
                count++;
            }else{
                break;
            }
        }
        return count;
        
    }
};
