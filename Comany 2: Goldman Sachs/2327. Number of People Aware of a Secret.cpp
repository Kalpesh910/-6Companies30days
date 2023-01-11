class Solution {
public:
    long long int mod = 1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>vec(n+1, 0);
        vec[1]=1;
        int fo=0;
        int ans=0;
        for(int i=1; i<=n; i++){
            if(vec[i]==0)   continue;
            ans=ans%mod;
            vec[i]=vec[i]%mod;
            ans+=vec[i];
            ans=ans%mod;
            if(i+forget<=n){  
                ans-=vec[i];
                ans=ans%mod;
            }
            for(int j=i+delay; j<i+forget&&j<=n; j++){
                vec[j]+=vec[i];
                vec[j]=vec[j]%mod;
            }
        }
        return ans;
    }
};
