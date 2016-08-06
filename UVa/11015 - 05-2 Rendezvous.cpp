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
	int N, M, x, y, d;
	string s;
	int t = 0;
	while(cin >> N >> M &&N) {
		
		t++;
		vs v;
		vector<vi> adjMat(N,vi(N,INF));
		for(int i = 0 ; i < N; i++) {
			cin >> s;
			adjMat[i][i] = 0;
			v.push_back(s);
		}
		for(int i = 0; i < M; i++) {
			cin >> x >> y >> d;
			adjMat[x-1][y-1] = d;
			adjMat[y-1][x-1] = d;
		}	
		for(int k = 0; k < N; k++)
			for(int i = 0; i < N; i++)
				for(int j = 0; j < N; j++)
					adjMat[i][j] = min(adjMat[i][j],adjMat[i][k]+adjMat[k][j]);
		
		
		int res = mmx;
		int indx;
		int sum = 0;
		for(int i = 0; i < N;i++) {
			sum = 0;
			for(int j = 0; j < N; j++) {
				if(adjMat[i][j] && adjMat[i][j] != INF) {
					sum += adjMat[i][j];
				}
			}
			if(res > sum) {
				res = sum;
				indx = i;
			}
		}
		
		printf("Case #%d : ",t);
		cout << v[indx]<< endl;
	}
	return 0;
}
