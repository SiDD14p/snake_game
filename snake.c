#include <stdio.h>
int roll()
{
   return (rand()%5)+1;
}
int check(int s)
{
    if(s==100)
    {
        printf("\n==============================");
        printf("\nYou are winner");
        printf("\nCongratulations\n");
        printf("==============================");
        return 1;
    }
    else 
    {
        return 0;
    }
}
int check_step(int c)
{
    switch(c)
    {
        case 1: return c+37;
        case 4: return c+10;
        case 8: return c+22;
        case 21: return c+21;
        case 28: return c+2;
        case 32: return c+48;
        case 34: return c-26;
        case 48: return c-22;
        case 50: return c+17;
        case 62: return c-44;
        case 71: return c+21;
        case 88: return c-64;
        case 95: return c-39;
        case 97: return c-19;
        case 99: return c-13;
        default: return c;
    }
}
int main() {
    // Write C code here
    int r,step=0;
    while(check(step)!=1)
    {
        printf("\nRoll Dice : ");
        r=roll();
        printf("%d",r);
        int current=step+r;
        if(step+r<101)
        {
        printf("\nYou are currently at %d step.",current);
        step=check_step(current);
        if(current<step)
        {
            printf("\nYou climed ladder and now you are at %d step.",step);
        }
        else if(current>step)
        {
            printf("\nSnake ate you and now you are at %d step.",step);
        }
        }
        else
        {
            printf("\nRoll Again");
        }
    }
    return 0;
}