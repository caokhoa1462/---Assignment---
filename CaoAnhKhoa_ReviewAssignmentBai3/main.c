#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <float.h>

int main() 
{
    while (1) 
    {
        char a[10];
        printf ("\nHere we have four data name for you to type in: int, float, double, char. \n");
        printf ("Please enter the data type name (you can type \"all\" to display all of them): ");
        scanf("%s", a);   
            if (strcmp(a, "int") == 0 || strcmp(a, "all") == 0) {
                printf("\nSize of int: 4 bytes\n", sizeof(int));
                printf("Value range of int: %d to %d\n", INT_MIN, INT_MAX);
            }
            if (strcmp(a, "float") == 0 || strcmp(a, "all") == 0) {
                printf("\nSize of float: 4 bytes\n", sizeof(float));
                printf("Value range of float: %e to %e\n", FLT_MIN, FLT_MAX);
            }
            if (strcmp(a, "double") == 0 || strcmp(a, "all") == 0) {
                printf("\nSize of double: 8 bytes\n", sizeof(double));
                printf("Value range of double: %e to %e\n", DBL_MIN, DBL_MAX);
            }
            if (strcmp(a, "char") == 0 || strcmp(a, "all") == 0) {
                printf("\nSize of char: 1 byte\n", sizeof(char));
                printf("Value range of char: %d to %d\n", CHAR_MIN, CHAR_MAX);
            }
    }
    return 0;
}
