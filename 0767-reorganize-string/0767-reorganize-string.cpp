class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>>pq;// max_heap;
        unordered_map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        for(auto it: mpp){
            pq.push({it.second,it.first});
        }
        string str(pq.top().first,pq.top().second);
        char lst = pq.top().second;
        pq.pop();
        while(!pq.empty() && pq.top().first>1){
            int n = pq.top().first;
            if(n==str.size()){
                str+=pq.top().second;
                n--;
            }
            for(int i=0;i<str.size()-1 && n;i++){
                if(str[i]==str[i+1]){
                    str.insert(str.begin()+i+1,pq.top().second);
                    n--;
                    i++;
                }
            }
            for(int i=0;i<str.size() && n;i++){
                if(str[i]==lst){
                    str.insert(str.begin()+i+1,pq.top().second);
                    n--;
                    i++;
                }
            }
            lst = pq.top().second;
            pq.pop();
        }
        int check = 1;
        while(!pq.empty() && pq.top().first==1){
            int cnt = 0;
            for(int i=0;i<str.size()-1;i++){
                if(str[i] == str[i+1]){
                    str.insert(str.begin()+i+1,pq.top().second);
                    cnt++;
                    break;
                }
            }
            if(cnt==0) str+=pq.top().second;
            pq.pop();
        }
        cout<<str;
        for(int i=0;i<str.size()-1;i++){
            if(str[i]==str[i+1] ) return "";
        }
        
        return str;
    }
};