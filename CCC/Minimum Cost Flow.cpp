#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct link {
  ll start, end, cost, rank;
};

bool compare(link a, link b)
{
  if(a.cost != b.cost){
    return a.cost < b.cost;
  }
  else{
    return a.rank < b.rank;
  }
}

ll find(ll num, vector<ll> &disjoint)
{
  if(disjoint[num] < 0){
    return num;
  }
  return disjoint[num] = find(disjoint[num], disjoint);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  ll vertices, edges, enhancer;
  cin >> vertices >> edges >> enhancer;

  vector<link> allEdges(edges);

  for(ll i = 0; i < edges; i++){
    cin >> allEdges[i].start >> allEdges[i].end >> allEdges[i].cost;
    allEdges[i].rank = i;
  }

  sort(allEdges.begin(), allEdges.end(), compare);

  vector<ll> disjoint(vertices + 1, -1);

  ll days = 0;
	ll bigCost = 0;

  for(ll i = 0; i < edges; i++){

    ll a = find(allEdges[i].start, disjoint);
    ll b = find(allEdges[i].end, disjoint);

    if(a != b){
      if(disjoint[a] < disjoint[b]){
        disjoint[a] += disjoint[b];
        disjoint[b] = a;
      }
      else{
        disjoint[b] += disjoint[a];
        disjoint[a] = b;
      }

			if(allEdges[i].cost > bigCost){
				bigCost = allEdges[i].cost;
      }

      if(!(allEdges[i].rank < vertices - 1)){
        days++;
      }
    }
  }

  vector<ll> newdisjoint(vertices + 1, -1);
  for(ll i = 0; i < edges; i++){
    ll a = find(allEdges[i].start, newdisjoint);
    ll b = find(allEdges[i].end, newdisjoint);
    if(a != b){
      if(allEdges[i].cost < bigCost or (allEdges[i].rank < vertices - 1 and allEdges[i].cost == bigCost)){
        if(newdisjoint[a] < newdisjoint[b]){
          newdisjoint[a] += newdisjoint[b];
          newdisjoint[b] = a;
        }
        else{
          newdisjoint[b] += newdisjoint[a];
          newdisjoint[a] = b;
        }
      }
      else{
        if(allEdges[i].rank < vertices - 1 and allEdges[i].cost <= enhancer){
          days--;
          break;
        }
      }
    }
  }

  cout << days;


  return 0;
}
