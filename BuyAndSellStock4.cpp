//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution {
public:
    int func(vector<int>& prices, int index, int buy, int trans_left, vector<vector<vector<int>>>&dp) {
        //base case
        if (trans_left == 0) return 0;
        if (index == prices.size()) return 0;

        if (dp[index][buy][trans_left] != -1) return dp[index][buy][trans_left];

        //either you can buy
        if (buy == 1) {
            int bought = 0;
            //will you actually buy right now
            bought = -prices[index] + func(prices, index+1, 0, trans_left, dp);
            //or wait it out
            int not_bought = func(prices, index+1, 1, trans_left, dp);
            return dp[index][buy][trans_left] = max(bought, not_bought);
        }
        //or you can sell
        else {
            int sold = 0;
            //either i sell right now
            sold = prices[index] + func(prices, index+1, 1, trans_left-1, dp);
            //or i wait it out
            int not_sold = func(prices, index+1, 0, trans_left, dp);
            return dp[index][buy][trans_left] = max(sold, not_sold);
        }

        return 0;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return func(prices, 0, 1, k, dp);
    }
};
