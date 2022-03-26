#include <stdio.h>
#include <stdlib.h>

void printRow1(int *p1, int rowSize) {
    for (int i = 0; i < rowSize; i++) {
        printf("%d\t", *p1);
        p1 += 1;
    }
}

void printCol1(int *p, int colSize) {
    for (int i = 0; i < colSize; i++) {
        printf("%d\n", *p);
        p += 4;
    }
}

/*     */

void reverseRow1(int *p2) {
    for (int i = 4; i > 0; i--) {
        printf("%d\t", *p2);
        p2--;;
    }
}

int arr[3][4] = {
    { 1,  2,  3,  4 },
    { 5,  6,  7,  8 },
    { 9, 10, 11, 12 }
};
int rows = sizeof(arr) / sizeof(arr[0]);
int cols = sizeof(arr[0]) / sizeof(arr[0][0]);

void printMat() {
    int col = 3;
    int row = 4;

    for (int i = 0; i < col; i ++) {
        printf("\n");

        for (int j = 0; j < row; j++) {
            printf("%d\t", arr[i][j]);
        }
    }
}

void printCol() {
    printf("Which column would you like to print? \t");

    int choiceCol;
    scanf("%d", &choiceCol);

    if (choiceCol >= 1 && choiceCol <= 4) {
        printCol1(&arr[0][choiceCol-1], 3);
    } else {
        printf("An Error occured\n");
    }
}

void printRow() {
    printf("Which row would you like to print? \t");

    int choiceRow;
    scanf("%d", &choiceRow);

    if (choiceRow >= 1 && choiceRow <= 3){
        printRow1(&arr[choiceRow-1][0], 4);
    } else {
        printf("An Error occured\n");
    }
}

void reverseRow(int rownum, int low, int high)
{
    if (low < high)
    {
        int temp = arr[rownum][low];
        arr[rownum][low] = arr[rownum][high];
        arr[rownum][high] = temp;

        reverseRow(rownum, low + 1, high - 1);
    } else {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    }
}

void printMenu() {
    printf("\n");
    printf("You can choose one of these services: \n");
    printf("1. Print matrix tabular form. \n");
    printf("2. Print a specific row or a number of rows in sequence \n");
    printf("3. Print a specific column or a number of columns in sequence \n");
    printf("4. Get the elements of a specific row reversed \n");
    printf("5. find the number of prime numbers in a specific row \n");
    printf("6. Quit \n");
    printf("Please select one to try ");

    int answer;
    scanf("%d", &answer);

    switch (answer) {
        case 1:
            printMat();
            printMenu();
            break;
        case 2:
            printCol();
            printMenu();
            break;

        case 3:
            printRow();
            printMenu();
            break;

        case 4:
             printf("Please select row number: ");
        int row;
        scanf("%d", &row);
        if (row >= rows || row < 0) {
            printf("Invalid row\n");
            break;
        }
        reverseRow(row, 0, cols - 1);
        break;

        case 5:
            /* code */
            break;

        case 6:
            printf("Bye!\n");
            break;

        default:
            printf("please select carefully! \n");
            break;
    }
}

int main() {

    printMat();
    printMenu();

    return 0;
}
