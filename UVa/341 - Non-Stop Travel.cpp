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
vvi p(100,vi(100));
void printPath(int i, int j) {
	if (i != j) printPath(i, p[i][j]);
	printf(" %d", j+1);
}
int main(){
	int N, n, x, d,y;
	int t = 0;
	while(cin >> N && N) {
		t++;
		vector<vector<ll> > adjMat(100,vector<ll>(100,mmx));
		
		for(int i = 0; i < p.size();i++){
			for(int j = 0; j < p.size();j++) {
				p[i][j] = i;
			}
		}
		for(int i = 0; i < N; i++) {
			cin >> n;
			adjMat[i][i] = 0;
			for(int j = 0; j < n; j++) {
				cin >> x >> d;
				adjMat[i][x-1] = d;
			}
		}
		for(int k = 0; k < N; k++) {
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < N; j++) {
					if(adjMat[i][j] > adjMat[i][k]+adjMat[k][j]){
						adjMat[i][j] = adjMat[i][k]+adjMat[k][j];
						p[i][j] = p[k][j];
					}
				}
			}
		}
		cin >> x >> y;
		printf("Case %d: Path =",t);
		printPath(x-1,y-1);
		printf("; ");
		cout << adjMat[x-1][y-1];
		cout << " second delay" << endl;
	}
	return 0;
}
