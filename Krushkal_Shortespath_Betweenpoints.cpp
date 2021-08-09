//https://leetcode.com/problems/min-cost-to-connect-all-points/
// Krushkal's Algo
    int parent[1000000], rnk[1000000];
    int find(int x){
        if(x!=parent[x])
            parent[x]=find(parent[x]);
        return parent[x];
    }
    
    void merge(int x, int y){
        int l=find(x);
        int m=find(y);
        if(l!=m){
            if(rnk[l] > rnk[m])
                parent[m]=l;
            else
                parent[l]=m;
            if(rnk[l]==rnk[m])
                rnk[m]++;
        }
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
            
        int i, j, n=points.size(), x1, x2, y1, y2, ans=0, cnt=0, d, u, v;
        vector<pair<int,pair<int,int>>>edges;
        for(i=0; i<n-1; i++){
            for(j=i+1; j<n; j++){
                x1=points[i][0];
                x2=points[j][0];
                y1=points[i][1];
                y2=points[j][1];
                d=abs(max(x1,x2)-min(x1,x2))+abs(max(y1,y2)-min(y1,y2));
                edges.push_back({d,{i, j}});
            }
        }
        
        for(i=0; i<n; i++)
            parent[i]=i, rnk[i]=0;
        sort(edges.begin(), edges.end());
        
        for(i=0; i<edges.size(); i++){
            u=edges[i].second.first;
            v=edges[i].second.second;
            if(cnt<n && find(u) != find(v)){
               ans+=edges[i].first;
               cnt++;
               merge(u,v); 
            }
            if(cnt==n)
                break;
        }
        return ans;
    }
    
    
    
    