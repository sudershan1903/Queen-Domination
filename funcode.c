#include<stdio.h>
#include<stdlib.h>
typedef struct node *NODEPTR;
NODEPTR dlist=NULL;
NODEPTR game_pointer;
struct node
{
int info;
int info1;
NODEPTR left;
NODEPTR right;
NODEPTR down;
NODEPTR top;
};
void display()
{
    system("cls");
    system("COLOR 2b");
    int i=0,j,l=0,k=0;
    NODEPTR q,p;
    q=dlist;
    while(q!=NULL)
    {
        p=q;
        printf("\n");
        while(p!=NULL)
        {
            if(p->info==0 && p->info1!=23)
                printf("  ");
            if(p->info==1 && p->info1!=23)
               printf(" 1 ");
            if(p->info==2 && p->info1!=23)
                printf(" 2 ");
            if(p->info==3 && p->info1!=23)
                printf(" 3 ");
            if(p->info==9 && p->info1!=23)
                printf(" [] ");
            if(p->info==1 && p->info1==23)
               printf(" 1*");
            if(p->info==2 && p->info1==23)
                printf(" 2*");
            if(p->info==3 && p->info1==23)
                printf(" 3*");
            if(p->info==9 && p->info1==23)
                printf(" []*");
                p=p->right;
        }
        q=q->down;
}
    getch();
}
void move_top()
{
if((game_pointer->top)==NULL)
        printf("wrong move");
else
    {
         game_pointer->info1=1;
        (game_pointer->top)->info1=23;
        game_pointer=game_pointer->top;
    }
    display();
}
void move_down()
{
    if((game_pointer->down)==NULL)
        printf("wrong move");
    else
    {
        game_pointer->info1=1;
        (game_pointer->down)->info1=23;
        game_pointer=game_pointer->down;
    }
display();

}
void move_left()
{
if((game_pointer->left)==NULL)
        printf("wrong move");
else
    {
        game_pointer->info1=1;
        (game_pointer->left)->info1=23;
        game_pointer=game_pointer->left;
    }
display();
}
void move_right()
{
    if((game_pointer->right)==NULL  || (game_pointer->right)->info==0)
        printf("wrong move");
else
    {
        game_pointer->info1=1;
        (game_pointer->right)->info1=23;
        game_pointer=game_pointer->right;
    }
display();
}
void change()
{
    if( game_pointer->info==9 )
    {
    int temp,i=1;
    while(i)
    {
        char c = getch();
        switch(c)
        {
        case 72:        //move top
            {
                printf("\n change to top:");
                if(game_pointer->top==NULL)
                    printf("wrong move");
                else
                {
                    temp=game_pointer->info;
                    game_pointer->info=(game_pointer->top)->info;
                    (game_pointer->top)->info=temp;
                }
                i=0;
            }
            break;
        case 80:        //move down
            {
                printf("\n change to down :");
                if(game_pointer->down==NULL)
                    printf("wrong move");
                else
                {
                    temp=game_pointer->info;
                    game_pointer->info=(game_pointer->down)->info;
                    (game_pointer->down)->info=temp;
                }
                i=0;
            }
            break;
        case 77:        //move right
            {
                printf("\n change to right:");
                if(game_pointer->right==NULL )
                    printf("wrong move");
                else
                {
                    temp=game_pointer->info;
                    game_pointer->info=(game_pointer->right)->info;
                    (game_pointer->right)->info=temp;
                }
                i=0;
            }
            break;
        case 75:        //move left
            {
                printf("\n change to left:");
            if(game_pointer->left==NULL)
                    printf("wrong move");
                else
                {
                    temp=game_pointer->info;
                    game_pointer->info=(game_pointer->left)->info;
                    (game_pointer->left)->info=temp;
                }
                i=0;
            }
            break;
        default : i=1;
            break;
        }
    display();
    }
    }
}
NODEPTR getnode()
{
        NODEPTR q;
        q=malloc(sizeof(struct node));
        return q;
}
void merge(NODEPTR p,NODEPTR q)
{

    while(p->down!=NULL)
        p=p->down;

    while(q!=NULL)
    {

        p->down=q;
        q->top=p;
        p=p->right;
        q=q->right;
    }
}
NODEPTR insert(int a[],int x)
{
    NODEPTR p,q,list=NULL;
    int i;
    for(i=0;i<x;i++)
    {
    p=getnode();
    q=list;
    p->info=a[i];
        if(list==NULL)
        {
            p->left=NULL;
            list=p;
        }
        else
        {
            while(q->right!=NULL)
                q=q->right;
            q->right=p;
            p->left=q;
        }
        p->top=NULL;
        p->right=NULL;
        p->down=NULL;
    }
    return list;
}
void check()
{

    int temp=0,count=0;
  NODEPTR p=dlist,q;
    while(p!=NULL)
        {
            count=0;
            q=p;
            temp=p->info;
            while(q!=NULL)
                {
                    if(temp==q->info)
                    count++;
                    q=q->right;
                }
                if(count!=3)
                {
                    printf("\nCONTINUE YOUR GAME");
                  return 0;
                }
                p=p->down;
        }
        printf("\nYOU WIN " );
        exit(0);
}
int main()
{
  int i,j;
  NODEPTR list;
  dlist=NULL;
  int  a[3][4]={1,2,3,0,2,1,2,0,3,1,3,9};
     for(i=0;i<3;i++)
    {
    if(dlist==NULL)
        dlist=insert(a[i],4);
    else
            {list=insert(a[i],4);
            merge(dlist,list);}
    }
    game_pointer=(dlist->down);
    game_pointer->info1=23;
    display();
      while(1)
    {
        char c = getch();
        switch(c)
        {
        case 72:move_top();
            break;
        case 80:move_down();
            break;
        case 77:move_right();
            break;
        case 75:move_left();
            break;
        case 27 :check();
            break;
        case 13 :change();
             break;
        default:
            break;
        }
    }
    getch();
}
