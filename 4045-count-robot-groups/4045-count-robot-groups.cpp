class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
       for(int i=0;i<speed.size()-1;i++){
        if(position[i+1]-position[i]<=distance){
            speed[i] = -1;
            position[i] = -1;
        }
       }
       int mini = INT_MAX;
       int cnt = 1;
       for(int i=speed.size()-1;i>=0;i--){
        if(speed[i]==-1) continue;
        if(mini == INT_MAX) mini = speed[i];
        else if(mini<speed[i]){
            continue;
        }
        else{
            mini = speed[i];
            cnt++;
        }
       }
       return cnt; 
    }
};