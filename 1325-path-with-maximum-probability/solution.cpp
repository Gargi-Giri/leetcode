class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>>graph(n);
        for(int i=0;i<edges.size();++i){
            int u=edges[i][0];
            int v=edges[i][1];
            double prob=succProb[i];
            graph[u].emplace_back(v,prob);
            graph[v].emplace_back(u,prob);
        }
        priority_queue<pair<double,int>> pq;
        vector<double> maxProb(n,0.0);
        maxProb[start_node]=1.0;
        pq.push({1.0,start_node});
        while(!pq.empty()){
            auto[currProb,u]=pq.top();
            pq.pop();
            if(u==end_node){
                return currProb;
            }
            for(auto& [v,prob]:graph[u]){
                double newProb=currProb*prob;
                if(newProb>maxProb[v])
                {
                    maxProb[v]=newProb;
                    pq.push({newProb,v});
                }
           }
        }
        return 0.0;
    }
};
