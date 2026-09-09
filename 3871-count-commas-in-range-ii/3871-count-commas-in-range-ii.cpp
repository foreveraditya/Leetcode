class Solution {
public:
    long long countCommas(long long n) {
        long long lower = 1000;
        int comma = 1;
        long long ans = 0;
        while(lower<=n){
            long long upper = lower*1000-1;
            ans+=(min(upper,n)-lower+1)*comma;
            comma+=1;
            lower = lower*1000;
        }
        return ans;
    }
};