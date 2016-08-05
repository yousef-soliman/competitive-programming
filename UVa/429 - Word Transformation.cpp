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
int dis(string s,string s1) {
	if(s.size() != s1.size()) return -1;
	int N = s.size();
	int cnt = 0;
	for(int i = 0; i < N; i++) {
		if(s[i] != s1[i]){
			cnt++;	
		}
	}
	return cnt;
}
int main(){
	int T;
	cin >> T;
	getchar();
	string s;
	while(T--) {
		
		map <string,int> m;
		int cnt = 0;
		vs v;
		while(cin >> s){
			if(s == "*") break;
			m[s] = cnt++;
			v.push_back(s);
		}
		vvi g(v.size());
		
		for(int i = 0;i < v.size(); i++) {
			for(int j = 0; j < v.size(); j++) {
				if(dis(v[i],v[j]) == 1){
					g[m[v[i]]].push_back(m[v[j]]);
				}
			}
		}
		getchar();
		string src,tin;
		while(gl(s)) {
			vi dist(v.size(),-1);
			if(s.size() == 0) break;
			stringstream ss;
			ss << s;
			ss >> src;
			ss >> tin;
			queue<int> q;
			q.push(m[src]);
			dist[m[src]] = 0;
			bool f = 1;
			while(!q.empty() && f) {
				int u = q.front();
				q.pop();
				for(int i = 0; i < g[u].size(); i++) {
					int v = g[u][i];
					if(dist[v] == -1) {
						dist[v] =dist[u]+1;
						q.push(v);
					}
					if(v == m[tin]) {
						f = 0;
						break;
					}
				}
			}
			cout << src << " " << tin << " " << dist[m[tin]] << endl;
		}
		if(T)
		cout << endl;
	}
	return 0;
}
