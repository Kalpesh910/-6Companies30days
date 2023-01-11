class Solution {
public:
    long long int mod=1e9+7;
    int rev(int num){
        int num2=0;
        while(num>0){
            num2 = (num2*10)+(num%10);
            num/=10;
        }
        return num2;
    }
    int countNicePairs(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int>mp;
        for(int i=0; i<n; i++){
            nums[i]=nums[i]-rev(nums[i]);
            mp[nums[i]]++;
        }
        int ans=0;
        for(auto it: mp){
            ans = ans + ((((long)(it.second) * (long)(it.second - 1)) / 2) % mod);
        }
        return ans%mod;
    }
};
