class Solution {
public:
    int numberOfSubstrings(string s) {
       
        // Solution 1: 
        // int ans=0;
       //  int i=0, j=0, n=s.length();
       //  map<char, int>mp;
       //  set<char>se;
       //  int t = j;
       //  while(i<n-2){
       //      if(se.size()==3){
       //          ans+=(n-t);
       //          mp[s[i]]--;
       //          if(mp[s[i]]==0){
       //              se.erase(s[i]);
       //          }
       //          i++;
       //          continue;
       //      }
       //      t=i;
       //      while(j<n && se.size()<3){
       //          se.insert(s[j]);
       //          mp[s[j]]++;
       //          t=j;
       //          j++;
       //      }
       //      if(se.size()==3){
       //          ans+=(n-t);
       //      }
       //      mp[s[i]]--;
       //      if(mp[s[i]]==0){
       //          se.erase(s[i]);
       //      }
       //      i++;
       //  }
        //  return ans;
        
        //  Solution 2:
        int ans=0, a=-1, b=-1, c=-1;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='a')   a=i;
            else if(s[i]=='b')  b=i;
            else    c=i;
            int p=min(a,min(b,c));
            if(p==-1)   continue;
            ans+=(p+1);
        }
        return ans;
    }
};
