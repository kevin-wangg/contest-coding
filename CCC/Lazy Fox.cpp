#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <cmath>
#include <algorithm>
using namespace std;
double find(int x1, int y1, int x2, int y2)
{
	return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}
int main()
{
	int N;
	cin >> N;
	vector<pair<int, int> > points;
	points.push_back(make_pair(0,0));
	for(int i = 0; i < N; i++){
		int a, b;
		cin >> a >> b;
		points.push_back(make_pair(a, b));
	}
	vector<vector<bool> > seen(2001, vector<bool> (2001, false));
	vector<tuple<double, int, int> > distances;
	for(int i = 0; i < N + 1; i++){
		for(int j = 0; j < N + 1; j++){
			if(i != j){
				if(seen[i][j] == false){
					seen[i][j] = true;
					seen[j][i]= true;
				//cout << i << " "<< j<<endl;
				double dist = find(points[i].first, points[i].second, points[j].first, points[j].second);									distances.push_back(make_tuple(dist, i, j));
				}
			}
		}
	}
	vector<int> most(N + 1, 0);
	vector<double> dis(N+1, 0);
	vector<int> oldmost(N+1, 0);
	sort(distances.begin(), distances.end());
	for(int i = 0; i < distances.size(); i++){
		double length = get<0> (distances[i]);
		//cout << length << endl;
		int a = get<1> (distances[i]);
		int b = get<2> (distances[i]);
		if(length > dis[a]){
			dis[a] = length;
			oldmost[a] = most[a];
		}
		if(length > dis[b]){
			dis[b] = length;
			oldmost[b] = most[b];
		}
		if(a == 0){
			if(oldmost[b] > most[a]){
				most[a] = oldmost[b];
			}
		}
		else{
			if(oldmost[b] +1> most[a]){
				most[a] = oldmost[b]+1;
			}
			if(oldmost[a] +1> most[b]){
				most[b]=oldmost[a]+1;
			}
		}
	}
	cout << most[0]+1;
}
