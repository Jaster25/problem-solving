#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define MIN(a,b) (a<b ? a : b)

int N;
int stats[21][21];

int total, min;
bool team1[21];

int findDiff() {
	
	int team1Score = 0;
	int team2Score = 0;
	
	for(int i=1 ; i<=N ; ++i)
		for(int j=1 ; j<=N ; ++j)
			if(team1[i] == true && team1[j] == true)
				team1Score += stats[i][j];
	
	for(int i=1 ; i<=N ; ++i)
		for(int j=1 ; j<=N ; ++j)
			if(team1[i] == false && team1[j] == false)
				team2Score += stats[i][j];
	
	int diff = abs(team1Score - team2Score);
	
	return diff;
}

void makeTeam(int cnt, int team1cnt) {
	
	if(cnt == N)
		min = MIN(min, findDiff());
	
	else {
		int team2cnt = cnt - team1cnt;
		
		if(team1cnt < N/2) {
			team1[cnt] = true;
			makeTeam(cnt+1, team1cnt+1);
		}
		
		if(team2cnt < N/2) {
			team1[cnt] = false;
			makeTeam(cnt+1, team1cnt);
		}
	}
}

int main() {
	
	scanf("%d", &N);
	
	for(int i = 1 ; i <= N ; ++i) {
		for(int j = 1 ; j <= N ; ++j) {
			scanf("%d", &stats[i][j]);
			total += stats[i][j];
		}
	}

	min = 999999999;
	makeTeam(0,0);
			
	printf("%d", min);	
}
