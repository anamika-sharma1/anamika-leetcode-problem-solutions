class mycomp{
    public:
    bool operator()(vector<int> const &v1, vector<int> const &v2){
        return v1[0] < v2[0];
    }
};
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        unordered_map<int,int> m;
        priority_queue<vector<int>, vector<vector<int>>, mycomp> pq;
        vector<int> v;
        int countn = 0, countz = 0, maxdiff = INT_MIN,cg,cc,ci;
        for(int i=0;i<gas.size();i++){
            m[i] = gas[i]-cost[i];
        }
        for(int i = 0;i<gas.size();i++){
            if(m[i]<0){
                countn++;
            }
            else if(m[i]==0){
                countz++;
            }
             v.push_back(m[i]);
             v.push_back(gas[i]);
             v.push_back(cost[i]);
             v.push_back(i);
             pq.push(v);
             v.clear();
        }
        if(countn == gas.size())return -1;
        if(countz == gas.size()) return 0;
        
        int x,y;
      //  cout<<cg<<" "<<cc<<" "<<ci;
      while(pq.empty()!=true){
          v = pq.top();
          pq.pop();
          cg = v[1];
          cc = v[2];
          ci = v[3];
          x = ci;
          if(ci == gas.size()-1){
            cg = cg - cost[ci] + gas[0];
            cc = cost[0];
            ci = 0;
          //  cout<<ci<<" "<<cg<<" "<<cc<<"\n";
        }
        else{
            y = ci+1;
            cg = cg - cost[ci] + gas[y];
            cc = cost[y];
            ci = y;
           // cout<<ci<<" "<<cg<<" "<<cc<<" ";
        }
        while(cg >= cc && ci!=x){
            if(ci == gas.size()-1){
                cg = cg - cost[ci] + gas[0];
                cc = cost[0];
                ci = 0;
              //  cout<<ci<<" "<<cg<<" "<<cc<<"\n";
            }
            else{
                y = ci+1;
                cg = cg - cost[ci] + gas[y];
                cc = cost[y];
                ci = y;
                //cout<<ci<<" "<<cg<<" "<<cc<<"\n";
            }
        }
        if(ci==x){
            return x;
        }
      }
      return -1;
    }
};
