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
        if (n<=100&&n>0){ //έλεγχος μεγέθους πίνακα
            ok=1;
        }
        else{
            printf("\nThe size of the array must be between 1 and 100\n");
            printf("Please retype\n\n");
        }
    }while (!ok); //true while ok == 0

    printf("\nType %d numbers : \n", n);
    for (i=0;i<n;++i){
        printf("Number %d :", i+1); //γέμισμα πίνακα από τον χρήστη
        scanf("%d",&akeraioi[i]);
    }

    for (i=0;i<n;++i){
        pinakasA[i]=akeraioi[i]; //αντιγραφή akeraioi[i] --> pinakas [A]
    }

    for (i=0;i<n;++i){
        pinakasB[i]=akeraioi[i]; //αντιγραφή akeraioi[i] --> pinakas [B]
    }


    for(i=n-1;i>0;i--){ //Για κάθε θέση ι από το τέλος στην αρχή
        for (j=0;j<i;j++){ // Για κάθε θέση j από την αρχή μέχρι το i
            if (pinakasA[i]<pinakasA[j]){ // σύγκριση τιμής θέσης i με θέση j
                    tempA=pinakasA[j];    // ανταλλαγή τιμών
                    pinakasA[j]=pinakasA[i];
                    pinakasA[i] = tempA;
                    metritisA = metritisA + 1;
            }

        }
    }

    while (1){ //όσο γίνεται εναλλαγή τιμών
        flag=0;
        for (i=0;i<n;i++){ //για κάθε θέση i από την αρχή εώς το τέλος
            if (pinakasB[i]>pinakasB[i+1]){ //σύγκριση τιμών θέσης i & ι+1
                tempB=pinakasB[i];           // εναλλαγή τιμών
                pinakasB[i]=pinakasB[i+1];
                pinakasB[i+1]=tempB;
                metritisB = metritisB + 1;
                flag=1;
            }
        }
        if (flag==0){ //τέλος εναλλαγής τιμών
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
        printf("%d\n",akeraioi[i]); //τυπώνει τον αρχικό πίνακα
        printf("-----\n");
    }

    /*printf("\n Array A\n");
    for (i=0;i<n;++i){
        printf("%d\n",pinakasA[i]); //τυπώνει τον πίνακα Α
    }*/

    printf("\n Array B\n");
    printf("-----\n");
    for (i=0;i<n;++i){
       printf("%d\n",pinakasB[i]);
       printf("-----\n"); //τυπώνει τον πίνακα Β
    }

    printf("Array A swappings: %d\n", metritisA); //τυπώνει τις εναλλαγές του 1ου αλγόριθμου
    printf("Array B swappings: %d\n", metritisB); //τυπώνει τις εναλλαγές του 2ου αλγόριθμου

    return 0;
}
