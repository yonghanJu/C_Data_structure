#include <stdio.h>
#include <stdlib.h>

// 일반적인 피보나치 함수 
long pib(int num)
{
	if(num ==0 ||num ==1 ) return 1;
	else{
		return pib(num-1) + pib(num-2);
	}
}

// 배열을 활용한 개선된 피보나치 함수 
long improvedPib(int num, long* arr)
{
	if(num ==0 ||num ==1 ) return 1;
	else{
		// 한번만 재귀호출 실행 
		// 포인터를 활용한 배열에 각 항 값들을 저장 
		return  *(arr+num) = improvedPib(num-1, arr) + *(arr+num-2);
	}
}

// 배열을 선언해주고 메인함수 간략화해주는 함수 
long pb(int num)
{
	//배열을 선언하고 0번쨰, 1번째 항에 1을 저장 
	long *arr =(long*)malloc((num+1)*sizeof(long));
	*arr=1;
	*(arr+1)=1;
	
	return improvedPib(num, arr);
	free(arr);
}

/* 자연수 n 을 입력 받으면 기존 피보나치 함수와
 향상된 피보나치 함수를 각각 실행하고 결과를 보여주는 프로그램*/ 
int main(void)
{	
	int n;
	char c;
	while(1)
	{
		printf("수열 중 구할 n항을 입력.\n");
		scanf("%d",&n);
		printf("향상된 피보나치 함수 : \n");
		printf(" %ld\n\n",pb(n));
		
		printf("기존 피보나치 함수 : \n");
		printf(" %ld\n",pib(n));
		printf("작업을 계속 하시겠습니까? (Y)\n");
		getchar();
		scanf("%c",&c);
		if (c=='y' || c=='Y') continue;
		else return 0;
	}
	return 0;
}