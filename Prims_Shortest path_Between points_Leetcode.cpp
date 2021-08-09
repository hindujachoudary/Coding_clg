//https://leetcode.com/problems/min-cost-to-connect-all-points/
//Prims Algo



int minCostConnectPoints(vector<vector<int>>& points) {
        int weight, i, j, n=points.size(), x1, x2, y1, y2, ans=0, cnt=0, d, u, v, dist, cost[10000], vis[10000], count=0;

        vector<pair<int,int>>edges[1000000];
        for(i=0; i<n-1; i++){
            for(j=i+1; j<n; j++){
                x1=points[i][0];
                x2=points[j][0];
                y1=points[i][1];
                y2=points[j][1];
                d=abs(max(x1,x2)-min(x1,x2))+abs(max(y1,y2)-min(y1,y2));
                edges[i].push_back({j,d});
                edges[j].push_back({i,d});
            }
        }
        for(i=0; i<n; i++)
            vis[i]=0;

        for(i=0; i<n; i++)
            cost[i]=INT_MAX;
        cost[0]=0;
        priority_queue<pair<int,int>>pq;
        pq.push({0,0});
        while(!pq.empty() && count < n){
            weight=pq.top().first;
            u=pq.top().second;
            pq.pop();
            if(vis[u]!=1){
                vis[u]=1;
                ans+=-weight;
                count++;
            }
            for(i=0; i<edges[u].size(); i++){
                v=edges[u][i].first;
                dist=edges[u][i].second;
                if(vis[v]==0 && dist < cost[v]){
                     cost[v]=dist;
                     pq.push({-dist,v});
                     // s.remove({cost[v], v});
                     // cost[v]=dist;
                     // s.insert({cost[v], v});
                }

            }
        }

        return ans;
    }



