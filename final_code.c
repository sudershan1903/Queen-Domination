#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct qd
{
    int sol[8];
    struct qd* next;
};
typedef struct qd* nodeptr;
nodeptr list=NULL;
nodeptr getnode()
{
    nodeptr p;
    p=malloc(sizeof(struct qd));
    return p;
}
void push(int s[],int n)
{
    int i;
    nodeptr p=getnode(),q;
    for(i=1;i<=n;i++)
        p->sol[i-1]=s[i];
    p->next=NULL;
    if(list==NULL)
        list=p;
    else
    {
        q=list;
        while(q->next!=NULL)
            q=q->next;
        q->next=p;
    }
}
void display(int n)
{   int i,c=0;
    nodeptr p=list;
    while(p!=NULL)
    {
        printf("\n%d)  ",++c);
        for(i=0;i<n;i++)
            printf("%d->",p->sol[i]);
        printf("END");
        p=p->next;
    }
}
void dell(int r,int c)
{
    int ad=-1,ss=0;
    nodeptr p=list,q,s=list;
    while(p!=NULL)
    {
        if(ad)
        p=s;
        ad=0;
        if(p->sol[c]!=r)
            ad=1;
        if(ad)
        {
            if(p==list)
                list=p->next;
            else
            {
                q=list;
                while(q->next!=p)
                    q=q->next;
                q->next=p->next;
            }
            s=p->next;
            if(s==NULL)
                ss=1;
            free(p);
        }
        if(!ad)
        p=p->next;
        if(ss)
            break;
    }
}
int count1()
{
    int c=0;
    nodeptr p=list;
    while(p!=NULL)
    {
        ++c;
        p=p->next;
    }
    return c;
}
void play(int n)
{
    int co,row,col,i=0;
    while(count1())
    {
        i++;
    printf("\nEnter row and column no where you want to place the Queen:");
    scanf("%d%d",&row,&col);
    dell(row,col-1);
 //   display();
    if(i==n)
    {
        printf("\nCongratulations\n");
        break;
    }
    co=count1();
    if(!co)
        printf("\nGame over\n");
    else
        printf("\nThere are %d possible ways to win the game currently\n",co);
    }
}
int board[20],count;

int main()
{
 int n,i,j;
 void queen(int row,int n);

 printf(" - N Queens Problem Using Backtracking -");
 printf("\n\nEnter number of Queens:");
 scanf("%d",&n);
 queen(1,n);
 display(n);
 play(n);
 return 0;
 }

//function for printing the solution
void print(int n)
{
 int i,j;
 printf("\n\nSolution %d:\n\n",++count);

 for(i=1;i<=n;++i)
  printf("\t%d",i);

 for(i=1;i<=n;++i)
 {
  printf("\n\n%d",i);
  for(j=1;j<=n;++j) //for nxn board
  {
   if(board[i]==j)
    printf("\tQ"); //queen at i,j position
   else
    printf("\t-"); //empty slot
  }
 }
push(board,n);
}

/*funtion to check conflicts
If no conflict for desired postion returns 1 otherwise returns 0*/
int place(int row,int column)
{
 int i,c=0;
 for(i=1;i<=row-1;++i)
 {
  if(board[i]==column)
  {
   return c;
  }
  else
   if(abs(board[i]-column)==abs(i-row))
   {
    return 0;
   }
 }

 return 1; //no conflicts
}
int ad=0;
//function to check for proper positioning of queen
void queen(int row,int n)
{
 int column;
 for(column=1;column<=n;++column)
 {
  if(place(row,column))
  {
   board[row]=column; //no conflicts so place queen
   if(row==n)
    print(n);
   else 
    queen(row+1,n);
  }
 }
}
