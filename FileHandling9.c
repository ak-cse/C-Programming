/*
 * C Program to Find Sum of Numbers given in Command Line Arguments 
 * Recursively
 */
#include <stdio.h>
 
int count, s = 0;
void sum(int *, int *);
 
void main(int argc, char *argv[])
{
    int i, ar[argc];
    count = argc;
    for (i = 1; i < argc; i++)
    {
        ar[i - 1] = atoi(argv[i]);
    }
    sum(ar, ar + 1);
    printf("%d", s);
}
 
/* computes sum of two numbers recursively */
void sum(int  *a, int  * b)
{
    if (count == 1)
        return;
    s = s + *a + *b;
    count -= 2;
    sum(a + 2, b + 2);
}