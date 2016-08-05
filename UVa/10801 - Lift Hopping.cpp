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
	int N, t,x,y;
	string s;
	while(cin >> N >> t) {
		vi lv(N);
		vector<vii> g(500);
		for(int i = 0; i < N; i++) {
			cin >> lv[i];
		}
		int cnt = 0;
		bool fl[100] = {0};
		bool fll[100][5] = {0};
		vi src;
		int st = 0;
		getchar();
		while(N--){
			gl(s);
			stringstream ss;
			ss << s;
			ss >> x;
			if(x == 0) src.push_back(100*cnt);
			if(fl[x]){
				int j = 0;
				while(j < cnt) {
					if(fll[x][j]){
						g[x+(100*j)].push_back(ii(x+(100*cnt),((x == 0)? 0:60)));
						g[x+(100*cnt)].push_back(ii(x+(100*j),((x == 0)? 0:60)));
					}
					j++;
				}
			}
		
			fl[x] = 1;
			fll[x][cnt] = 1;
			while (ss >> y) {
				g[x+(100*cnt)].push_back(ii(y+(100*cnt),(((y+(100*cnt))-(x+(100*cnt)))*lv[cnt])));
				g[y+(100*cnt)].push_back(ii(x+(100*cnt),(((y+(100*cnt))-(x+(100*cnt)))*lv[cnt])));
				if(fl[y]){
					int j = 0;
					while(j < cnt) {
						if(fll[y][j]){
							g[y+(100*j)].push_back(ii(y+(100*cnt),60));
							g[y+(100*cnt)].push_back(ii(y+(100*j),60));
						}
						j++;
					}
				}
				fl[y] = 1;
				fll[y][cnt] = 1;
				if(y == 0) src.push_back(100*cnt);;
				x = y;
				
			}
			cnt++;
		}
		
		vi dist(500,mmx);
		priority_queue<ii,vii,greater<ii> > q;
		for(int i = 0; i < src.size(); i++) {
			dist[src[i]] = 0;
			q.push(ii(0,src[i]));
		}
		while(!q.empty()) {
			ii p = q.top();
			q.pop();
			int d = p.first;
			int u = p.second;
			if (d > dist[u]) continue;
			for(int i = 0; i < g[u].size(); i++) {
				ii v = g[u][i];
				if( dist[u]+v.second < dist[v.first]) {
					dist[v.first] = dist[u]+v.second;
					q.push(ii(dist[v.first],v.first));
				}
			}
			
		}
		vi res;
		int j = 0;
		while(j < cnt) {
			res.push_back(dist[t+(j*100)]);
			j++;
		}
		int ans =  *min_element(all(res));
		if(ans == mmx) cout << "IMPOSSIBLE" << endl;
		else cout<<ans << endl;
	}
	return 0;
}
