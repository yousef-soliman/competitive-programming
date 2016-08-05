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
	int T, N, M, x, y;
	cin >> T;
	while(T--) {
		cin >> N;
		vii v;
		for(int i = 0; i < N; i++){
			cin  >> x >> y;
			v.push_back(mp(x,y));
		}
		vector<pair<double,ii> > g;
		for(int i = 0; i < N;i++) {
			for(int j = i+1; j < N; j++){
				double dis = distance(v[i],v[j]);
				g.push_back(mp(dis,mp(i,j)));
			}
		}
		sort(all(g));
		UnionFind uf(N);
		cin >> M;
		for(int i = 0; i < M;i++){
			cin >> x >> y;
			uf.Union(x-1,y-1);
		}
		bool f = 0;
		for(int i = 0; i < g.size(); i++) {
			if(!uf.isSame(g[i].second.first,g[i].second.second)){
				cout << g[i].second.first+1 << " "
					 << g[i].second.second+1 << endl;
				uf.Union(g[i].second.first,g[i].second.second);
				f = 1;
			}
		}
		if(!f)cout << "No new highways need" << endl;
		if(T)cout << endl;
	}
	return 0;
}
