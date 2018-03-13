#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

int main()
{
  int t; cin >> t;
  map<string, string> left;
  left["up"] = "left";
  left["down"] = "right";
  left["left"] = "down";
  left["right"] = "up";
  map<string, string> right;
  right["up"] = "right";
  right["down"] = "left";
  right["left"] = "up";
  right["right"] = "down";
  for(int i = 0; i < t; i++){
    vector<int> directions;
    while(true){
      int n; cin >> n;
      if(n == 0){
        break;
      }
      directions.push_back(n);
    }
    int xdis = 0, ydis = 0;
    string orient = "up";
    for(int j = 0; j < directions.size(); j++){
      if(directions[j] == 1){
        j++;
        if(orient == "up"){
          ydis += directions[j];
        }
        else if(orient == "down"){
          ydis -= directions[j];
        }
        else if(orient == "right"){
          xdis += directions[j];
        }
        else if(orient == "left"){
          xdis -= directions[j];
        }
      }
      else if(directions[j] == 2){
        orient = right[orient];
      }
      else if(directions[j] == 3){
        orient = left[orient];
      }
    }
    cout << "Distance is " << abs(xdis) + abs(ydis) << endl;
    vector<int> goBack;
    if(xdis > 0 and ydis > 0){
      if(orient == "up"){
        goBack.push_back(3);
        goBack.push_back(1);
        goBack.push_back(abs(xdis));
        goBack.push_back(3);
        goBack.push_back(1);
        goBack.push_back(abs(ydis));
      }
      else if(orient == "right"){
        goBack.push_back(2);
        goBack.push_back(1);
        goBack.push_back(abs(ydis));
        goBack.push_back(2);
        goBack.push_back(1);
        goBack.push_back(abs(xdis));
      }
      else if(orient == "down"){
        goBack.push_back(1);
        goBack.push_back(abs(ydis));
        goBack.push_back(2);
        goBack.push_back(1);
        goBack.push_back(abs(xdis));
      }
      else if(orient == "left"){
        goBack.push_back(1);
        goBack.push_back(abs(xdis));
        goBack.push_back(3);
        goBack.push_back(1);
        goBack.push_back(abs(ydis));
      }
    }
    else if(xdis > 0 and ydis < 0){
      if(orient == "up"){
        goBack.push_back(1);
        goBack.push_back(abs(ydis));
        goBack.push_back(3);
        goBack.push_back(1);
        goBack.push_back(abs(xdis));
      }
      else if(orient == "right"){
        goBack.push_back(3);
        goBack.push_back(1);
        goBack.push_back(abs(ydis));
        goBack.push_back(3);
        goBack.push_back(1);
        goBack.push_back(abs(xdis));
      }
      else if(orient == "down"){
        goBack.push_back(2);
        goBack.push_back(1);
        goBack.push_back(abs(xdis));
        goBack.push_back(2);
        goBack.push_back(1);
        goBack.push_back(abs(ydis));
      }
      else if(orient == "left"){
        goBack.push_back(1);
        goBack.push_back(abs(xdis));
        goBack.push_back(2);
        goBack.push_back(1);
        goBack.push_back(abs(ydis));
      }
    }
    else if(xdis < 0 and ydis < 0){
      if(orient == "up"){
        goBack.push_back(1);
        goBack.push_back(abs(ydis));
        goBack.push_back(2);
        goBack.push_back(1);
        goBack.push_back(abs(xdis));
      }
      else if(orient == "right"){
        goBack.push_back(1);
        goBack.push_back(abs(xdis));
        goBack.push_back(3);
        goBack.push_back(1);
        goBack.push_back(abs(ydis));
      }
      else if(orient == "down"){
        goBack.push_back(3);
        goBack.push_back(1);
        goBack.push_back(abs(xdis));
        goBack.push_back(3);
        goBack.push_back(1);
        goBack.push_back(abs(ydis));
      }
      else if(orient == "left"){
        goBack.push_back(2);
        goBack.push_back(1);
        goBack.push_back(abs(ydis));
        goBack.push_back(2);
        goBack.push_back(1);
        goBack.push_back(abs(xdis));
      }
    }
    else if(xdis < 0 and ydis > 0){
      if(orient == "up"){
        goBack.push_back(2);
        goBack.push_back(1);
        goBack.push_back(abs(xdis));
        goBack.push_back(2);
        goBack.push_back(1);
        goBack.push_back(abs(ydis));
      }
      else if(orient == "right"){
        goBack.push_back(1);
        goBack.push_back(abs(xdis));
        goBack.push_back(2);
        goBack.push_back(1);
        goBack.push_back(abs(ydis));
      }
      else if(orient == "down"){
        goBack.push_back(1);
        goBack.push_back(abs(ydis));
        goBack.push_back(3);
        goBack.push_back(1);
        goBack.push_back(abs(xdis));
      }
      else if(orient == "left"){
        goBack.push_back(3);
        goBack.push_back(1);
        goBack.push_back(abs(ydis));
        goBack.push_back(3);
        goBack.push_back(1);
        goBack.push_back(abs(xdis));
      }
    }
    else{
      if(xdis == 0 and ydis == 0){
        
      }
      else if(xdis == 0){
        if(ydis > 0){
          if(orient == "up"){
            goBack.push_back(2);
            goBack.push_back(2);
          }
          else if(orient == "down"){
            
          }
          else if(orient == "left"){
            goBack.push_back(3);
          }
          else if(orient == "right"){
            goBack.push_back(2);
          }
          goBack.push_back(1);
          goBack.push_back(abs(ydis));
        }
        else if(ydis < 0){
          if(orient == "up"){
            
          }
          else if(orient == "down"){
            goBack.push_back(2);
            goBack.push_back(2);
          }
          else if(orient == "left"){
            goBack.push_back(2);
          }
          else if(orient == "right"){
            goBack.push_back(3);
          }
          goBack.push_back(1);
          goBack.push_back(abs(ydis));
        }
      }
      else if(ydis == 0){
        if(xdis > 0){
          if(orient == "up"){
            goBack.push_back(3);
          }
          else if(orient == "down"){
            goBack.push_back(2);
          }
          else if(orient == "left"){
            
          }
          else if(orient == "right"){
            goBack.push_back(2);
            goBack.push_back(2);
          }
          goBack.push_back(1);
          goBack.push_back(abs(xdis));
        }
        else if(xdis < 0){
          if(orient == "up"){
            goBack.push_back(2);
          }
          else if(orient == "down"){
            goBack.push_back(3);
          }
          else if(orient == "left"){
            goBack.push_back(2);
            goBack.push_back(2);
          }
          else if(orient == "right"){

          }
          goBack.push_back(1);
          goBack.push_back(abs(xdis));
        }
      }
    }
    for(int k = 0; k < goBack.size(); k++){
      cout << goBack[k] << endl;
    }
    cout << endl;
  }
  return 0;
}
