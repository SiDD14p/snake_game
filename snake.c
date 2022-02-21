
#include <stdio.h>
char p1,p2;
/*char check_name(char p)
{
    char p2;
    printf("Enter initial character of Player 2 : ");
    scanf("%c",&p2);
    if(p==p2)
    {
        printf("Please pick another letter");
        check_name(p);
    }
    return p2;
}*/
int roll(){
   return (rand()%5)+1;
}
int check(int s, char p){
    if(s==100)
    {
        printf("\n==============================");
        printf("\nPlayer %c is winner",p);
        printf("\nCongratulations\n");
        printf("==============================");
        return 1;
    }
    else 
    {
        return 0;
    }
}
int check_step(int c){
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
int current_step(int r, int step, char p)
{
        printf("%d",r);
        int current=step+r;
        if(step+r<101)
        {
        printf("\nPlayer %c is currently at %d step.",p,current);
        step=check_step(current);
        if(current<step)
        {
            printf("\nPlayer %c climed ladder and now at %d step.",p,step);
        }
        else if(current>step)
        {
            printf("\nPlayer %c is eaten by snake and now you are at %d step.",p,step);
        }
        }
        else
        {
            printf("\nRoll Again player %c",p);
        }
        return step;
}

int main() {
    int r,step1=0,step2=0;
    char p1;
    char p2='c';
    printf("Welcome to snake-ladder game\nEnter the name of 2 players\n");
    printf("Enter initial character of Player 1 : ");
    scanf("%c",&p1);
    //printf("Enter initial character of Player 2 : ");
    //scanf("%c",&p2);
    while(check(step1,p1)!=1 && check(step2,p2) !=1)
    {
        printf("\n-------------------\n");
        //printf("%c : ",&p1);
        printf("\nRoll Dice player %c: ",p1);
        r=roll();
        step1=current_step(r,step1, p1);
        printf("\nRoll Dice player %c: ",p2);
        r=roll();
        step2=current_step(r,step2, p2);
    }
    return 0;
}