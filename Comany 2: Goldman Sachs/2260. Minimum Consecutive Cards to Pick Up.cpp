class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n=cards.size();
        if(n<=1)    return -1;
        map<int, int>mp;
        int sub=n;
        for(int i=0; i<n; i++){
            if(mp.find(cards[i])!=mp.end()){
                sub=min(i-mp[cards[i]], sub);
            }
            mp[cards[i]]=i;
        }
        if(sub==n)  return -1;
        return sub+1;
    }
};
