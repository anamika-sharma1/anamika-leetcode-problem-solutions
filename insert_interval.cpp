class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> result;
        if(intervals.size()==0){
            result.push_back(newInterval);
            return result;
        }

        int x = newInterval[0];
        int y = newInterval[1];

        int m = intervals[0][0],i=0,j=0;
        if(m>x){
int x1 = intervals[j][0], y1 = intervals[j][1], final_y=0, next_index=0;
        if(result.empty()!=true){
            result.pop_back();
        }
        vector<int> r;
        r.push_back(x);
        if(y<x1){
            r.push_back(y);
            result.push_back(r);
        }
        else{
            while(j<intervals.size()){
            if(y<=y1){
                final_y = y1;
                next_index = j+1;
                break; 
            }
            else if(y>y1 && j!=intervals.size()-1){
                 j++;
                 x1 = intervals[j][0];
                 y1 = intervals[j][1];
                 if(y<x1){
                     final_y = y;
                     next_index = j;
                     break;
                 }
                 else if(y==x1){
                     final_y = y1;
                     next_index = j+1;
                     break;
                 }
             }
             else if(y>y1 && j==intervals.size()-1){
                 final_y = y;
                 next_index = j+1;
                 break;  
             }
        }
        r.push_back(final_y);
        result.push_back(r);
        }
        
        while(next_index<intervals.size()){
            result.push_back(intervals[next_index]);
            next_index++;
        }
        }
        else{
            vector<int> r;
            while(m<=x && i!=intervals.size()-1){
                j=i;
                result.push_back(intervals[i]);
                i++;
                m = intervals[i][0];
             }
             int final_y=0, next_index=0;
             if(i==intervals.size()-1){
                 if(x>intervals[i][0]){
                     if(x<=intervals[i][1]){
                        final_y = y>intervals[i][1]?y:intervals[i][1];
                        r.push_back(intervals[i][0]);
                        r.push_back(final_y);
                        result.push_back(r);
                        return result;
                     }
                     else if(x>intervals[i][1]){
                         result.push_back(intervals[i]);
                         result.push_back(newInterval);
                         return result;
                     }
                 }
                 else if(x==intervals[i][0]){

                 }
             }
             int x1 = intervals[j][0], y1 = intervals[j][1];
        if(result.empty()!=true){
            result.pop_back();
        }
        if(x<=y1){
            r.push_back(x1);
        }
        else{
            r.push_back(x1);
            r.push_back(y1);
            result.push_back(r);
            r.clear();
            r.push_back(x);
        }

        while(j<intervals.size()){
            if(y<=y1){
                final_y = y1;
                next_index = j+1;
                break; 
            }
            else if(y>y1 && j!=intervals.size()-1){
                 j++;
                 x1 = intervals[j][0];
                 y1 = intervals[j][1];
                 if(y<x1){
                     final_y = y;
                     next_index = j;
                     break;
                 }
                 else if(y==x1){
                     final_y = y1;
                     next_index = j+1;
                     break;
                 }
             }
             else if(y>y1 && j==intervals.size()-1){
                 final_y = y;
                 next_index = j+1;
                 break;  
             }
        }

        r.push_back(final_y);
        result.push_back(r);
        while(next_index<intervals.size()){
            result.push_back(intervals[next_index]);
            next_index++;
        }

        return result;
        }
        return result;
    }
};
