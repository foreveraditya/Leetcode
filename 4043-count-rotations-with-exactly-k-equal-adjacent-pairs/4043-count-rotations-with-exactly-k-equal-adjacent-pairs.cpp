class Solution {
public:
    int countRotations(string s, int k) {
        int cnt = 0;
            int n = s.size();
            while(n--){
            reverse(s.begin(),s.end());
            reverse(s.begin(),s.end()-1);
            int sum = 0;
            for(int i=0;i<s.size()-1;i++){
                if(s[i]==s[i+1]) sum++;
            }
            if(sum==k) cnt++;
            
            }
        
        return cnt;
        }
};