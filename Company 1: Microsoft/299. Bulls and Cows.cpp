class Solution {
public:
    string getHint(string secret, string guess) {
        int b=0, a=0;
        map<char, int>mp;
        for(int i=0; i<secret.length(); i++){
            mp[secret[i]]++;
        }
        for(int i=0; i<secret.length(); i++){
            if(secret[i]==guess[i]){
                b++;
                mp[secret[i]]--;
            }
            // else if(mp[guess[i]]!=0){
            //     a++;
            //     mp[guess[i]]--;
            // }
        }
        for(int i=0; i<secret.length(); i++){
            if(secret[i]!=guess[i] && mp[guess[i]]!=0){
                a++;
                mp[guess[i]]--;
            }
        }
        string A=to_string(a);
        string B=to_string(b);
        string ans = B+'A'+A+'B';
        return ans;
    }
};
