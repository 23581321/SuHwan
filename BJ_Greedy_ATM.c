#include <stdio.h>
#include <stdlib.h> // 퀵정렬 쓸려면 선언해야됨 그리디 알고리즘이 핵심이니까 퀵정렬은 검색 ㄱㄱ

int compare(const void *a, const void *b)
{
	int num1 = *(int *)a;
	int num2 = *(int *)b;

	if(num1 < num2){
		return -1;
	}
	if(num1 > num2){
		return 1;
	}
	return 0;
} // 퀵정렬을 사용하기 위해 정의하는 비교함수 퀵정렬은 구글링 ㄱㄱ

int main(void)
{
	int n, sum=0;
	scanf("%d" , &n);
	int time[n]; // 입력받은 시간들을 저장할 배열
	for(int i=0 ; i<n ; i++){
		scanf("%d" , &time[i]);
	} 
	qsort(time, sizeof(time) / sizeof(int), sizeof(int), compare); // 오름차순으로 정렬
	for(int j=0 ; j<n ; j++){
		sum = sum + (time[j]*(n-j));
	} // 최소값을 구하는 반복문, (n-j)는 그 수가 더해지는 횟수를 의미함
	printf("%d\n" , sum);
	return 0;
} // 이 문제에서 입력받는 시간들은 한번 더하면 계속 더해야 하므로, 최소값을 구하려면
  // 작은 수 부터 더해야 한다. 입력받은 값을 배열에 저장하고 퀵정렬을 사용하여 오름차순으로 정리한다.
  // 배열의 맨 앞부터 더해가며 값을 저장하면 최소값이 나온다.
