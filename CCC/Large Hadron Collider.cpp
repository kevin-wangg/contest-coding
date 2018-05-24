#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
ll find(ll cur, ll curlength, vector<bool> &vis, vector<vector<ll> > &adj, ll &diam)
{
  vis[cur] = true;
  if(curlength == diam / 2){
    return 1;
  }
  ll ways = 0;
  for(ll i = 0; i < adj[cur].size(); i++){
    ll v = adj[cur][i];
    if(vis[v] == false){
      ways += find(v, curlength + 1, vis, adj, diam);
    }
  }
  return ways;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	ll N;
	cin >> N;
	vector<vector<ll> > adj(N, vector<ll> (0));
  vector<ll> incounter(N, 0);
	for(ll i = 0; i < N - 1; i++){
		ll a, b;
		cin >> a >> b;
		adj[a - 1].push_back(b - 1);
		adj[b - 1].push_back(a - 1);
    incounter[a - 1]++;
    incounter[b - 1]++;
	}
	queue<ll> bfs;
  vector<ll> vis(N, -1);
  bfs.push(0);
  vis[0] = 0;
  ll start;
  ll curbig = 0;
  while(!bfs.empty()){
    ll u = bfs.front();
    bfs.pop();
    for(ll i = 0; i < adj[u].size(); i++){
      ll v = adj[u][i];
      if(vis[v] == -1){
        vis[v] = vis[u] + 1;
        bfs.push(v);
        if(vis[v] > curbig){
          curbig = vis[v];
          start = v;
        }
      }
    }
  }
  queue<ll> bfsZ;
  vector<ll> visZ(N, -1);
  bfsZ.push(start);
  visZ[start] = 0;
  ll diam = 0;
  while(!bfsZ.empty()){
    ll u = bfsZ.front();
    bfsZ.pop();
    for(ll i = 0; i < adj[u].size(); i++){
      ll v = adj[u][i];
      if(visZ[v] == -1){
        visZ[v] = visZ[u] + 1;
        bfsZ.push(v);
        if(visZ[v] > diam){
          diam = visZ[v];
          start = v;
        }
      }
    }
  }
  queue<ll> ones;
  for(ll i = 0; i < N; i++){
    if(incounter[i] == 1){
      ones.push(i);
    }
  }
  ll center1 = -1, center2 = -1;
  vector<bool> removed(N, false);
  ll nodesleft = N;
  while(!ones.empty()){
    ll front = ones.front();
    ones.pop();
    nodesleft--;
    removed[front] = true;
    if(nodesleft == 1 and diam % 2 == 0){
      for(ll i = 0; i < N; i++){
        if(removed[i] == false){
          center1 = i;
          break;
        }
      }
      break;
    }
    else if(nodesleft == 2 and diam % 2 == 1){
      for(ll i = 0; i < N; i++){
        if(removed[i] == false){
          if(center1 == -1){
            center1 = i;
          }
          else{
            center2 = i;
            break;
          }
        }
      }
      break;
    }
    for(ll i = 0; i < adj[front].size(); i++){
      ll parent = adj[front][i];
      if(removed[parent] == false){
        incounter[parent]--;
        if(incounter[parent] == 1){
          ones.push(parent);
        }
      }
    }
  }
  ll ans = 0;
  if(diam % 2 == 0){
    vector<ll> subtrees;
    ll total = 0;
    vector<bool> vis(N, false);
    vis[center1] = true;
    for(ll i = 0; i < adj[center1].size(); i++){
      ll v = adj[center1][i];
      ll branch = find(v, 1, vis, adj, diam);
      total += branch;
      subtrees.push_back(branch);
    }
    for(ll i = 0; i < subtrees.size(); i++){
      total -= subtrees[i];
      ans += (subtrees[i] * total);
    }
  }
  else if(diam % 2 == 1){
    ll val1 = 0;
    vector<bool> vis(N, false);
    vis[center1] = true;
    vis[center2] = true;
    for(ll i = 0; i < adj[center1].size(); i++){
      ll v = adj[center1][i];
      if(v != center2){
        ll branch = find(v, 1, vis, adj, diam);
        val1 += branch;
      }
    }
    ll val2 = 0;
    for(ll i = 0; i < adj[center2].size(); i++){
      ll v = adj[center2][i];
      if(v != center1){
        ll branch = find(v, 1, vis, adj, diam);
        val2 += branch;
      }
    }
    ans += (val1 * val2);
  }
  cout << diam + 1 << " " << ans;
  return 0;
}
