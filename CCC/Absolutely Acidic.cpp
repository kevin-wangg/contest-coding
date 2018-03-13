#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#define pb push_back
using namespace std;

int main()
{
  int sensors; cin >> sensors;
  vector<int> readings(sensors, 0);
  map<int, int> count;
  for(int i = 0; i < sensors; i++){
    int val; cin >> val;
    count[val]++;
  }

  int highval = -1;
  int highind;
  vector<int> allhigh = {};
  for(map<int, int>::iterator it = count.begin(); it != count.end(); it++){
    if(it->second > highval){
      highval = it->second;
      highind = it->first;
      allhigh = {};
      allhigh.pb(highind);
    }
    else if(it->second == highval){
      allhigh.pb(it->first);
    }
  }
  if(allhigh.size() > 1){
    cout << abs(*max_element(allhigh.begin(), allhigh.end()) -
            *min_element(allhigh.begin(), allhigh.end()));
    return 0;
  }
  /*for(int i = 0; i < allhigh.size(); i++){
    cout << allhigh[i] << " ";
  }
  cout << endl;*/
  int next = -1;
  int wow;
  vector<int> allnext = {};

  for(map<int, int>::iterator it = count.begin(); it != count.end(); it++){
    //cout << it->first << " " << it->second << endl;
    if(it->second > next and it->second < highval){
      next = it->second;
      wow = it->first;
      allnext = {};
      allnext.pb(wow);
      //cout << wow << endl;
    }
    else if(it->second == next){
      //cout << "hi";
      allnext.pb(it->first);
    }
  }
  /*for(int i = 0; i < allnext.size(); i++){
    cout << allnext[i] << " ";
  }
  cout << endl;*/
  int one = abs(*max_element(allhigh.begin(), allhigh.end()) -
            *min_element(allnext.begin(), allnext.end()));
  int two = abs(*min_element(allhigh.begin(), allhigh.end()) -
            *max_element(allnext.begin(), allnext.end()));
  cout << max(one, two);
  return 0;
}
