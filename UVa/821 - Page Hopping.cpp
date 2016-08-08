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
#define INF 1<<29 
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
	int x, y;
	int t = 0;
	while(cin >> x >> y && x && y) {
		t++;
		vector<vi> g(100,vi(100,INF));
		for(int i = 0; i < 100; i++) {
			g[i][i] = 0;
		}
		g[x-1][y-1] = 1;
		while(cin >> x >> y && x && y) {
			g[x-1][y-1] = 1;
		}
		for(int k = 0; k < 100; k++)
			for(int i = 0; i < 100; i++)
				for(int j = 0; j < 100; j++)
					g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
		int sum = 0;
		int cnt = 0;
		for(int i = 0; i < 100; i++) {
			for(int j = 0; j < 100; j++) {
				if(g[i][j] && g[i][j] != INF) {
					sum += g[i][j];
					cnt++;
				}
			}
		}
		printf("Case %d: average length between pages = %.3f clicks\n",t,sum*1.0/cnt);
	}
	return 0;
}
