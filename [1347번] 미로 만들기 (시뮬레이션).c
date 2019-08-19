#include<stdio.h>

int dir = 2;
//		북0 
//서3			동1
//		남2 

int N;
int y = 50, x = 50;
int map[110][110]; 
//0은 빈곳 , 1은 지난 곳 

void turnRight() {
	
	dir = (dir + 1) % 4;	
}

void turnLeft() {
	
	dir = (dir + 4 - 1) % 4;	
}

void move() {
	
	switch(dir) {
		case 0:
			y--;
			break;
		case 1:
			x++;
			break;
		case 2:
			y++;
			break;
		case 3:
			x--;
			break;	
	}
	
	map[y][x] = 1;
}

void printMap() {
	
	int maxY = 50, maxX = 50;
	int minY = 50, minX = 50;
	
	for(int i=1 ; i<110 ; ++i) {
		for(int j=1 ; j<110 ; ++j) {
			if(map[i][j] == 1) {
				if(i < minY) minY = i;
				if(i > maxY) maxY = i;
				if(j < minX) minX = j;
				if(j > maxX) maxX = j;
			}
		}
	}
	
	for(int i=minY ; i<=maxY ; ++i) {
		for(int j=minX ; j<=maxX ; ++j) {
			if(map[i][j] == 1) printf(".");
			else printf("#");
		}
		printf("\n");
	}
}

int main() {
	
	map[50][50] = 1;
	
	scanf("%d", &N);
		getchar();
	
	while(N--) {
		char ch;
		scanf("%1c", &ch);
		
		if(ch == 'R')
			turnRight();
		else if(ch == 'L')
			turnLeft();
		else
			move();
	}
	
	printMap();
}
