#include <iostream>
#include <map>
#include <algorithm>
#define nl "\n"
using namespace std;

map<string, bool> necessary;
int adj[26][26] = {0};

void recurse(int node, map<string, bool> travelled)
{
  string temp = "";
  if(node == 1){
    //cout << "stop" << nl;
    for(map<string, bool>::iterator it = travelled.begin(); it != travelled.end(); it++){
      if(it->second == false){
        necessary[it->first] = false;
      }
    }
  }
  else{
    for(int i = 1; i < 26; i++){
      temp = "";
      if(adj[node][i] == 1){
        if(node < i){
          temp += char(node + 65);
          temp += char(i + 65);
        }
        else{
          temp += char(i + 65);
          temp += char(node + 65);
        }
        if(travelled[temp] == false){
          map<string, bool> newtravelled = travelled;
          newtravelled[temp] = true;
          recurse(i, newtravelled);
        }
      }
    }
  }
}
int main()
{
  map<string, bool> travelled;
  string points = "";
  while(true){
    cin >> points;
    if(points == "**"){
      break;
    }
    adj[int(points.at(0)) - 65][int(points.at(1)) - 65] = 1;
    adj[int(points.at(1)) - 65][int(points.at(0)) - 65] = 1;
    if(int(points.at(0)) < int(points.at(1))){
      necessary[points] = true;
      travelled[points] = false;
    }
    else{
      reverse(points.begin(), points.end());
      necessary[points] = true;
      travelled[points] = false;
    }
  }
  
  recurse(0, travelled);
  int count = 0;
  for(map<string, bool>::iterator it = necessary.begin(); it != necessary.end(); it++){
    if(it->second == true){
      count++;
      cout << it->first << nl;
    }
  }
  cout << "There are " << count << " disconnecting roads.";
  return 0;
}
