#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>
#include <algorithm>
#include <map>

#define mp make_pair
#define mt make_tuple

using namespace std;

int main()
{
	int buildings, pipes, enhancer;
	cin >> buildings >> pipes >> enhancer;

	vector<vector<tuple<int, int, bool> > > adj(buildings, vector<tuple<int, int, bool> > (0));

	for(int i = 0; i < pipes; i++){
		int a, b, cost;
		cin >> a >> b >> cost;

		if(i < buildings - 1){
			adj[a - 1].push_back(mt(b - 1, cost, true));
			adj[b - 1].push_back(mt(a - 1, cost, true));
		}
		else{
			adj[a - 1].push_back(mt(b - 1, cost, false));
			adj[b - 1].push_back(mt(a - 1, cost, false));
		}
	}



	return 0;
}
