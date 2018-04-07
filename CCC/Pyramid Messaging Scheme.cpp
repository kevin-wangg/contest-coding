#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>

using namespace std;

int main() 
{
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int oldtime = 0;
    string start;
    map<string, vector<string> > adj;
    for(int i = 0; i < n / 2; i++){
      string first, second;
      cin >> first >> second;
      start = second;
      adj[first].push_back(second);
      adj[second].push_back(first);
      oldtime += 10;
    }

    queue<pair<string, int> > bfs;
    
    bfs.push(make_pair(start, 0));
    
    int farthest = 0;
    map<string, bool> vis;
    vis[start] = true;
    while(not bfs.empty()){
      string cur = bfs.front().first;
      int dist = bfs.front().second;
      if(dist > farthest){
        farthest = dist;
      }
      bfs.pop();
      
      for(int i = 0; i < adj[cur].size(); i++){
        if(vis[adj[cur][i]] == false){
          vis[adj[cur][i]] = true;
          bfs.push(make_pair(adj[cur][i], dist + 10));
        }
      }
    }
    cout << (oldtime * 2) - (farthest * 2) << endl;
  }
  
  
  return 0;
}
