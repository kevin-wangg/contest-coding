#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

int main() 
{
  vector<vector<int> > adj(100, vector<int> (0));
  int pages;
  cin >> pages;
  map<string, int> toNum;
  map<string, bool> done;
  vector<string> toStr;
  int key = 0;
  while(pages--){
    string cur;
    cin >> cur;
    if(done[cur] == false){
      toNum[cur] = key++;
      toStr.push_back(cur);
      done[cur] = true;
    }
    while(true){
      string input;
      cin >> input;
      if(input == "</HTML>"){
        break;
      }
      string check = input.substr(0, 5);
      if(check == "HREF="){
        string takeout = "";
        for(int i = 6; i < input.size(); i++){
          if(input[i] == '"'){
            break;
          }
          takeout += input[i];
        }
        if(done[takeout] == false){
          done[takeout] = true;
          toNum[takeout] = key++;
          toStr.push_back(takeout);
        }
        adj[toNum[cur]].push_back(toNum[takeout]);
        cout << "Link from " << cur << " to " << takeout << endl;
      }
    }
  }
  cout << endl;
  while(true){
    string first, second;
    cin >> first >> second;
    if(first == "The" && second == "End"){
      break;
    }
    int start = toNum[first];
    int end = toNum[second];
    
    queue<int> bfs;
    bfs.push(start);
    vector<bool> vis(100, false);
    vis[start] = true;
    
    bool possible = false;
    
    while(!bfs.empty()){
      if(possible){
        break;
      }
      int cur = bfs.front();
      bfs.pop();
      int limit = adj[cur].size();
      for(int i = 0; i < limit; i++){
        if(vis[adj[cur][i]] == false){
          if(adj[cur][i] == end){
            cout << "Can surf from " << toStr[start] << " to " << toStr[end] << endl;
            possible = true;
            break;
          }
          
          vis[adj[cur][i]] = true;
          bfs.push(adj[cur][i]);
        }
      }
    }
    if(!possible){
      cout << "Can't surf from " << toStr[start] << " to " << toStr[end] << endl;
    }
  }
  return 0;
}
