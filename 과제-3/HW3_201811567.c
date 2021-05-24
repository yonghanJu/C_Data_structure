#include "DBLinkedList.h"
/* 제목 : id 추천 프로그램      생성자 : 주용한         생성 날짜: 2021년 04월 06일
 더미 기반 양방향 연결리스트를 이용해 사용자에게 id를 입력받으면 자동으로 id 추천을 해주는 프로그램 */


void idRecommend(char *original, char *recommended);    // 첫번째 파라미터엔 입력받은 id 배열,
                                                        // 두번째 파라미터는 추천된 id가 저장될 배열

int main(void){                                     //main 함수 실행
    char id[100];                                   // 원본 id 저장할 공간
    char reId[100];                                 // 추천된 id 저장할 공간

    printf("id를 입력해 주세요 : ");                 // 원본 id 입력받기
    scanf("%s", id);

    idRecommend(id, reId);                          // 함수 실행

    printf("새로 추천된 id 는 \n");                  // 추천된 id 출력
    printf("%s",reId);                              

    return 0;
}

// id 추천 함수
void idRecommend(char *id, char *reId){         
    List charList;                                  // id character 의 List 생성
    LData *pdata = (char*)malloc(sizeof(char));     // 노드의 data 담을 공간

    //리스트에 id입력
    ListInit(&charList);                
    for(int i = 0; i<strlen(id); i++){
        TInsert(&charList, id[i]);                  // tail쪽으로 노드 추가
    }
    
    //1단계
    if(LFirst(&charList, pdata)){                   
        LReplace(&charList, tolower(*pdata));
        while (LNext(&charList, pdata)){
            LReplace(&charList, tolower(*pdata));   // LReplace()함수 활용, 소문자로 교체
        }
    }

    //2단계
    if(LFirst(&charList, pdata)){         // 소문자나 숫자가 아닌경우, 정해진 기호가 아닌경우를 확인 후 제거
        if(((*pdata<0x30||*pdata>0x39)&&(*pdata<0x61||*pdata>0x7A))&&*pdata!=45&&*pdata!=46&&*pdata!=95){
            LRemove(&charList);
        }
        while (LNext(&charList, pdata)){  // 소문자나 숫자가 아닌경우, 정해진 기호가 아닌경우를 확인 후 제거
            if(((*pdata<0x30||*pdata>0x39)&&(*pdata<0x61||*pdata>0x7A))&&*pdata!=45&&*pdata!=46&&*pdata!=95){
                LRemove(&charList);
            }
        }
    }

    //3단계
    if(LFirst(&charList, pdata)){       // 전에 '.'이 나왔으면 isOver=1 으로 중복을 나타냄
        int isOver =0;                  // next 후 중복된 경우 삭제하고 중복이 아닌경우 isOver=0
        if(*pdata=='.')
           isOver=1;                        
        while (LNext(&charList, pdata)){
            if(*pdata=='.'){
                if(isOver)
                    LRemove(&charList);
                isOver = 1;
            }else
                isOver = 0;
        }  
    }

    //4단계
    if(LFirst(&charList, pdata))       
        if(*pdata =='.')                // 첫 노드가 '.'인 경우 
            LRemove(&charList);
    if(LLast(&charList, pdata))  
        if(*pdata == '.')               // 마지막 노드가 '.'인 경우
            LRemove(&charList);

    //5단계
    if(!LFirst(&charList, pdata)){      // LFirst() 실패 시 
        LInsert(&charList,'a');         // 'a' 추가
    }

    //6단계
    while (LCount(&charList)>15){       // 크기가 15보다 클 때
        LLast(&charList, pdata);        // 마지막으로 이동, 삭제
        LRemove(&charList);             
    }
    LLast(&charList, pdata);            // 크기를 15로 줄인 후 다시 마지막으로 이동
    if(*pdata=='.')                     // 마지막 노드가 '.'이면 삭제
        LRemove(&charList);             
    

    //7단계
    LLast(&charList, pdata);            // 마지막 노드로 이동, 데이터 pdata에 받아오기
    while (LCount(&charList)<3){        // 크기가 3 이하일 때
        TInsert(&charList, *pdata);     // tail 쪽으로 마지막 노드의 데이터를 추가
    }

    if(LFirst(&charList, pdata)){       // 함수의 두번째 파라미터 reId[]에 새로운 id 저장
        reId[0] = *pdata;
        int i  =1;
        while (LNext(&charList, pdata)){
            reId[i]=*pdata;
            i++;
        }
    }
}