#include <stdio.h>
#include <stdlib.h>

#define n_max 100


int main()
{
    int akeraioi[n_max], pinakasA[n_max], pinakasB[n_max], ok=0, n, i, j,
    tempA=0, tempB=0, metritisA=0, metritisB=0, flag;

    do{
    printf("Type the size of the array:");
    scanf("%d", &n);
        if (n<=100&&n>0){ //������� �������� ������
            ok=1;
        }
        else{
            printf("\nThe size of the array must be between 1 and 100\n");
            printf("Please retype\n\n");
        }
    }while (!ok); //true while ok == 0

    printf("\nType %d numbers : \n", n);
    for (i=0;i<n;++i){
        printf("Number %d :", i+1); //������� ������ ��� ��� ������
        scanf("%d",&akeraioi[i]);
    }

    for (i=0;i<n;++i){
        pinakasA[i]=akeraioi[i]; //��������� akeraioi[i] --> pinakas [A]
    }

    for (i=0;i<n;++i){
        pinakasB[i]=akeraioi[i]; //��������� akeraioi[i] --> pinakas [B]
    }


    for(i=n-1;i>0;i--){ //��� ���� ���� � ��� �� ����� ���� ����
        for (j=0;j<i;j++){ // ��� ���� ���� j ��� ��� ���� ����� �� i
            if (pinakasA[i]<pinakasA[j]){ // �������� ����� ����� i �� ���� j
                    tempA=pinakasA[j];    // ��������� �����
                    pinakasA[j]=pinakasA[i];
                    pinakasA[i] = tempA;
                    metritisA = metritisA + 1;
            }

        }
    }

    while (1){ //��� ������� �������� �����
        flag=0;
        for (i=0;i<n;i++){ //��� ���� ���� i ��� ��� ���� ��� �� �����
            if (pinakasB[i]>pinakasB[i+1]){ //�������� ����� ����� i & �+1
                tempB=pinakasB[i];           // �������� �����
                pinakasB[i]=pinakasB[i+1];
                pinakasB[i+1]=tempB;
                metritisB = metritisB + 1;
                flag=1;
            }
        }
        if (flag==0){ //����� ��������� �����
            break;
        }
    }

    for (i=0;i<n;++i){
        if (pinakasA[i]!= pinakasB[i]){
            printf("\n Arrays A and B are not identical\n");
            exit(1);
        }
    }
    printf("\n Original Array\n");
    printf("-----\n");
    for (i=0;i<n;++i){
        printf("%d\n",akeraioi[i]); //������� ��� ������ ������
        printf("-----\n");
    }

    /*printf("\n Array A\n");
    for (i=0;i<n;++i){
        printf("%d\n",pinakasA[i]); //������� ��� ������ �
    }*/

    printf("\n Array B\n");
    printf("-----\n");
    for (i=0;i<n;++i){
       printf("%d\n",pinakasB[i]);
       printf("-----\n"); //������� ��� ������ �
    }

    printf("Array A swappings: %d\n", metritisA); //������� ��� ��������� ��� 1�� ����������
    printf("Array B swappings: %d\n", metritisB); //������� ��� ��������� ��� 2�� ����������

    return 0;
}
