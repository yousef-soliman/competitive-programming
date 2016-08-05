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
class UnionFind{
	private:
		vi p;
		vi rank;
	public:
		UnionFind(int N) {
			rank.assign(N,0);
			for(int i = 0; i < N; i++) {
				p.push_back(i);
			}
		}
		void assign(int N) {
			rank.assign(N,0);
			for(int i = 0; i < N; i++) {
				p[i] = i;
			}
		}
		int root(int i) {
			return (( i == p[i])? i: p[i] = root(p[i]));
		}
		bool isSame(int i, int j) {
			return root(i) == root(j);
		}
		void Union(int i,int j) {
			int x = root(i);
			int y = root(j);
			if(x != y) {
				if(rank[x] > rank[y]) {
					p[y] = x;
				}
				else {
					p[x] = y;
					if(rank[x] == rank[y]) {
						rank[y]++;
					}
				}
			}
		}
};
bool sortby(pair<int,ii> x,pair<int,ii>  y) {
	return x.first > y.first;
}
int main(){
	int T, N, M;
	cin >> T;
	int x, y, z;
	int t = 0;
	while(T--) {
		t++;
		cin >> N >> M;
		vector <pair<int,ii> > g;
		for(int i = 0; i < M; i++) {
			cin >> x >> y >> z;
			g.push_back(mp(z,mp(x,y)));			
		}
		sort(all(g),sortby);
		UnionFind u(N);
		int mn = mmx;
		for(int  i = 0 ; i < g.size(); i++) {
			if(!u.isSame(g[i].second.first,g[i].second.second)){
				mn =min(g[i].first,mn);
				u.Union(g[i].second.first,g[i].second.second);
			}
		}
		printf("Case #%d: %d\n",t,mn);
	}
	
	return 0;
}
