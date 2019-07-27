#include<stdio.h>
#define SIZE 1000
typedef struct
{
	int og_index;
	int personal_time;
	int total_time;
}person;

//퀵정렬 이용하기 
int Partition(person *list, int st, int end)
{
	int pivot = list[end].personal_time; 
	int index=st;
	
	for(int i=st ; i<end ; ++i)
	{
		//퀵정렬 조건 부등호 조심 
		if(pivot > list[i].personal_time)
		{
			person temp;
			temp = list[i];
			list[i] = list[index];
			list[index] = temp;
			
			index++;
		}
	}
	
	person temp;
	temp = list[end];
	list[end] = list[index];
	list[index] = temp;
	
	return index;
}

void Quick(person *list, int st, int end)
{
	if(st<end)
	{
		int index = Partition(list, st, end);
		Quick(list, st, index-1);
		Quick(list, index+1, end);
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	
	int Min=0;
	person list[SIZE];
	
	for(int i=0 ; i<N ; ++i)
	{
		list[i].og_index = i;
		list[i].total_time=0;
		scanf("%d", &list[i].personal_time);
	}
	
	//퀵정렬
	Quick(list, 0, N-1); 
	
	for(int i=0 ; i<N ; ++i)
	{
		for(int j=0; j<=i ; ++j)
		{
			list[i].total_time += list[j].personal_time;
		}
		Min += list[i].total_time;
	}
	
	printf("%d", Min);
}
