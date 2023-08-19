#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int mod = 1000000007;
void dfs(int  node, vector<int> &vis, vector<vector<int>> &undirected) {
    vis[node] = 1;
    for(auto child : undirected[node]) {
        if(vis[child] == 0) dfs(child, vis, undirected);
    }
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>>directed(n + 1);
    vector<int>inedges(n + 1);
    vector<vector<int>>undirected(n + 1);
    for(int i = 1; i <= n; i++) {
        int cnt; cin >> cnt;
        for(int j = 1; j <= cnt; j++) {
            int adj; cin >> adj;
            inedges[i]++;
            directed[adj].push_back(i);
            undirected[i].push_back(adj);
        }
    }
    vector<int> vis(n + 1);
    dfs(1, vis, undirected);
    queue<int> q;
    vector<int> ans;
    for(int i = 1; i <= n; i++) {
        if(vis[i] == 1 && inedges[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int curr = q.front();
        if(curr == 1) break;
        ans.push_back(curr);
        q.pop();
        for(auto child: directed[curr]) {
            inedges[child]--;
            if(inedges[child] == 0 && vis[child]) {
                q.push(child);
            }
        }
    }
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] <<' ';
    }
}
