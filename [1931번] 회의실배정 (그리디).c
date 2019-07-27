#include<stdio.h>
typedef struct {
	int start;
	int end;
} Meeting;

Meeting time[100001];
int N;
int count = 0;
int endTime = 0;

int compareMeeting(void* a, void* b) {
	if((*(Meeting*)a).end == (*(Meeting*)b).end)
		return ((*(Meeting*)a).start > (*(Meeting*)b).start) * 2 -1;
	else
		return ((*(Meeting*)a).end > (*(Meeting*)b).end) * 2 -1;
}

int main() {

	scanf("%d", &N);
	for(int i=0 ; i<N ; ++i) {
		scanf("%d%d", &time[i].start, &time[i].end);
	}
	
	qsort(time, N, sizeof(Meeting), compareMeeting);
	
	for(int i=0 ; i<N ; ++i) {
		if(endTime <= time[i].start) {
			endTime = time[i].end;
			count++;
		}
	}
	
	printf("%d", count);
}
