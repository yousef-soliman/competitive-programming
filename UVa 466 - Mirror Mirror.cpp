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
using namespace std;
typedef long long ll;

int main() {
	char org[10][10];
	char eff[10][10];
	int N;
	int T = 0;
	while(cin >> N) {
		T = T+1;
		getchar();
		for(int i = 0;i < N; i++){
			for(int j = 0; j < N; j++) {
				scanf("%c", &org[i][j]);
			}
			getchar();
			for(int j = 0; j < N; j++) {
				scanf("%c", &eff[i][j]);
			}
			getchar();
		}
		bool f = 1;
		for(int i = 0 ;i < N; i++){
			for(int j = 0; j < N; j++) {
				if(eff[i][j] != org[i][j]) {
					f = 0;
					break; 
				}
			}
		}
		if( f == 1){
			printf("Pattern %d was preserved.\n", T);
			continue;
		}
		f = 1;
		for(int i = 0;i < N && f; i++){
			for(int j = 0, k = N-1; j < N; j++, k--) {
				if(eff[i][j] != org[k][i]) {
					f = 0;
					break; 
				}
			}
		}
		if( f == 1){
			printf("Pattern %d was rotated 90 degrees.\n", T);
			continue;
		}
		f = 1;
		for(int i = 0,m = N-1 ;i < N && f; i++, m--){
			for(int j = 0, k = N-1; j < N; j++, k--) {
				if(eff[i][j] != org[m][k]){
					f = 0;
					break; 
				}
			}
		}
		if( f == 1){
			printf("Pattern %d was rotated 180 degrees.\n", T);
			continue;
		}
		f = 1;
		for(int i = 0,m = N-1 ;i < N; i++, m--){
			for(int j = 0, k = N-1; j < N; j++, k--) {
				if(eff[i][j] != org[j][m]) {
					f = 0;
					break; 
				}
			}
		}
		if( f == 1){
			printf("Pattern %d was rotated 270 degrees.\n", T);
			continue;
		}
		f = 1;
		char vert[10][10];
		for(int i = 0,m = N-1 ;i < N; i++, m--){
			for(int j = 0, k = N-1; j < N; j++, k--) {
				vert[i][j] = org[m][j];
			}
		}
		
		for(int i = 0,m = N-1 ;i < N && f; i++, m--){
			for(int j = 0, k = N-1; j < N; j++, k--) {
				if(vert[i][j] != eff[i][j]) {
					f = 0;
					break;
				}
			}
		}
		if( f == 1){
			printf("Pattern %d was reflected vertically.\n", T);
			continue;
		}
		f = 1;
		for(int i = 0;i < N && f; i++){
			for(int j = 0, k = N-1; j < N; j++, k--) {
				if(vert[i][j] != eff[k][i]) {
					f = 0;
					break; 
				}
			}
		}
		if( f == 1){
			printf("Pattern %d was reflected vertically and rotated 270 degrees.\n", T);
			continue;
		}
		f = 1;
		for(int i = 0,m = N-1 ;i < N && f; i++, m--){
			for(int j = 0, k = N-1; j < N; j++, k--) {
				if(vert[i][j] != eff[m][k]){
					f = 0;
					break; 
				}
			}
		}
		if( f == 1){
			printf("Pattern %d was reflected vertically and rotated 180 degrees.\n", T);
			continue;
		}
		f = 1;
		for(int i = 0,m = N-1 ;i < N; i++, m--){
			for(int j = 0, k = N-1; j < N; j++, k--) {
				if(vert[i][j] != eff[j][m]) {
					f = 0;
					break; 
				}
			}
		}
		if( f == 1){
			printf("Pattern %d was reflected vertically and rotated 90 degrees.\n", T);
			continue;
		}
		printf("Pattern %d was improperly transformed.\n",T);
	}
}


