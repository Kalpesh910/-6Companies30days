class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 1);
        vector<int>hash(n);
        int lastindex=0;
        int maxi=1;
        sort(nums.begin(), nums.end());
        for(int i=1; i<n; i++){
            hash[i]=i;
            for(int prev=0; prev<i; prev++){
                if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(maxi < dp[i]){
                maxi=dp[i];
                lastindex=i;
            }
        }
        vector<int>ans;
        ans.push_back(nums[lastindex]);
        while(hash[lastindex]!=lastindex){
            lastindex = hash[lastindex];
            ans.push_back(nums[lastindex]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
