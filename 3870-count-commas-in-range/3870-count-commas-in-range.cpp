class Solution {
public:
    int countCommas(int n) {
        int digit = 0;
        int x = n;
        while(x){
            digit++;
            x/=10;
        }
        if(digit<4) return 0;
        return n-999;
    }
};