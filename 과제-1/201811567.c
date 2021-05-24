#include <stdio.h>
#include <stdlib.h>
/*제목 :  향상된 피보나치 재귀함수
 생성자 : 주용한
 생성 날짜: 2021.03.06 (2020.03.20 수정)
 코드 설명 : 일반적인 피보나치 함수와 성능을 개선 시킨 피보나치 함수를 만들어 
 			일반->개선  순으로 n번째 항까지의 값을 출력해 준다 */ 
 			
// 일반적인 피보나치 함수 
long pib(int num)
{
	if(num ==0) return 0;
	else if(num ==1 ) return 1;
	else{
		return pib(num-1) + pib(num-2);
	}
}

// 배열을 활용한 개선된 피보나치 함수 
long improvedPib(int num, long* arr)
{
	if(num ==0) return 0; 
	else if(num ==1) return 1;
	else{
		/* 한번만 재귀호출 실행  
		   배열에 각 항 값들을 저장*/ 
		return  *(arr+num) = improvedPib(num-1, arr) + *(arr+num-2);
	}
}

//배열을 선언해주고 메인함수 간략화해주는 함수 
long pb(int num)
{
	//포인터를 이용한 배열을 선언하고 0번쨰, 1번째 항에 1을 저장 
	long *arr =(long*)malloc((num+1)*sizeof(long));
	*arr=0;
	*(arr+1)=1;
	
	return improvedPib(num, arr);
	free(arr);
}


/* 자연수 n 을 입력 받으면 기존 피보나치 함수와
 향상된 피보나치 함수를 각각 실행하고 결과를 보여주는 프로그램*/ 
int main(void)
{	
	int i;
	int n; 			//구할 n 번째 항 
	char c;			//프로그램 종료 여부 
	while(1)
	{
		printf("피보나치 수열 n 항까지 구하기.\n");
		printf("n을 입력하시요.\n"); 
		scanf("%d",&n);
		//기존 피보나치 함수 실행 
		printf("기존 피보나치 함수\n");
		for(i = 0; i <= n; i++){
			printf("(기존) %d 번쨰 항은 : %ld \n", i, pib(i));
		}
		printf("\n");
		//향상된 피보나치 함수 실행 
		printf("향상된 피보나치 함수\n");
		for(i = 0; i <= n; i++){
			printf("(개선) %d 번째 항은 :%ld \n", i, pb(i));
		}
		
		
		printf("작업을 계속 하시겠습니까? (y)\n");
		getchar();
		scanf("%c",&c);
		if (c=='y' || c=='Y') continue;
		else return 0;
	}
	return 0;
}
