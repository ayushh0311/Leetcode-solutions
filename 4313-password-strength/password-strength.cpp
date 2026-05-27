class Solution {
public:
  int val(char ch){
    if(ch>='0' && ch<='9')return 3;
    if(ch>='a' && ch<='z')return 1;
     if(ch>='A' && ch<='Z')return 2;
     return 5;
  }
    int passwordStrength(string password) {
        int n=password.size();
        map<char,int>mp;
        for(int i=0;i<n;i++){
   mp[password[i]]++;
        }

        int ans=0;
        for(auto &it:mp){
            ans=ans+val(it.first);
        }
return ans;
    }
};