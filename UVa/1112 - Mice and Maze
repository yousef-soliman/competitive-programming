#include <iostream>
#include <string>
#include <cstdio>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <sstream>
#include <utility>
#include <cmath>
#include <bitset>
#include <cstring>
#include <utility>
#include <set>
#include <cctype>
#include <list>
#include <climits>
#include <cstdlib>
#define ii pair<int,int>
#define psi pair<string,int>
#define vi vector<int>
#define vvi vector <vector<int> >
#define vvc vector <vector<char> >
#define vs vector<string>
#define vc vector<char>
#define vl vector<long long>
#define vii vector<ii>
#define mp make_pair
#define gl(s) getline(cin , s)
#define max3(x, y, z) max(x,max(y,z))  
#define min3(x, y, z) min(x,min(y,z))
#define mmx INT_MAX 
#define mmn INT_MIN
#define all(v) v.begin(),v.end()
#define distance(x,y) sqrt(pow(x.first - y.first ,2) + pow(x.second - y.second ,2))
typedef long long ll;
int dr_k[] = {1, 2 , -1, 2, -2, -2, 1, -1};
int dc_k[] = {2, 1, 2, -1, 1, -1, -2, -2};
int dr[] = {1, 0, 0, -1, 1, 1, -1, -1};
int dc[] = {0, 1, -1, 0, 1, -1, 1, -1};
int dt[] = {-1, 1};
using namespace std;

int main(){
	int T, N, E, t, M, x, y, d, u;
	cin >> T;
	while(T--) {
		cin >> N >> E >> t >> M;
		vector<vii> g(N);
		for(int i = 0; i < M; i++) {
			scanf("%d %d %d",&x, &y, &d);
			g[x-1].push_back(ii(y-1,d));
		}
		int cnt = 0;
		for(int i = 0; i < N; i++) {
			vi dist(N,mmx);
			priority_queue<ii,vii,greater<ii> > q;
			q.push(ii(0,i));
			dist[i] = 0;
			while(!q.empty()) {
				ii p = q.top();
				q.pop();
				d = p.first;
				u = p.second;
				if(d > dist[u]) continue;
				for(int i = 0; i < g[u].size(); i++) {
					ii v = g[u][i];
					if(dist[u] + v.second < dist[v.first]) {
						dist[v.first] = dist[u] + v.second;
						q.push(ii(dist[v.first],v.first)); 
					}
				}
			}
			if(dist[E-1] <= t) {
				cnt++;
			}
		}
		cout << cnt << endl;
		if(T)
		cout << endl;
	}
	return 0;
}
