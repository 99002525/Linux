
#include <stdio.h>
#include "basic.h"
int main()
{
    char aj1[100], aj2[100];
    int compare;

    printf("\n\nEnter 1st string: ");
    scanf("%s", aj1);

    printf("\n\nEnter 2nd string: ");
    scanf("%s", aj2);

    compare = mystrcmp(aj1, aj2);  // function call

    if(compare == 1)
        printf("\n\nBoth the strings are exactly same.\n\n");
     else
        printf("\n\nBoth the strings are different.\n");
    printf("the length : %d" ,mystrlen(aj1));
    mystrcpy(aj1);
    mystrcat(aj1,aj2);
    return 0;
}

