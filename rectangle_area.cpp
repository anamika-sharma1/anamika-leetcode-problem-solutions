class Solution {
public:
    long long computeArea(long long ax1, long long ay1, long long ax2, long long ay2, long long bx1, long long by1, long long bx2, long long by2) {
        long long area;
        area = ((ax2 - ax1) * (ay2 - ay1)) + ((bx2 - bx1) * (by2 - by1));
     long long l = (min(ax2,bx2) - max(ax1,bx1));
     long long b = (min(ay2,by2) - max(ay1,by1));
     cout << l << " " << b<<"\n";
     if(l>0 && b>0){
         area = area - (l*b);
     }
     return area;
    }
};