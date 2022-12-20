class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int, int> m;
        queue<int> q;
        int n = rooms.size();
        int arr[n];
        for(int i=0;i<n;i++){
            arr[i]=0;
        }
        int l,x;
        q.push(0);
        arr[0]=1;
        while(q.empty()!=true){
            x = q.front();
            q.pop();
            m[x]++;
            l = rooms[x].size();
            for(int j=0;j<l;j++){
                if(arr[rooms[x][j]]!=1){
                    q.push(rooms[x][j]);
                    arr[rooms[x][j]]=1;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(m.find(i)!=m.end()){
                if(m[i]<=0){
                    return false;
                }
            }
            else{
                return false;
            }
        }

        return true;
    }
};
