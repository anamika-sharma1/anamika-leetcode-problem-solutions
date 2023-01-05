class mycomp{
    public:
    bool operator()(vector<int> &p1, vector<int> &p2){
        return p1[1] > p2[1];
    }
};
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        priority_queue<vector<int>, vector<vector<int>>, mycomp> pq;
        for(int i=0;i<points.size();i++){
            pq.push(points[i]);
        }
        vector<int> v;
        v = pq.top();
        int xend = v[1];
        int count = 1;
        pq.pop();
        while(pq.empty()!=true){
            v = pq.top();
            if(v[0] > xend){
                count++;
                xend = v[1];
            }
            pq.pop();
        }
        return count;
    }
};
