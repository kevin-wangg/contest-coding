#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<bool> isPho(N, false);
	vector<vector<int> > adj(N, vector<int> (0));
	vector<int> incounter(N, 0);
	vector<bool> useful(N, true);
	vector<bool> processed(N, false);
	vector<int> leaves;
	int start;
	//get input for which ones are pho restaurants
	for(int i = 0; i < M; i++){
		int input;
		cin >> input;
		isPho[input] = true;
		useful[input] = true;
		start = input;
	}
	for(int i = 0; i < N - 1; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		incounter[a]++;
		incounter[b]++;
	}
	for(int i = 0; i < N; i++){
		if(incounter[i] == 1){
			leaves.push_back(i);
		}
	}
	int totweight = N - 1;
	for(int i = 0; i < leaves.size(); i++){
		//cout << leaves[i] << endl;
		if(isPho[leaves[i]] == false){
			useful[leaves[i]] = false;
			totweight--;
			queue<int> bfs;
			bfs.push(leaves[i]);
			while(!bfs.empty()){
				int cur = bfs.front();
				//cout << "wow " << cur << endl;
				bfs.pop();
				for(int j = 0; j < adj[cur].size(); j++){
					//cout << "hi " << adj[cur][j] << endl;
					incounter[adj[cur][j]]--;
					//cout << incounter[adj[cur][j]] << " " << isPho[adj[cur][j]] << " " << useful[adj[cur][j]] << endl;
					if(incounter[adj[cur][j]] <= 1 && !isPho[adj[cur][j]] && useful[adj[cur][j]]){
						useful[adj[cur][j]] = false;
						//cout << "set " << adj[cur][j] << " to useless" << endl;
						bfs.push(adj[cur][j]);
						totweight--;
					}
				}
			}
		}
	}
	/*for(int i = 0; i < useful.size(); i++){
		if(useful[i]){
			cout << i << " ";
		}
	}*/
	queue<int> firstbfs;
	vector<int> firstvis(N, -1);
	firstvis[start] = 0;
	firstbfs.push(start);
	int distance = 0;
	int nextstart;
	while(!firstbfs.empty()){
		int cur = firstbfs.front();
		firstbfs.pop();
		for(int i = 0; i < adj[cur].size(); i++){
			if(useful[adj[cur][i]] && firstvis[adj[cur][i]] == -1){
				firstvis[adj[cur][i]] = firstvis[cur] + 1;
				if(firstvis[adj[cur][i]] > distance){
					distance = firstvis[adj[cur][i]];
				}
				firstbfs.push(adj[cur][i]);
				nextstart = adj[cur][i];
			}
		}
	}
	//cout << "wow " << start << " " << nextstart << " " << distance << endl;
	queue<int> nextbfs;
	nextbfs.push(nextstart);
	vector<int> nextvis(N, -1);
	nextvis[nextstart] = 0;
	int diameter = 0;
	while(!nextbfs.empty()){
		int cur = nextbfs.front();
		nextbfs.pop();
		for(int i = 0; i < adj[cur].size(); i++){
			if(useful[adj[cur][i]] && nextvis[adj[cur][i]] == -1){
				nextvis[adj[cur][i]] = nextvis[cur] + 1;
				if(nextvis[adj[cur][i]] > diameter){
					diameter = nextvis[adj[cur][i]];
				}
				nextbfs.push(adj[cur][i]);
			}
		}
	}
	cout << totweight * 2 - diameter << endl;
	return 0;
}
