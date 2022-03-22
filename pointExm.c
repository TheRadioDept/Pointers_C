#include <stdio.h>
#include <stdlib.h>

void PrintCol(int* p, int colSize);  // prototype of the function. 
// It uses a pointer to store address of top element of the column to print

int main(int argc, char *argv[])
{
    char buf; // just for absorbing excess reading characters
    char choice=' ';
    int col;
    int arr[][4] = { {2,4,7,9}, {11,33,66,77},{12,15,55,22} };  // declaration and initialization of a 3x4 array of int
    // printing the array
    for (int i = 0; i < 3; i++)  
    { 
        for (int j = 0; j < 4; j++)
            printf("%d\t", arr[i][j]);
        printf("\n");
    }

    printf("would you like to print a column of the array?  y or Y to proceed:  ");
    int k= scanf("%c", &choice);
    buf=fgetc(stdin);
    printf("1st : Char is %c , buf is %c\n", choice, buf);  //debugging

    do 
    {
        if ((choice != 'y') && (choice != 'Y'))
        {
            printf("Thank you for using the program... See you !\n");
            exit(0);
        }
        printf("Which column would you like to print (Choose 1 to 4):   ");
        scanf("%d", &col);
        buf = fgetc(stdin);  // for absorbing newline char
        if (col >= 1 && col <= 4)
            PrintCol(&arr[0][col - 1], 3);  // passing the @ of top element of the column
        else
        {
            printf("Wrong column number !  should be between 1 and 4\n");
            printf("Try again later ... Quiting ! \n");
            exit(0);
        }
        
        printf("would you like to print another column of the array?  y or Y to proceed:  ");
        scanf("%c", &choice);
        buf=fgetc(stdin);
    } while ((choice == 'y') || (choice == 'Y'));
}

void PrintCol(int* p, int colSize)
{ 
    printf("Printing a column of a doubel dim. array\n");
    for (int i = 0; i < colSize; i++)
    {
        printf("%d\n", *p);
        p += 4;
    }
}