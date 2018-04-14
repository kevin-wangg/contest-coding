#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <queue>

#define mt make_tuple
#define mp make_pair

using namespace std;

int main()
{
	int thickness, islands, routes;
	cin >> thickness >> islands >> routes;

	vector<vector<tuple<int, int, int> > > adj(islands, vector<tuple<int, int, int> > (0));

	for(int i = 0; i < routes; i++){
		int a, b, time, wear;
		cin >> a >> b >> time >> wear;
		adj[a - 1].push_back(mt(b - 1, time, wear));
		adj[b - 1].push_back(mt(a - 1, time, wear));
	}

	int start, finish;
	cin >> start >> finish;
	start--; finish--;

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<tuple<int, int, int> > > pq;

	vector<pair<int, int> > flag(islands, mp(1e9, thickness));

    pq.push(mt(0, start, thickness));

    while(!pq.empty()){
		tuple<int, int, int> low = pq.top();
		pq.pop();

		int weight = get<0> (low);
		int cur = get<1> (low);
		int hull = get<2> (low);

		if(weight < flag[cur].first){
			flag[cur] = mp(weight, hull);
		}
		if(cur == finish){
			cout << flag[cur].first;
			return 0;
		}

		for(int i = 0; i < adj[cur].size(); i++){
			int connectedTo = get<0> (adj[cur][i]);
			int length = get<1> (adj[cur][i]);
			int weardown = get<2> (adj[cur][i]);

			if(weight + length < flag[connectedTo].first && hull - weardown > 0){
				/*if(connectedTo == finish){
					cout << weight + length;
					return 0;
				}*/
				pq.push(mt(length + weight, connectedTo, hull - weardown));
			}
			else if(hull - weardown > flag[connectedTo].second){
				pq.push(mt(length + weight, connectedTo, hull - weardown));
			}
		}

    }

	cout << -1;

	return 0;
}
