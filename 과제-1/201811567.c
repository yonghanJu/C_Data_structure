#include <stdio.h>
#include <stdlib.h>
/*���� :  ���� �Ǻ���ġ ����Լ�
 ������ : �ֿ���
 ���� ��¥: 2021.03.06 (2020.03.20 ����)
 �ڵ� ���� : �Ϲ����� �Ǻ���ġ �Լ��� ������ ���� ��Ų �Ǻ���ġ �Լ��� ����� 
 			�Ϲ�->����  ������ n��° �ױ����� ���� ����� �ش� */ 
 			
// �Ϲ����� �Ǻ���ġ �Լ� 
long pib(int num)
{
	if(num ==0) return 0;
	else if(num ==1 ) return 1;
	else{
		return pib(num-1) + pib(num-2);
	}
}

// �迭�� Ȱ���� ������ �Ǻ���ġ �Լ� 
long improvedPib(int num, long* arr)
{
	if(num ==0) return 0; 
	else if(num ==1) return 1;
	else{
		/* �ѹ��� ���ȣ�� ����  
		   �迭�� �� �� ������ ����*/ 
		return  *(arr+num) = improvedPib(num-1, arr) + *(arr+num-2);
	}
}

//�迭�� �������ְ� �����Լ� ����ȭ���ִ� �Լ� 
long pb(int num)
{
	//�����͸� �̿��� �迭�� �����ϰ� 0����, 1��° �׿� 1�� ���� 
	long *arr =(long*)malloc((num+1)*sizeof(long));
	*arr=0;
	*(arr+1)=1;
	
	return improvedPib(num, arr);
	free(arr);
}


/* �ڿ��� n �� �Է� ������ ���� �Ǻ���ġ �Լ���
 ���� �Ǻ���ġ �Լ��� ���� �����ϰ� ����� �����ִ� ���α׷�*/ 
int main(void)
{	
	int i;
	int n; 			//���� n ��° �� 
	char c;			//���α׷� ���� ���� 
	while(1)
	{
		printf("�Ǻ���ġ ���� n �ױ��� ���ϱ�.\n");
		printf("n�� �Է��Ͻÿ�.\n"); 
		scanf("%d",&n);
		//���� �Ǻ���ġ �Լ� ���� 
		printf("���� �Ǻ���ġ �Լ�\n");
		for(i = 0; i <= n; i++){
			printf("(����) %d ���� ���� : %ld \n", i, pib(i));
		}
		printf("\n");
		//���� �Ǻ���ġ �Լ� ���� 
		printf("���� �Ǻ���ġ �Լ�\n");
		for(i = 0; i <= n; i++){
			printf("(����) %d ��° ���� :%ld \n", i, pb(i));
		}
		
		
		printf("�۾��� ��� �Ͻðڽ��ϱ�? (y)\n");
		getchar();
		scanf("%c",&c);
		if (c=='y' || c=='Y') continue;
		else return 0;
	}
	return 0;
}
