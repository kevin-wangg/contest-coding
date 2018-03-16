#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main() 
{
  int roads;
  cin >> roads;
  int queries; cin >> queries;
  vector<vector<int> > adj(26, vector<int> (26, 0));
  for(int i = 0; i < roads; i++){
    string first, second;
    cin >> first >> second;
    adj[int(first[0]) - 65][int(second[0] - 65)] = 1;
    adj[int(second[0]) - 65][int(first[0] - 65)] = 1;
  }
  for(int i = 0; i < queries; i++){
    string first, second;
    cin >> first >> second;
    int start = int(first[0]) - 65, end = int(second[0]) - 65;
    vector<int> flag(26, -1);
    flag[start] = 0;
    queue<pair<int, vector<int> > > bfs;
    vector<int> wow;
    wow.push_back(start);
    bfs.push(make_pair(start, wow));
    while(not bfs.empty()){
      int cur = bfs.front().first;
      vector<int> vis = bfs.front().second;
      bfs.pop();
      for(int i = 0; i < adj[cur].size(); i++){
        if(adj[cur][i] == 1 and flag[i] == -1){
          if(i == end){
            for(int j = 0; j < vis.size(); j++){
              cout << char(vis[j] + 65);
            }
            cout << char(i + 65);
            break;
          }
          flag[i] = 0;
          vector<int> newVis = vis;
          newVis.push_back(i);
          bfs.push(make_pair(i, newVis));
        }
      }
    }
    cout << endl;
  }
  return 0;
}
