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
int N, M;
bool isValid(int x,int y) {
	return (x >= 0 && x < N && y >= 0 && y < M); 
}
int main(){
	int T;
	cin >> T;
	int dist[1000][1000];
	int g[1000][1000];
	while(T--) {
		scanf("%d",&N);
		scanf("%d",&M);
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				scanf("%d",&g[i][j]);
				dist[i][j] = mmx;
			}
		}
		priority_queue<pair<int,ii>,vector<pair<int,ii> >,greater<pair<int,ii> > > q;
		q.push(mp(g[0][0],mp(0,0)));
		dist[0][0] = g[0][0];
		int cnt = 0;
		while(!q.empty()) {
			
			pair<int,ii> p = q.top();
			q.pop();
			int d = p.first ;
			int x = p.second.first;
			int y = p.second.second;
			if( d > dist[x][y]) continue;
			cnt++;
			for(int i = 0; i < 4; i++) {
				if(isValid(x+dr[i],y+dc[i]) &&  g[x+dr[i]][y+dc[i]] + d < dist[x+dr[i]][y+dc[i]]){
					dist[x+dr[i]][y+dc[i]] = g[x+dr[i]][y+dc[i]] + d;
					q.push(mp(dist[x+dr[i]][y+dc[i]],ii(x+dr[i],y+dc[i])));
				}
			}
		}
		printf("%d\n",dist[N-1][M-1]);
	}
	return 0;
}
