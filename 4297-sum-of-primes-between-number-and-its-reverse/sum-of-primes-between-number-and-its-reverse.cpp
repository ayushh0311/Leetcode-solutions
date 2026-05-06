class Solution {
public:
    bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i *i<=n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

    int sumOfPrimesInRange(int n) {
         string s=to_string(n);
         int sm=0;
         reverse(s.begin(),s.end());
         int m=stoi(s);
         for(int i=min(n,m);i<=max(n,m);i++){
            if(isPrime(i)){
                sm=sm+i;
            }
         }    
         return sm;   
    }
};