#include <stdio.h>
#include <stdlib.h>

/*  제목: Recursive Matrix Multiplication
    생성자:201811567_주용한     생성날짜:2021.03.21
    n * n 크기의 두 행렬을 n/2*n/2 크기로 나누어 재귀호출하고
    연산값을 output행렬에 저장한다 
*/

/*  함수 파라미터 순서대로 설명
    *a[], *b[]  => 입력받은 두 행렬
    *out[]      => 결과값을 담을 행렬
    n           => 행렬의 크기
    r1, c1, r2, c2  =>곱할 두 값의 좌표
    outR, outC  => 결과값이 입력될 좌표, 예를 들어 두 함수의
                 outR, outC값이 같으면 같은 곳에 저장.
*/  
void recurMultiply(int *a[], int *b[], int *out[], int n, int r1, int c1, int r2, int c2, int outR, int outC){

    if(n==1){
        //나누어진 타일을 연산 후 결과행렬에 더한다.
        *(out[outR]+outC) += (*(a[r1]+c1)) * (*(b[r2]+c2));
    }else{
        //두 행렬을 각각 4개로 나누고 재귀호출한다
        //C(11) = A(11)*B(11) + A(12)*B(21)      -outR, outC 공유   
        recurMultiply(a, b, out, n/2, r1+0,c1+0,r2+0,c2+0, outR+0,outC+0);     
        recurMultiply(a, b, out, n/2, r1+0,c1+n/2,r2+n/2,c2+0, outR+0,outC+0); 

        //C(12) = A(11)*B(12) + A(12)*B(22)      -outR, outC 공유
        recurMultiply(a, b, out, n/2, r1+0,c1+0,r2+0,c2+n/2, outR+0,outC+n/2);        
        recurMultiply(a, b, out, n/2, r1+0,c1+n/2,r2+n/2,c2+n/2, outR+0,outC+n/2);  

        //C(21) = A(21)*B(11) + A(22)*B(21)     -outR, outC 공유
        recurMultiply(a, b, out, n/2, r1+n/2,c1+0,r2+0,c2+0, outR+n/2,outC+0);
        recurMultiply(a, b, out, n/2, r1+n/2,c1+n/2,r2+n/2,c2+0, outR+n/2,outC+0);

        //C(22) = A(21)*B(12) + A(22)*B(22)     -outR, outC 공유
        recurMultiply(a, b, out, n/2, r1+n/2,c1+0,r2+0,c2+n/2, outR+n/2,outC+n/2);
        recurMultiply(a, b, out, n/2, r1+n/2,c1+n/2,r2+n/2,c2+n/2, outR+n/2,outC+n/2);
    }
}

int main(void){
    printf("크기 n과 두 행렬을 입력하시오.\n");
    // n = 행, 열의 크기
    int n; 
    scanf("%d", &n);

    //입력받을 두 행렬과 결과행렬 1개를 선언
    int* pmatrixA[n];
    int* pmatrixB[n];
    int* output[n];
    for(int i =0; i < n; i++){
        pmatrixA[i] = (int*)malloc(n*sizeof(int));
        pmatrixB[i] = (int*)malloc(n*sizeof(int));
        output[i] = (int*)malloc(n*sizeof(int));
    }

    //사용자로부터 입력행렬 받기
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",(pmatrixA[i]+j));
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",(pmatrixB[i]+j));
        }
    }

    //함수 실행
    recurMultiply(pmatrixA, pmatrixB, output, n, 0,0,0,0,0,0);

    //결과행렬 출력
    printf("\n실행 결과\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ",*(output[i]+j));
        }
        printf("\n");
    }

    for(int i =0; i < n; i++){
        free(pmatrixA[i]);
        free(pmatrixB[i]);
        free(output[i]);
    }
    return 0;
}