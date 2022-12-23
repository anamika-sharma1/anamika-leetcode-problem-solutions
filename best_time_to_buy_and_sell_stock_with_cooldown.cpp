class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int has1_sell1 = 0;
        int has1_donothing = -prices[0];
        int has0_buy1 = -prices[0];
        int has0_donothing = 0;
        int x = prices.size(),i;
        for(i=1;i<x;i++){
            has1_donothing = has1_donothing > has0_buy1 ? has1_donothing : has0_buy1;
            has0_buy1 = -prices[i]+has0_donothing;
            has0_donothing = has0_donothing > has1_sell1 ? has0_donothing : has1_sell1;
            has1_sell1 = prices[i] + has1_donothing;
        }

        return has1_sell1 > has0_donothing ? has1_sell1 : has0_donothing;

    }
};
