/*
Nama            :   Fauzan Akmal Hariz
NPM             :   140810180005
Kelas Kuliah    :   A
Kelas Praktikum :   B
Nama Program    :   Algoritma Gale-Shapley (GS) - Stable Matching Problem
*/

#include <iostream>

using namespace std;

const int N = 5;
string M_name[N] = {"Victor", "Wyatt", "Xavier", "Yancey", "Zeus"};
string W_name[N] = {"Amy", "Bertha", "Clare", "Diane", "Erika"};

int M_preference[N][N] = {
	{1, 0, 3, 4, 2},
	{3, 1, 0, 2, 4},
	{1, 4, 2, 3, 0},
	{0, 3, 2, 1, 4},
	{1, 3, 0, 4, 2},
};

int W_preference[N][N] = {
	{4, 0, 1, 3, 2},
	{2, 1, 3, 0, 4},
	{1, 2, 3, 4, 0},
	{0, 4, 3, 2, 1},
	{3, 1, 4, 2, 0},
};

int stable[N][2];
bool M_match[N];
bool W_match[N];

int getManMatch(int woman) {
	
	for (int i=0; i<N; i++) {
		if (stable[i][1]==woman) {
			return stable[i][0];
			break;
		}
	}

	return -1;
}

int getPreferenceLevel(int woman, int man) {
	
	for (int i=0; i<N; i++){
		if (W_preference[woman][i]==man){
			return i;
			break;
		}
	}
	
	return -1;
}

void matchingProcess(int M, int W) {

	stable[M][0] = M;
	stable[M][1] = W;
	M_match[M] = true;
	W_match[W] = true;
}

void traversalMatch() {
	
	cout<<"\nHasil Stable Matching:\n\n";
	cout<<"{\n";
	for (int i=0; i<N; i++){
		if (i!=0) {
			cout<<", \n";
		}
		cout<<"\t("<<M_name[stable[i][0]]<<", "<<W_name[stable[i][1]]<<")";
	}
	cout<<"\n}\n";
}

int main() {
	
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++){
			int M = j;
			if (M_match[M]==false) {
				int W = M_preference[M][i];
				if (W_match[W]==true) {
					int xM = getManMatch(W);
					int xM_prep = getPreferenceLevel(W,xM);
					int M_prep = getPreferenceLevel(W,M);
					if (M_prep<xM_prep) {
						matchingProcess(M,W);
						M_match[xM] = false;
						stable[xM][1] = -1;
						continue;
					} 
					else {
						continue;
					}
				} 
				else {
					matchingProcess(M,W);
					continue;
				}
			} 
			else {
				continue;
			}
		}
	}
	
	traversalMatch();
}