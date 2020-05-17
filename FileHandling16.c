/*
 * C Program to Compare two Binary Files, Printing the First Byte 
 * Position where they Differ
 */
#include <stdio.h>
 
void compare_two_binary_files(FILE *,FILE *);
 
int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
 
    if (argc < 3)
    {
        printf("\nInsufficient Arguments: \n");
        printf("\nHelp:./executable <filename1> <filename2>\n");
        return;
    }
    else
    {
        fp1 = fopen(argv[1],  "r");
        if (fp1 == NULL)
        {
            printf("\nError in opening file %s", argv[1]);
            return;
        }
 
        fp2 = fopen(argv[2], "r");
 
        if (fp2 == NULL)
        {
            printf("\nError in opening file %s", argv[2]);
            return;
        }
 
        if ((fp1 != NULL) && (fp2 != NULL))
        {
            compare_two_binary_files(fp1, fp2);
        }
    }
}
 
/*
 * compare two binary files character by character
 */
void compare_two_binary_files(FILE *fp1, FILE *fp2)
{
    char ch1, ch2;
    int flag = 0;
 
    while (((ch1 = fgetc(fp1)) != EOF) &&((ch2 = fgetc(fp2)) != EOF))
    {
        /*
          * character by character comparision
          * if equal then continue by comparing till the end of files
          */
        if (ch1 == ch2)
        {
            flag = 1;
            continue;
        }
        /*
          * If not equal then returns the byte position
          */
        else
        {
            fseek(fp1, -1, SEEK_CUR);        
            flag = 0;
            break;
        }
    }
 
    if (flag == 0)
    {
        printf("Two files are not equal :  byte poistion at which two files differ is %d\n", ftell(fp1)+1);
    }
    else
    {
        printf("Two files are Equal\n ", ftell(fp1)+1);
    }
}
