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
	int T,N, M, s, t;
	int x, y, d;
	scanf("%d",&T);
	int cnt = 0;
	while(T--) {
		cnt++;
		scanf("%d %d %d %d", &N, &M, &s, &t);
		vector<vii> g(N);
		vi dist(N,mmx);
		for(int i = 0; i < M; i++) {
			scanf("%d %d %d",&x, &y, &d);
			g[x].push_back(ii(y,d));
			g[y].push_back(ii(x,d));
		}
		priority_queue<ii, vector<ii>, greater<ii> > q;
		q.push(ii(0,s));
		dist[s] = 0;
		while(!q.empty()) {
			ii p = q.top();
			q.pop();
			d = p.first;
			int u = p.second;
			if(d > dist[u]) continue;
			for(int i = 0; i < g[u].size();i++) {
				ii v = g[u][i];
				if(dist[u]+v.second < dist[v.first]) {
					dist[v.first] = dist[u] + v.second;
					q.push(ii(dist[v.first],v.first));
				}
			}
		}
		if(dist[t] == mmx) {
			printf("Case #%d: unreachable\n",cnt); 
		}
		else
			printf("Case #%d: %d\n",cnt,dist[t]); 
	}
	return 0;
}
