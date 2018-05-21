#include <stdio.h>

int main(void)
{
	int n, number, sum, max, temp;
	scanf("%d",&n);
	scanf("%d",&sum);
	max = sum;
	for(int i=1 ; i<n ; i++){
		scanf("%d", &number);
		if(sum < 0){
			sum = number;
		} else {
			sum += number;
		}
		if(sum > max){
			max = sum;
		}
	}
	printf("%d\n", max);
	return 0;
}
