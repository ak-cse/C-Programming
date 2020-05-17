/*
 * C Program to Convert the Content of File to LowerCase
 */
#include <stdio.h>
#include <errno.h>
 
int to_lower_file(FILE *);
 
void main(int argc, char * argv[])
{
    int op = -1;
    char ch;
    FILE *fp;
    if (fp = fopen(argv[1], "r+"))
    {
        printf("FILE has been opened..!!!\n");
        op = to_lower_file(fp);
        printf(" %d \n", op);
        fclose(fp);
    }
    else
    {
        perror("Error Occured");
        printf(" %d\n ", op);
    }
}
 
int to_lower_file(FILE *f)
{
    int c;
    char ch;
    while ((ch = fgetc(f))! = EOF)
    {    
        c = (int)ch;
        if (c >= 65 && c <= 90)
        {
            ch = ch + 32;
            fseek(f, -1L, 1);
            fputc(ch, f);
        }
    }
    return 0;
}