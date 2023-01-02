class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long int ans=0, sum=0;
        for(int i=0; i<nums.size(); i++){
            ans+=nums[i]*i;
            sum+=nums[i];
        }
        long long int t = ans;
        int i=nums.size()-1, size=nums.size();
        while(i>0){
            t = t+sum-nums[i]*size;
            ans = max(ans, t);
            i--;
        }
        return ans;
    }
};
