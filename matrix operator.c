#include <stdio.h>
void matrix_input(int matrix[][10], int rows, int cols);
void matrix_output(int c[][10], int rows, int cols);
void matrix_sum(int a[][10], int b[][10], int c[][10], int arows, int acols);
void matrix_subtract(int a[][10], int b[][10], int c[][10], int arows, int acols);
void matrix_multiply(int a[][10], int b[][10], int c[][10], int arows, int bcols, int acols);
void matrix_transpose(int a[][10], int c[][10], int arows, int acols);

int main()
{
    int arows, acols, brows, bcols;
    int a[10][10], b[10][10], c[10][10];

    int o;
    printf("\n\n*****Operation Table*****\n\n");
    printf("For matrix addition, enter 1\n");
    printf("For matrix subtraction, enter 2\n");
    printf("For matrix multiplication, enter 3\n");
    printf("For matrix transpose, enter 4\n");
    printf("To exit, enter 0\n");

    // using switch case to select the operation
    scanf("%d", &o);

    switch (o)
    {

    case 0:
        break;

    case 1:
        // addition
        printf("No. of rows and cols for matrix A:\n");
        scanf("%d%d", &arows, &acols);
        printf("No. of rows and cols for matrix B:\n");
        scanf("%d%d", &brows, &bcols);

        // checking condition
        if ((arows == brows) && (acols == bcols))
        {
            // matrix A and matrix B input
            printf("\n");
            printf("Enter elements for matrix A\n");
            matrix_input(a, arows, acols);
            printf("\n");
            printf("Enter elements for matrix B\n");
            matrix_input(b, brows, bcols);

            // matrix add
            matrix_sum(a, b, c, arows, acols);

            // added matrix print
            printf("\nSum of matrix A and matrix B is:\n");
            matrix_output(c, arows, acols);
        }
        else
        {
            printf("can't perform addition for above defined matrix");
        }

        break;

    case 2:
        // subtraction
        printf("No. of rows and cols for matrix A:\n");
        scanf("%d%d", &arows, &acols);
        printf("No. of rows and cols for matrix B:\n");
        scanf("%d%d", &brows, &bcols);

        // checking condition
        if ((arows == brows) && (acols == bcols))
        {
            // matrix A and matrix B input
            printf("\n");
            printf("Enter elements for matrix A\n");
            matrix_input(a, arows, acols);
            printf("\n");
            printf("Enter elements for matrix B\n");
            matrix_input(b, brows, bcols);

            // matrix subtract
            matrix_subtract(a, b, c, arows, acols);

            // subtracted matrix print
            printf("\nDifference of matrix A and matrix B is:\n");
            matrix_output(c, arows, acols);
        }
        else
        {
            printf("can't perform subtraction for above defined matrix");
        }

        break;

    case 3:
        // multiplication
        printf("No. of rows and cols for matrix A:\n");
        scanf("%d%d", &arows, &acols);
        printf("No. of rows and cols for matrix B:\n");
        scanf("%d%d", &brows, &bcols);

        // checking condition
        if (acols == brows)
        {
            // matrix A and matrix B input
            printf("\n");
            printf("Enter elements for matrix A\n");
            matrix_input(a, arows, acols);
            printf("\n");
            printf("Enter elements for matrix B\n");
            matrix_input(b, brows, bcols);

            // matrix multiply
            matrix_multiply(a, b, c, arows, bcols, acols);

            // multiplied matrix print
            printf("\nProduct of matrix A and matrix B is:\n");
            matrix_output(c, arows, bcols);
        }
        else
        {
            printf("can't perform multiplication for above defined matrix");
        }

        break;

    case 4:
        // transpose
        printf("Enter number of rows and columns:\n");
        scanf("%d%d", &arows, &acols);

        // matrix input
        matrix_input(a, arows, acols);

        // matrix transpose
        matrix_transpose(a, c, arows, acols);

        // matrix print
        printf("\nTranspose of matrix A is:\n");
        matrix_output(c, acols, arows);

        break;

    default:
        printf("Invalid Operation:");

        break;
    }

    return 0;
}

void matrix_input(int matrix[][10], int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("Enter element matrix[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("\t%d", matrix[i][j]);
        }
        printf("\n");
    }
}

void matrix_output(int c[][10], int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("\t%d", c[i][j]);
        }
        printf("\n");
    }
}

void matrix_sum(int a[][10], int b[][10], int c[][10], int arows, int acols)
{
    int i, j;
    for (i = 0; i < arows; i++)
    {
        for (j = 0; j < acols; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void matrix_subtract(int a[][10], int b[][10], int c[][10], int arows, int acols)
{
    int i, j;
    for (i = 0; i < arows; i++)
    {
        for (j = 0; j < acols; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

void matrix_multiply(int a[10][10], int b[10][10], int c[10][10], int arows, int bcols, int acols)
{
    int i, j, k;
    for (i = 0; i < arows; i++)
    {
        for (j = 0; j < bcols; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < acols; k++)
            {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
    }
}

void matrix_transpose(int a[][10], int c[][10], int arows, int acols)
{
    int i, j;
    for (i = 0; i < arows; i++)
    {
        for (j = 0; j < acols; j++)
        {
            c[j][i] = a[i][j];
        }
    }
}