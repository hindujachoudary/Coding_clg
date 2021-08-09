class Solution {
public:
    
    int vis=0, n;
    vector<string> dfs(string x, vector<string>vec, map<string, vector<string>>m){
        vec.push_back(x);
        vis++;     
        if(vis==n)
            return vec;
        sort(m[x].begin(),m[x].end());
        return dfs(m[x][0], vec, m);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        n = tickets.size();
        int i;
        set<string>s;
        map<string, vector<string>>m;
        for(i = 0; i < tickets.size(); i++){
            m[tickets[i][0]].push_back(tickets[i][1]);
            s.insert(tickets[i][0]);
            s.insert(tickets[i][1]);
        }
        n = s.size();
        //cout<<n<<endl;
        vector<string>vec;
        return dfs("JFK",vec,m); 
    }
};