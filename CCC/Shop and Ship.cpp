#include <iostream>
#include <vector>
#include <queue>

#define mp make_pair

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int cities, routes;
	cin >> cities >> routes;
	vector<vector<pair<int, int> > > adj(cities, vector<pair<int, int> > (0));
	for(int i = 0; i < routes; i++){
		int a, b, cost;
		cin >> a >> b >> cost;
		adj[a - 1].push_back(mp(b - 1, cost));
		adj[b - 1].push_back(mp(a - 1, cost));
	}
	vector<int> canBuy(cities, 0);
	int K;
	cin >> K;
	for(int i = 0; i < K; i++){
		int a, b;
		cin >> a >> b;
		canBuy[a - 1] = b;
	}
	int dest;
	cin >> dest;

	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

	vector<int> flag(cities, 1e9);

	pq.push(mp(0, dest - 1));

	int best = 1e9;

	while(!pq.empty()){
		pair<int, int> low = pq.top();
		pq.pop();
		int weight = low.first;
		int cur = low.second;

		//cout << "cur " << cur + 1 << endl;
		if(weight < flag[cur]){
			flag[cur] = weight;
		}

		if(canBuy[cur] > 0){
			best = min(best, weight + canBuy[cur]);
		}

		for(int i = 0; i < adj[cur].size(); i++){
			int connectedTo = adj[cur][i].first;
			int length = adj[cur][i].second;

			if(weight + length < flag[connectedTo]){
				if(weight + length < best){
					pq.push(mp(weight + length, connectedTo));
				}
			}
		}
	}
	cout << best;
	return 0;
}
