 /**
*
* By - Jatin Kumar Mandav
*
* Header File for some functions!
*
* Functions in this header file are:
*
* square
* cube
* greet
* binary
* octal
* hex
* bin2dec
* oct2dec
* in_string
* in_int
*
**/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<stdbool.h>

int square()
{
    int num,sq;
    scanf("%d",&num);
    sq = num*num;
    return sq;
}

int cube()
{
    int num,cb;
    scanf("%d",&num);
    cb = num*num*num;
    return cb;
}

void greet()
{
    char* nam = (char*)malloc(10240 * sizeof(char));
    printf("Enter your name user:");
    scanf("%[^\n]s",nam);
    printf("O, Hello! %s!\n",nam);
}

int binary()
{
    int num,rem = 0,i = 1,bin = 0;
    scanf("%d",&num);
    while(num != 0)
    {
        rem = num%2;
        bin += (rem*i);
        i = i*10;
        num = num/2;
    }
    return bin;
}

int octal()
{
 int num,rem = 0,i = 1,oct = 0;
    scanf("%d",&num);
    while(num != 0)
    {
        rem = num%8;
        oct += (rem*i);
        i = i*10;
        num = num/8;
    }
    return oct;
}

void hex()
{
    long int num,i=0,rem[5],len=0;
    scanf("%ld",&num);
    while(num>0)
    {
        rem[i] = num%16;
        len++;
        i++;
        num = num/16;
    }
    for(int j=len-1;j>=0;j--)
    {
        switch(rem[j])
        {
            case 10:
            {
                printf("A");
                break;
            }
            case 11:
            {
                printf("B");
                break;
            }
            case 12:
            {
                printf("C");
                break;
            }
            case 13:
            {
                printf("D");
                break;
            }
            case 14:
            {
                printf("E");
                break;
            }
            case 15:
            {
                printf("F");
                break;
            }
            default:
            printf("%ld",rem[j]);
        }
    }
    printf("\n");
}

int bin2dec()
{
    int bin,dec=0,dig,i=0,bin1,dig1;
    p1: scanf("%d",&bin);
    bin1 = bin;
    while(bin1>0)
    {
        dig1 = bin1%10;
        if(dig1 == 0 || dig1 ==1)
        {
            bin1 = bin1/10;
        }
        else
        {
            printf("Not a Binary! \nRetry:");
            goto p1;
        }
    }
    while(bin>0)
    {
        dig = bin%10;
        dec += dig*pow(2, i);
        bin = bin/10;
        i++;
    }
    return dec;
}

int oct2dec()
{
    int oct,dec=0,dig,i=0,oct1=0,dig1=0;
    p1: scanf("%d",&oct);
        oct1 = oct;
    while(oct1>0)
    {
        dig1 = oct1%10;
        if(dig1 >= 0 && dig1 <=7)
        {
            oct1 = oct1/10;
        }
        else
        {
            printf("Not an Octal! \nRetry:");
            goto p1;
        }
    }
    while(oct>0)
    {
        dig = oct%10;
        dec += dig*pow(8, i);
        oct = oct/10;
        i++;
    }
    return dec;
}

char* in_string()
{
    char* string = (char*)malloc(10240*sizeof(char));
    scanf(" %[^\n]s",string);
    free(string);
    return string;
}

int in_int()
{
    while (true)
    {
        char* in = (char*)malloc(10240*sizeof(char));
        scanf(" %[^\n]s",in);
        int n;
        char c;
        if(sscanf(in, " %d %c", &n, &c) == 1)
        {
            free (in);
            return n;
        }
        else
        {
            printf("Only integers allowed : ");
            free (in);
        }
    }
}
