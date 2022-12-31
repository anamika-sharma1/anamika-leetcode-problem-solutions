class myComp1{
    public:
    bool operator()(vector<int> const &a, vector<int> const &b){
        if(a[1]==b[1]){
            return a[2]>b[2];
        }
        return a[1]>b[1];
    }
};

class myComp2{
    public:
    bool operator()(vector<int> const &a, vector<int> const &b){
        return a[0]>b[0];
    }
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>> tasks) {
        priority_queue<vector<int>, vector<vector<int>>, myComp1> pq1;
        priority_queue<vector<int>, vector<vector<int>>, myComp2> pq2,test;
        vector<int> r,s;
        long long x;
        int flag = 0;
        for(int i=0;i<tasks.size();i++){
            r.push_back(tasks[i][0]);
            r.push_back(tasks[i][1]);
            r.push_back(i);
            pq2.push(r);
            r.clear();
        }
        r = pq2.top();
        pq2.pop();
        pq1.push(r);
        x = r[0];
        while(pq2.empty()!=true && pq2.top()[0]<=x){
                r = pq2.top();
                pq2.pop();
                pq1.push(r);
         }
        while(pq1.empty()!=true){
            r = pq1.top();
            pq1.pop();
            s.push_back(r[2]);
            x = x + (long long)r[1];
            while(pq2.empty()!=true && pq2.top()[0]<=x){
                flag = 1; 
                r = pq2.top();
                pq2.pop();
                pq1.push(r);
            }
            if(flag == 0 && pq1.empty()==true){
                if(pq2.empty()!=true){
                    r = pq2.top();
                    pq2.pop();
                    pq1.push(r);
                    x = r[0];
                    while(pq2.empty()!=true && pq2.top()[0]<=x){ 
                        r = pq2.top();
                        pq2.pop();
                        pq1.push(r);
                         }   
                }
            }
            flag = 0;
        }
        return s;
    }
};
