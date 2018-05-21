#include <stdio.h>

int main(void)
{
	int n, k, coin;
	int arr[100000] = {0, };
	scanf("%d %d",&n ,&k);
	for(int i=0 ; i<n ; i++){
		scanf("%d", &coin);
		arr[coin] += 1;
		int index = 0;
		while(index + coin <= k){
			arr[index + coin] += arr[index];
			index += 1;
		}
	}
	printf("%d\n", arr[k]);
	return 0;
}
