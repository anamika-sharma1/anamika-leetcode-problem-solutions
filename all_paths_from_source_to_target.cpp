class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> v;
        queue<vector<int>> q;
        vector<int> r,s;
        int x;
        r.push_back(0);
        q.push(r);
        while(q.empty()!=true){
            r = q.front();
            // cout<<"{ ";
            // for(int i=0;i<r.size();i++){
            //     cout<<r[i]<<" ";
            // }
            // cout<<" }\n";
            q.pop();
            x = r.back();
            if(x == graph.size()-1){
                     v.push_back(r);
            }
            else{
                for(int j = 0; j < graph[x].size(); j++){
                s = r;
                s.push_back(graph[x][j]);
                q.push(s);
                 }
            }
        }

        cout<<v.size();
        return v;
    }
};
