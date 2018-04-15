#include <stdio.h>
#include <stdlib.h> // 퀵정렬 쓸려면 선언해야됨

int compare(const void *a, const void *b){
	int num1 = *(int *)a;
	int num2 = *(int *)b;
	
	if(num1 < num2){
		return 1;
	}
	if(num1 > num2){
		return -1;
	}
	return 0;
} // 퀵정렬을 사용하기 위해 정의한 비교함수

int main(void)
{
	int n, max;
	scanf("%d" , &n);
	int rope[n]; // 값을 저장하기 위한 배열
	for(int i=0 ; i<n ; i++){
		scanf("%d" , &rope[i]);
	} // 로프가 버틸 수 있는 무게를 입력받고 배열에 저장한다.
	qsort(rope, sizeof(rope) / sizeof(int), sizeof(int), compare); // 오름차순으로 정렬한다.
	max = rope[0];
	for(int j=1 ; j<n ; j++){
		rope[j] = rope[j]*(j+1); // 오름차순으로 정렬했으므로 새로운 로프가 최소 무게가 된다.
		if(max < rope[j]){
			max = rope[j];
		} // 계산한 값 최대값보다 크다면 max 변수에 새로운 값 저장
	} 
	printf("%d\n",max); // 최대값 출력
	return 0;
} // 로프가 버틸수 있는 최대 무게는 (사용한 로프의 수)*(사용한 로프 중 가장 약한 로프가 버티는 무게) 
  // 이다. 로프의 수가 많을수록, 가장 약한 로프가 버티는 무게가 클 수록 최대가 되므로, 버틸 수 있는
  // 무게가 큰 로프부터 매달면서 계산한 값 중 가장 큰 값이 최대값이 된다.
