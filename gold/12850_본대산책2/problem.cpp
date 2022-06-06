#include <stdio.h> 
#include <vector>
#include <utility>
#include <queue>
#include <string.h>
#include <map>
#include <math.h>

using namespace std;

long long mod = 1000000007;



long long mat[8][8] = {
	//0, 1, 2, 3, 4, 5, 6, 7
	{0, 1, 1, 0, 0, 0, 0, 0},
	{1, 0, 1, 1, 0, 0, 0, 0},
	{1, 1, 0, 1, 1, 0, 0, 0},
	{0, 1, 1, 0, 1, 1, 0, 0},
	{0, 0, 1, 1, 0, 1, 0, 1},
	{0, 0, 0, 1, 1, 0, 1, 0},
	{0, 0, 0, 0, 0, 1, 0, 1},
	{0, 0, 0, 0, 1, 0, 1, 0}
};

long long ansmat[8][8] = {
	{0, 1, 1, 0, 0, 0, 0, 0},
	{1, 0, 1, 1, 0, 0, 0, 0},
	{1, 1, 0, 1, 1, 0, 0, 0},
	{0, 1, 1, 0, 1, 1, 0, 0},
	{0, 0, 1, 1, 0, 1, 0, 1},
	{0, 0, 0, 1, 1, 0, 1, 0},
	{0, 0, 0, 0, 0, 1, 0, 1},
	{0, 0, 0, 0, 1, 0, 1, 0}
};

void sqr(){
	long long newmat[8][8];
	
	for(int i=0; i<8; i++) {
		for(int j=0; j<8; j++) {
			newmat[i][j] = 0;
			for(int k=0; k<8; k++) {
				newmat[i][j] = (newmat[i][j] + ansmat[i][k] * ansmat[k][j]) % mod;
			}
		}
	}
	
	for(int i=0; i<8; i++) {
		for(int j=0; j<8; j++) {
			ansmat[i][j] = newmat[i][j];
		}
	}
	
}

void mult(){
	long long newmat[8][8];
	
	for(int i=0; i<8; i++) {
		for(int j=0; j<8; j++) {
			newmat[i][j] = 0;
			for(int k=0; k<8; k++) {
				newmat[i][j] = (newmat[i][j] +  ansmat[i][k] * mat[k][j] ) % mod;
			}
		}
	}
	
	for(int i=0; i<8; i++) {
		for(int j=0; j<8; j++) {
			ansmat[i][j] = newmat[i][j];
		}
	}
	
}

void matpow(int n) {
	if (n == 1) {
		return;
	}
	
	if (n%2 == 0) {
		matpow(n/2);
		sqr();
	}
	else {
		matpow((n-1)/2);
		sqr();
		mult();
	}
	
	
}

void printansmat() {
	for(int i=0; i<8; i++) {
		for(int j=0; j<8; j++) {
			printf("%lld ", ansmat[i][j]);
		}
		printf("\n");
	}
}


int main() {
	
	int D;
	
	scanf("%d", &D);
	
	matpow(D);
	
	printf("%d", ansmat[0][0]);
	
}

