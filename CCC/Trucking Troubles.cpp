#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <utility>

#define mp make_pair

using namespace std;

map<int, int> heap;

pair<int, int> extractMax()
{
	int lowkey, lowval = -1;

	for(map<int, int>::iterator it = heap.begin(); it != heap.end(); it++){
		if(it->second > lowval){
			lowval = it->second;
			lowkey = it->first;
		}
	}

	heap.erase(lowkey);

	return mp(lowkey, lowval);
}

int main()
{
	int cities, roads, dests;
	cin >> cities >> roads >> dests;

	vector<vector<pair<int, int> > > adj(cities, vector<pair<int, int> > (0));

	for(int i = 0; i < roads; i++){
		int a, b, c;
		cin >> a >> b >> c;
		heap[a - 1] = -1;
		heap[b - 1] = -1;
		adj[a - 1].push_back(mp(b - 1, c));
		adj[b - 1].push_back(mp(a - 1, c));
	}

	vector<int> isDest;

	for(int i = 0; i < dests; i++){
		int input;
		cin >> input;
		isDest.push_back(input - 1);
	}

	vector<bool> vis(cities, false);

	heap[0] = 0;

	unordered_map<int, pair<int, int> > parent;

	while(!heap.empty()){
		pair<int, int> high = extractMax();

		int cur = high.first;
		int weight = high.second;

		if(heap.empty()){
			break;
		}

		for(int i = 0; i < adj[cur].size(); i++){

			int connectedTo = adj[cur][i].first;
			int length = adj[cur][i].second;

			if(heap.find(connectedTo) != heap.end()){
				if(length > heap[connectedTo]){
					heap[connectedTo] = length;
					parent[connectedTo] = mp(cur, length);
					//cout << connectedTo + 1 << " " << cur + 1<< " " << length << endl;
				}
			}
		}
	}

	int mini = 1e9;

	for(int i = 0; i < dests; i++){
		int cur = isDest[i];
		while(true){
			if(cur == 0 or vis[cur] == true){
				break;
			}
			vis[cur] = true;
			int weight = parent[cur].second;
			if(weight < mini){
				mini = weight;
			}
			cur = parent[cur].first;
		}
	}

	cout << mini;
	return 0;
}
