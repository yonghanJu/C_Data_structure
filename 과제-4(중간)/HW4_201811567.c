#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListStack.h"
/*제목 : 스택과 재귀함수를 이용한 문자열 검열 프로그램
  생성자 : 201811567_주용한         생성 날짜 : 2021년 4월 28일 
  프로그램 설명 : 스택자료구조 기반 재귀함수를 사용한다. 1, 2 번째 매개변수로는 각각 
  입력받은 A(검열자), T(문자열)을 받는다. 
  함수의 반환값은 int 형이며 이는 함수의 실행 횟수가 짝수인지 홀수인지 구분하기 위함이다.*/

// Parameter : 입력받는 스택 2개, 재귀 이용 스택 2개 총 4개의 스택과 함수 호출의 횟수 count 
int censorship(Stack *stackA, Stack *stackT, Stack *tmp, Stack *result, int count);

int main(void) {
    char A[26];             // A는 최대 25자
    char T[300001];         // T는 최대 300,000자

    scanf("%s\n", A);       //  사용자로부터 A 입력받기
    scanf("%s", T);         //  사용자로부터 T 입력받기

    Stack stackA;           //검열자
    Stack stackT;           //문자열
    Stack result;           //재귀호출에 사용될 스택
    Stack tmpstack;         //재귀호출에 사용될 스택
    StackInit(&stackA);
    StackInit(&stackT);
    StackInit(&tmpstack);
    StackInit(&result);
    
    //입력 받은 문자열 StackA, StackT에 저장
    for(int i =0; i<strlen(A); i++){    
        SPush(&stackA, A[i]);
    }
    for(int i =0; i<strlen(T); i++){
        SPush(&stackT, T[strlen(T)-i-1]);
    }

    // 실행 횟수의 짝, 홀수 저장
    int count = censorship(&stackA, &stackT, &tmpstack, &result, 0);
    
    printf("\n result : \n");
        if(count)                
            while(!SIsEmpty(&result)) SPush(&stackT, SPop(&result));        //실행 횟수가 홀수인 경우 역순정리
        while(!SIsEmpty(&stackT))   printf("%c", SPop(&stackT));            //T값 출력
    printf("\n");
    return 0;
}

int censorship(Stack *stackA, Stack *stackT, Stack *tmp, Stack *result, int count){
    char data;                                        // 데이터 담을 공간

    while(!SIsEmpty(stackT)){                         // T 가 다 비울때 까지
        if( SPeek(stackA) != SPeek(stackT) ){         // A,T가 같은게 나올때 까지
            SPush(result, SPop(stackT));              // T에서 result로 이동
        }else {
            SPop(stackT);
            SPush(tmp, SPop(stackA));               // A,T가 같다면 pop(A), push(tmp)
        }

        if(!SIsEmpty(tmp)){           //tmp에 뭔가 있다면 = A,T와 같은게 있다면
            while( !SIsEmpty(stackA) && (SPeek(stackA) == SPeek(result))){   //A,T가 다른게 나올때 까지
                SPop(stackA);
                SPush(tmp, SPop(result));
            }
            if(!SIsEmpty(stackA)){     //A를 다 비우지 못했다면 = 다른 문자열일 경우
                while(!SIsEmpty(tmp)){  //다시 tmp를 비워 A,T를 채움
                    data = SPop(tmp);
                    SPush(stackA, data);
                    SPush(result, data);
                }
            }
        }
    }
    if (!SIsEmpty(stackA)) {// 실행 후 A가 남아있다면 = 같은 문자열이 없다면 종료
        return count/2;     // 실행 횟수가 홀수인지 짝수인지 반환
    }
    count++;                // 실행 횟수 계산
    censorship(tmp, result, stackA, stackT, count);
}