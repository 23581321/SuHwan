#include <stdio.h>

int main(void)
{
	int t, n;
	int fibonacci[41][2]={0, }; // 값을 저장할 2차원 배열 생성
	fibonacci[0][0]=1;
	fibonacci[1][1]=1; // f(1)과 f(0)에서의 0과 1을 출력하는 횟수 설정
	for(int i=2 ; i<41 ; i++){
		fibonacci[i][0] = fibonacci[i-2][0] + fibonacci[i-1][0];
		fibonacci[i][1] = fibonacci[i-2][1] + fibonacci[i-1][1];
	} // 40번째 피보나치 수까지 0과 1을 출력하는 횟수를 저장
	scanf("%d",&t);
	int answer[t][2]; // 정답을 출력할 때 이용할 배열
	for(int j=0 ; j<t ; j++){
		scanf("%d",&n);
		answer[j][0] = fibonacci[n][0];
		answer[j][1] = fibonacci[n][1];
	} // 테스트케이스의 수 만큼 n의 값을 입력받고, n의 값에 맞는 출력 횟수를 배열에 저장
	for(int k=0 ; k<t ; k++){
		printf("%d %d\n", answer[k][0], answer[k][1]);
	} // 정답을 출력
	return 0;
} // n번째 피보나치 수를 재귀로 구하는 함수를 f(n)이라 하자. f(2)를 구하려면 f(1)과 f(0)을 호출해야
  // 하고, f(3)을 구하려면 f(2)와 f(1)을 호출해야 한다. 먼저 f(2)를 보자, f(2)를 호출했을 때
  // 0과 1이 출력되는 횟수는 f(1)을 호출했을 때의 0과 1의 출력 횟수와 f(0)을 출력했을 때의
  // 0과 1의 출력 횟수를 더한것과 같다. 마찬가지로 f(3)을 호출했을 때 0과 1이 출력되는 횟수는
  // f(2)와 f(1)을 호출했을 때의 0과 1의 출력횟수를 더한것과 같으므로 피보나치 수열과 같은 방식으로
  // 값을 저장하며 더해 나가면 된다. 최대 40번째 피보나치 수에서의 0과 1의 출력 횟수를 구하는
  // 문제이므로 40번째의 행과 0번째와 1번째 열을 가지는 배열을 만든다. 여기서 행은 n번째 피보나치 수를
  // 의미하며, 0번째 열과 1번째 열은 각각 0이 출력되는 횟수, 1이 출력되는 횟수를 의미한다.
	
