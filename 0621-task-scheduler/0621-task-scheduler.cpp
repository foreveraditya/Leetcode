class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mpp;
        for(int i=0;i<tasks.size();i++) mpp[tasks[i]]++;
        priority_queue<int>pq;
        for(auto it: mpp){
            pq.push(it.second);
        }
        int cnt = 0;
        while(!pq.empty()){
            vector<int>temp;
            int x = n+1;
            while(!pq.empty() && x>0){
                temp.push_back(pq.top()-1);
                x--;
                pq.pop();
            }
            for(int i=0;i<temp.size();i++) {
                if(temp[i]!=0)pq.push(temp[i]);
            }
            if(pq.empty()) cnt += temp.size();
            else cnt+=n+1;
        }
        return cnt;
    }
};