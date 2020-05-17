/*
 * C Program to Join Lines of Two given Files and 
 * Store them in a New file
 */
#include <stdio.h>
#include <stdlib.h>
 
/* Function Prototype */
int joinfiles(FILE *, FILE *, FILE *);
 
char ch;
int flag;
 
void main(int argc, char *argv[])
{
    FILE *file1, *file2, *target;
 
    file1 = fopen(argv[1], "r");
    if (file1 == NULL)
    {
        perror("Error Occured!");
    }
    file2 = fopen(argv[2], "r");
    if (file2 == NULL)
    {
        perror("Error Occured!");
    }
    target = fopen(argv[3], "a");
    if (target == NULL)
    {
        perror("Error Occured!");
    }
 
    joinfiles(file1, file2, target);        /* Calling Function */
 
    if (flag == 1)
    {
        printf("The files have been successfully concatenated\n");
    }
}
 
/* Code join the two given files line by line into a new file */
 
int joinfiles(FILE *file1, FILE *file2, FILE *target)
{
    while ((fgetc(file1) != EOF) || (fgetc(file2) != EOF))
    {
        fseek(file1, -1, 1);
        while ((ch = fgetc(file1)) != '\n')
        {
            if (ch == EOF)
            {
                break;
            }
            else
            {
                fputc(ch, target);
            }
        }
        while ((ch = fgetc(file2)) != '\n')
        {
            if (ch == EOF)
            {
                break;
            }
            else
            {
                fputc(ch, target);
            }
        }
        fputc('\n', target);
    }
    fclose(file1);
    fclose(file2);
    fclose(target);
    return flag = 1;
}