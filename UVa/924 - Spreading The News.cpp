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
	int N, E, x;
	cin >> E;
	vvi g(E);
	
	for(int i = 0; i < E; i++) {
		cin >> N; 
		for(int j = 0; j  < N; j++) {
			cin >> x;
			g[i].push_back(x);
		}
	}
	int T;
	cin >> T;
	while(T--) {
		vi dist(E,-1);
		cin >> N;
		queue<int> q;
		q.push(N);
		int c = 0;
		vi day(400,0);
		dist[N] = 0;
		while(!q.empty()){
			int u = q.front();
			q.pop();
			
			int cnt = 0;
			for(int i = 0; i < g[u].size(); i++) {
				int v = g[u][i];
				if(dist[v] == -1) {
					cnt++;
					dist[v] = dist[u]+1;
					day[dist[v]]++;
					q.push(v);
				}
			}
		}
		int mx = mmn;;
		int indx;
		for(int  i = 0; i < day.size(); i++) {
			if(mx < day[i]){
				indx = i;
				mx = day[i];
			}
		}
		if(mx) {
			cout << mx << " " << indx << endl;
		}
		else 
			cout << 0 << endl;
		
	}
	
	return 0;
}
