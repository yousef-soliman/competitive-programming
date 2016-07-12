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
typedef long long ll;
int dr_k[] = {1, 2 , -1, 2, -2, -2, 1, -1};
int dc_k[] = {2, 1, 2, -1, 1, -1, -2, -2};
int dr[] = {-1, 0, 0, 1, 1, 1, -1, -1};
int dc[] = {0, -1, 1, 0, 1, -1, 1, -1};
using namespace std;

class UnionFind {
	private:
		vi p;
		vi rank;
	public:
		UnionFind(int N) {
			rank.assign(N,0);
			for(int i = 0;i < N; i++) {
				p.push_back(i);
			}
		}
		int root(int i){
			return ((i == p[i])? i:p[i] = root(p[i]));
		}
		bool isSame(int i,int j) {
			return root(i) == root(j);
		}
		
		void Union(int i, int j) {
			int x = root(i);
			int y = root(j);
			if(x == y) return;
			if(rank[x] > rank[y]) {
				p[x] = y;
			}
			else {
				p[y] = x;
				if(rank[x] == rank[y]) {
					rank[y]++;
				}
			}
			
		}
};
int main(){	
	int T;
	cin >> T;
	int k, p;
	while(T--) {
		cin >> k >> p;
		vii v;
		int x, y;
		for(int i = 0; i < p; i++){
			cin >> x  >> y;
			v.push_back(mp(x,y));
		}
		vector<pair<double,ii> > g;
		for(int i = 0; i < v.size();i++){
			for(int j = i+1; j < v.size(); j++) {
				double dis = sqrt(pow(v[i].first - v[j].first,2) +pow(v[i].second - v[j].second,2));
				g.push_back(mp(dis,mp(i,j)));
			}
		}
		sort(all(g));
		UnionFind uf(p);
		bitset<501> bs;
		double mx = mmn;
		for(int i = 0; i < g.size(); i++){
			for(int j = 0; j < p;j++){
				bs[uf.root(j)] = 1; 
			}
			if(bs.count() == k) break;
			if(!uf.isSame(g[i].second.first,g[i].second.second)){
				if(mx < g[i].first) mx = g[i].first;
				uf.Union(g[i].second.first,g[i].second.second);
			}
			bs.reset();
		}
		printf("%.2f\n",mx);
	}
	return 0;
}
