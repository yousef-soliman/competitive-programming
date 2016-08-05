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
using namespace std;
int N,M;
bool isValid(int r,int c){
	return (r < N && r >= 0 && c < M && c >= 0);
}
int main(){
	int R,r, numC, c;
	int x,y,xs,ys,xt,yt;
	int map[1000][1000];
	int dist[1000][1000];
	while(cin >> N >> M && N && M) {
		memset(map,0,sizeof(map));
		memset(dist,-1,sizeof(dist));
		cin >> R;
		while(R--) {
			cin >> r >> numC;
			while(numC--) {
				cin >> c;
				map[r][c] = 1;
			}
		}
		cin >> xs >> ys;
		cin >> xt >> yt;
		queue<ii>q;
		q.push(ii(xs,ys));
		dist[xs][ys] = 0;
		while(!q.empty()){
			ii p = q.front();
			x = p.first;
			y = p.second;
			q.pop();
			for(int i = 0; i < 4; i++) {
				if(isValid(x+dr[i],y+dc[i]) && !map[x+dr[i]][y+dc[i]] && dist[x+dr[i]][y+dc[i]] == -1) {
					dist[x+dr[i]][y+dc[i]] = dist[x][y] + 1;
					q.push(ii(x+dr[i],y+dc[i]));
				}
			}
		}
		cout << dist[xt][yt] << endl;
	}
	return 0;
}
