#include <stdio.h>

int main(void)
{
	int n, cost, minCost=1000000;
	scanf("%d" , &n);
	int paintingCost[n][3]; // 값을 저장할 배열을 만든다. n은 집의 개수, 3은 색깔의 개수다.
	scanf("%d" , &paintingCost[0][0]); 
	scanf("%d" , &paintingCost[0][1]); 
	scanf("%d" , &paintingCost[0][2]); // 점화식의 적용, 반복이 두번째 행부터 진행되므로 초기값은 직접 입력받는다.
	for(int i=1 ; i<n ; i++){ // i번째 집을 색칠한다. n번째 집까지 반복한다.
		for(int j=0 ; j<3 ; j++){ // j=0일때는 빨간색, 1일때는 초록색, 2일때는 파란색으로 i번째 집을 색칠하는 경우이다.
			scanf("%d" , &cost); // 도색에 드는 비용을 입력받는다.
			if(paintingCost[i-1][(j+1)%3] >= paintingCost[i-1][(j+2)%3]){
				paintingCost[i][j] = paintingCost[i-1][(j+2)%3] + cost;
			} else {
				paintingCost[i][j] = paintingCost[i-1][(j+1)%3] + cost;
			} // i번째 집을 칠할때 더할수 있는 경우는 i번째 집과 다른 2개의 색이다. 2개중 작은 값을 새로 입력받은 도색 비용과 더한것이 최소 비용이 되고 이를 저장한다.
		}
	} // ppt에서 설명한 알고리즘의 구현
	for(int k=0 ; k<3 ; k++){ 
		if(minCost >= paintingCost[n-1][k]){
			minCost = paintingCost[n-1][k];
		}
	} // 마지막 집을 각각 빨간색, 초록색, 파란색으로 칠한 경우 중 가장 작은 값이 최소 비용이 된다.
	printf("%d\n" , minCost);
	return 0;
} 
// 주석만 달면 설명이 부족할 수 있으니까, 요기에다가 알고리즘에 대한 전체적인 설명을 넣어주셈
// 이 문제는 ppt에 알고리즘 써놨으니까 까먹었으면 다시보고, 이해안되면 물어보셈
