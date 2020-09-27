#include<stdio.h>
#include<math.h>
#include<stdbool.h>

int N, count;
int map[16];

bool check(int index) {

    for(int i=0 ; i<index ; i++) {
        if(map[i] == map[index] || abs(map[index] - map[i]) == (index - i))
            return false;
    }
    
    return true;
}

void queen(int index) {
	
	if(index == N)
        count++;
    
	else {
        for(int i=0 ; i<N ; i++) {
            map[index] = i;
    
	        if(check(index))
                queen(index + 1);
        }
    }
}


int main() {
	
	scanf("%d", &N);	
	
	queen(0);
	
	printf("%d", count);
}
