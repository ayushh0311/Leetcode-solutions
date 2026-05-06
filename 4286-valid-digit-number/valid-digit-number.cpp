class Solution {
public:
    bool validDigit(int n, int x) {
        string s=to_string(n);
        string t=to_string (x);
        if(t[0]==s[0])return false;
        for(int i=1;i<s.size();i++){
if(t[0]==s[i])return true;
        }  
        return false; 
        }
};