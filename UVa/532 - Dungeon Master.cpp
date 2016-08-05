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
int N, M, Z;
bool isValid(int z,int x, int y) {
	return (z >= 0 && z < Z && x < N && x >= 0 && y >= 0 && y < M);
}
int main(){
	char map[30][30][30];
	int dist[30][30][30];
	int sX,sY,sZ;
	int tX,tY,tZ;
	while(cin >> Z >> N >> M && N && M && Z) {
		memset(dist,-1,sizeof(dist));
		getchar();
		for(int i = 0; i < Z; i++) {
			for(int j = 0; j < N; j++){
				for(int k = 0;k < M; k++) {
					scanf("%c",&map[i][j][k]);
					if(map[i][j][k] == 'S'){
						sZ = i;
						sX = j;
						sY = k;
					}
					if(map[i][j][k] == 'E'){
						tZ = i;
						tX = j;
						tY = k;
					}
				}
				getchar();
			}
			getchar();
		}
		queue<pair<int,ii> > q;
		q.push(mp(sZ,mp(sX,sY)));
		dist[sZ][sX][sY] = 0;
		int x,y,z;
		while(!q.empty()) {
			pair<int,ii> p = q.front();
			q.pop();
			z = p.first;
			x = p.second.first;
			y = p.second.second;
			for(int i = 0; i < 2; i++) {
				if(isValid(z+dt[i],x,y) && map[z+dt[i]][x][y]!= '#' && dist[z+dt[i]][x][y] == -1) {
					dist[z+dt[i]][x][y] = dist[z][x][y] + 1;
					q.push(mp(z+dt[i],mp(x,y)));
				}
			}
			for(int i = 0; i < 4; i++) {
				if(isValid(z,x+dr[i],y+dc[i]) && map[z][x+dr[i]][y+dc[i]] != '#' && dist[z][x+dr[i]][y+dc[i]] == -1) {
					dist[z][x+dr[i]][y+dc[i]] = dist[z][x][y] + 1;
					q.push(mp(z,mp(x+dr[i],y+dc[i])));
				}
			}
		}
		if(dist[tZ][tX][tY] != -1) {
			printf("Escaped in %d minute(s).\n",dist[tZ][tX][tY]);
		}
		else {
			cout <<"Trapped!"<< endl;
		}
	}
	return 0;
}
