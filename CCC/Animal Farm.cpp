#include <iostream>
#include <vector>
#include <utility>
#include <map>

#define mp make_pair

using namespace std;

pair<int, int> extractMin(map<int, int> &heap)
{
	int lowkey, lowval = 1e9;

	for(map<int, int>::iterator it = heap.begin(); it != heap.end(); it++){
		if(it->second < lowval){
			lowval = it->second;
			lowkey = it->first;
		}
	}

	heap.erase(lowkey);

	return mp(lowkey, lowval);
}

int main()
{
	int pens;
	cin >> pens;

	map<int, int> heap;
	map<int, int> heap2;
	heap2[pens] = 1e9;

	map<pair<int, int>, bool> seen;
	map<pair<int, int>, pair<int, int> > connect;

	vector<vector<pair<int, int> > > adj(pens + 1, vector<pair<int, int> > (0));

	for(int i = 0; i < pens; i++){
		heap[i] = 1e9;
		heap2[i] = 1e9;
		int edges;
		cin >> edges;
		vector<int> vertices(edges);
		vector<int> lengths(edges);

		for(int j = 0; j < edges; j++){
				int corner;
				cin >> corner;
				vertices[j] = corner;
		}
		for(int j = 0; j < edges; j++){
				int edge;
				cin >> edge;
				lengths[j] = edge;
		}

		for(int j = 0; j < edges; j++){
			int first, second;
			if(j != edges - 1){
				first = min(vertices[j], vertices[j + 1]);
				second = max(vertices[j], vertices[j + 1]);
			}
			else{
				first = min(vertices[j], vertices[0]);
				second = max(vertices[j], vertices[0]);
			}
			pair<int, int> check = mp(first, second);
			if(seen[check] == false){ //first time seeing edge

				seen[check] = true;
				connect[check] = mp(i, lengths[j]);

			}
			else{ //seen this edge before
				seen[check] = false; //should never see it again, edge can only connect two pens
				int connectedTo = connect[mp(first, second)].first;
				int length = connect[mp(first, second)].second;
				adj[i].push_back(mp(connectedTo, length));
				adj[connectedTo].push_back(mp(i, length));
			}
		}
	}

	for(map<pair<int, int>, bool>::iterator it = seen.begin(); it != seen.end(); it++){
		if(it->second == true){
			int connectedTo = connect[it->first].first;
			int length = connect[it->first].second;

			adj[pens].push_back(mp(connectedTo, length));
			adj[connectedTo].push_back(mp(pens, length));
		}
	}

	/*for(int i = 0; i < adj.size(); i++){

		cout << i << ": ";
		for(int j = 0; j < adj[i].size(); j++){
			cout << adj[i][j].first << " " << adj[i][j].second << ", ";
		}
		cout << endl;
	}*/

	heap[0] = 0;
	heap2[0] = 0;

	int inside = 0;
	int outside = 0;

	while(!heap.empty()){
		pair<int, int> cur = extractMin(heap);

		int node = cur.first;

		int weight = cur.second;
		inside += weight;
		//cout << "cur " << node << " " << weight << endl;
		if(heap.empty()){
			break;
		}
		bool ok = false;
		for(int i = 0; i < adj[node].size(); i++){
			int connectedTo = adj[node][i].first;
			int length = adj[node][i].second;
			if(connectedTo != pens){ //can't go outside
				if(heap.find(connectedTo) != heap.end()){
					ok = true;
					if(length < heap[connectedTo]){
						//cout << "changing " << connectedTo << endl;
						heap[connectedTo] = length;
					}
				}
			}
		}
		if(!ok){
			inside = 1e9;
			break;
		}
	}

	while(!heap2.empty()){
		pair<int, int> cur = extractMin(heap2);

		int node = cur.first;
		int weight = cur.second;
		outside += weight;

		if(heap2.empty()){
			break;
		}
		for(int i = 0; i < adj[node].size(); i++){
			int connectedTo = adj[node][i].first;
			int length = adj[node][i].second;

			if(heap2.find(connectedTo) != heap2.end()){
				if(length < heap2[connectedTo]){
					heap2[connectedTo] = length;
				}
			}
		}
	}

	cout << min(inside, outside);

	return 0;
}
