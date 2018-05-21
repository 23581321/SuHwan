#include <stdio.h>

int main(void)
{
	int n, newStair, max=0;
	int score[300]={0, };
	int stair[300][3]={0, };
	scanf("%d",&n);
	for(int i=n-1 ; i>=0 ; i--){
		scanf("%d",&score[i]);
	}
	stair[1][0] = score[0];
	stair[1][2] = score[0]+score[1];
	for(int j=2 ; j<n ; j++){
		stair[j][0] = stair[j-1][2];
		stair[j][1] = stair[j-1][0]+score[j];
		if(stair[j][0] <= stair[j-1][1]){
			stair[j][0] = stair[j-1][1];
		}
		newStair = stair[j-1][1] + score[j];
		if(stair[j][2] <= newStair){
			stair[j][2] = newStair;
		}
	}
	for(int k=0 ; k<3 ; k++){
		if(max <= stair[n-1][k]){
			max = stair[n-1][k];
		}
	}
	printf("%d\n",max);
	return 0;
}
