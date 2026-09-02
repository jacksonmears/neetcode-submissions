class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int mx = 0;
        vector<int> dp(cost.size()+1, INT_MAX);
        dp[0] = 0; dp[1] = 0;
        
        for (int i = 0; i < cost.size(); ++i)
        {
            if (i < cost.size()) dp[i+1] = min(cost[i]+dp[i], dp[i+1]);
            if (i < cost.size()-1) dp[i+2] = min(cost[i]+dp[i], dp[i+2]);
        }
    
        return dp[dp.size()-1]; 
    }
};

