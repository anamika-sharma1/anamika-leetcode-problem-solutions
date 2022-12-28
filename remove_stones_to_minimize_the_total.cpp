class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(int i=0;i<piles.size();i++){
            pq.push(piles[i]);
        }
        int x,y;
        for(int i=k;k>0;k--){
            x = pq.top();
            y = floor(x/2);
            x = x - y;
            pq.pop();
            pq.push(x);
        }
        int result=0;
        while(pq.empty()!=true){
            x = pq.top();
            pq.pop();
            result+=x;
        }
        return result;
    }
};
