#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<bool> vis(7, false);
vector<int> final;
vector<vector<int> > adj(7, vector<int> (7, 0));

void rec(int cur)
{
  for(int i = 6; i > -1; i--){
    if(adj[cur][i] == 1 and vis[i] == false){
      vis[i] = true;
      rec(i);
    }
  }
  //cout << "added " << cur + 1 << endl;
  final.push_back(cur);
}

bool check()
{
  for(int i = 0; i < 7; i++){
    vector<bool> yolo(7, false);
    stack<int> dfs;
    dfs.push(i);
    while(!dfs.empty()){
      int cur = dfs.top();
      dfs.pop();
      for(int j = 0; j < 7; j++){
        if(adj[cur][j] == 1 and yolo[j] == false){
          if(i == j){
            return false;
          }
          dfs.push(j);
          yolo[j] = true;
        }
      }
    }
  }
  return true;
}

int main()
{
  adj[0][6] = 1;
  adj[0][3] = 1;
  adj[1][0] = 1;
  adj[2][3] = 1;
  adj[2][4] = 1;
  int a, b;
  while(true){
    cin >> a >> b;
    if(a == 0 && b == 0){
      break;
    }
    adj[a - 1][b - 1] = 1;
  }
  
  if(!check()){
    cout << "Cannot complete these tasks. Going to bed.";
    return 0;
  }
  
  for(int i = 6; i > -1; i--){
    if(vis[i] == false){
      vis[i] = true;
      rec(i);
    }
  }
  
  
  for(int i = 6; i > -1; i--){
    cout << final[i] + 1 << " ";
  }
  return 0;
}
