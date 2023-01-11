class Solution {
public:
    int countDigits(int num) {
        int x,count=0,y = num;
    
        while(y!=0){
            x = y%10;
            if(num%x==0)count++;
            y = y/10;
        }
        return count;
    }
};
