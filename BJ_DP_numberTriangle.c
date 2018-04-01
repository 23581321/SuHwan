#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d" , &n); 
	int triangle[n][n]; // n의 크기를 가지는 삼각형을 저장할 배열
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<=i ; j++){
			scanf("%d" , &triangle[i][j]);
		}
	} // 삼각형에 들어갈 숫자를 입력받고 배열에 저장한다.
	for(int k=n-2 ; k>=0 ; k--){
		for(int s=0 ; s<=k ; s++){
			if(triangle[k+1][s] >= triangle[k+1][s+1]){
				triangle[k][s] += triangle[k+1][s];
			} else{
				triangle[k][s] += triangle[k+1][s+1];
			}
		}
	} // n-2번째 행에서부터, 선택 할 수 있는 두 수중, 큰 수를 더해가며 올라온다.
	printf("%d\n" , triangle[0][0]); // 삼각형의 꼭대기에 저장된 수가 최대값이므로, 배열의 첫번째 수를 출력한다.
	return 0;
} // 삼각형의 위에서부터 더해서 내려오는 방식이 아니라, 밑에서부터 합을 쌓아 올려 나간다고 생각하자
  // n의 크기를 가진 삼각형에서 n-1번째 줄의 숫자들을 보자. n-1번째 줄의 숫자 하나가 선택할 수
  // 있는 숫자는 대각선 왼쪽 또는 오른쪽 아래의 숫자 둘 중 하나를 고를수 있다.
  // 최대값을 구해야 하는 문제이므로 둘 중 더 큰 수를 더하고, 같은 방식으로 n-2, n-3 ... 1번쨰
  // 줄까지 큰 수를 택하며 합한 결과가 최대값이 된다.
