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
int dr[] = {-1, 0, 0, 1, 1, 1, -1, -1};
int dc[] = {0, -1, 1, 0, 1, -1, 1, -1};
using namespace std;

int main(){
	int N;
	int x, y, t = 0;
	vvi g;
	vi vis;
	vi dis;
	while(cin >> N && N) {
		g.resize(32);
		int cnt = 1;
		map<int,int> m;
		dis.assign(32,-2);
		for(int i = 0; i < N; i++){
			cin >> x >> y;
			if(!m[x])
				m[x]= cnt++;
			if(!m[y])
				m[y]= cnt++;
			g[m[x]].push_back(m[y]);
			g[m[y]].push_back(m[x]);
			dis[m[x]] = -1;
			dis[m[y]] = -1;
		}
		
		while(cin >> x >> y){
			if(x == 0 && y == 0) break;
			vi dis2 = dis;
			t++;
			cnt = 0;
			queue <int>q;
			q.push(m[x]);
			dis2[m[x]] = 0;
			while(!q.empty()){
				int u = q.front();
				q.pop();
				for(int i = 0; i < g[u].size();i++) {
					int v = g[u][i];
					if(dis2[v] == -1){
						dis2[v] = dis2[u]+1;
						q.push(v);
					}
					
				}
			}
			for(int i = 0;i < dis.size(); i++) {
				if(i != m[x] && (dis2[i] > y ||dis2[i] == -1 )) {
					cnt++;
				}
			}
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", t, cnt, x, y);
		}
		
		m.clear();
		g.clear();
	}
	return 0;
}
