class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int mx = nums[0], sm = 0;

        for (int n : nums)
        {
            sm += n;
            mx = max(mx, sm);
            sm = max(sm, 0);
        }

        return mx;
    }
};

