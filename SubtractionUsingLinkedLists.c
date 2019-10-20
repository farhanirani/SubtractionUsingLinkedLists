#include <stdio.h>
#include <stdlib.h>
struct node{
    int x;
    struct node *next;
};

struct headnode1{
    int count1;
    struct node *first;
    struct node *pos;
}*p1;

struct headnode2{
    int count2;
    struct node *first;
    struct node *pos;
}*p2;

struct final{
	int count3;
    struct node *first;
    struct node *pos;
}*p3;

void createHeadNodes()
{
    p1 = (struct headnode1 *)malloc(sizeof(struct headnode1));
    p2 = (struct headnode2 *)malloc(sizeof(struct headnode2));
    p3 = (struct final *)malloc(sizeof(struct final));
    p1->count1=0;
    p2->count2=0;
    p3->count3=0;
    p1->first=NULL;
    p2->first=NULL;
    p3->first=NULL;
}

void link1(int a)
{
    struct node *pNew; int i;
    pNew = (struct node *)malloc(sizeof(struct node));
    pNew->x=a;
    pNew->next=NULL;
    if(p1->first==NULL)
    {
        p1->first=pNew;
    }
    else
    {
    	p1->pos=p1->first;
        for(i=1;i<p1->count1;i++)
        {
        	p1->pos=p1->pos->next;
		}
		p1->pos->next=pNew;
    }
    p1->count1++;
}

void link2(int a)
{
    struct node *pNew; int i;
    pNew = (struct node *)malloc(sizeof(struct node));
    pNew->x=a;
    pNew->next=NULL;
    if(p2->first==NULL)
    {
        p2->first=pNew;
    }
    else
    {
    	p2->pos=p2->first;
        for(i=1;i<p2->count2;i++)
        {
        	p2->pos=p2->pos->next;
		}
		p2->pos->next=pNew;
    }
    p2->count2++;
}


void calc1()
{
    struct node *pNew;
    pNew = (struct node *)malloc(sizeof(struct node));
    pNew->next=p3->first;
    p3->first=pNew;
    
    if(p1->pos->x==-1)
    {
    	p1->pos->x=9;
    	p1->pos->next->x --;
	}
    
    if(p1->pos->x>=p2->pos->x)
    {
        pNew->x=((p1->pos->x)-(p2->pos->x));
    }
    else
    {
        pNew->x=((p1->pos->x + 10)-(p2->pos->x));
        p1->pos->next->x --;
    }
    p1->pos=p1->pos->next;
    p2->pos=p2->pos->next;
}


void calc2()
{
	if(p1->pos->x==-1)
    {
    	p1->pos->x=9;
    	p1->pos->next->x --;
	}
    struct node *pNew;
    pNew = (struct node *)malloc(sizeof(struct node));
    pNew->next=p3->first;
    p3->first=pNew;
    pNew->x=(p1->pos->x);
    p1->pos=p1->pos->next;
}


void main()
{
    int a,b,tempa,tempb;
    createHeadNodes();
    printf("enter a,b to find a-b:  \n");
    scanf("%d%d",&a,&b);
    if(b>a) exit(1);
    tempa = a;
    tempb = b;
    
    //to make the ll of numbers in reverse order
    while(a!=0)
    {
        link1(a%10);
        a=a/10;
    }
    while(b!=0)
    {
        link2(b%10);
        b=b/10;
    }
    
    p1->pos=p1->first;
    p2->pos=p2->first;
    
    while (tempb!=0)    
    {
        tempb/=10;
        tempa/=10;
        calc1();
    }
    while(tempa!=0)
    {
        tempa/=10;
        calc2();
    }
    
    p3->pos=p3->first;
    
    int i;
    for(i=0;i<p1->count1;i++)
    {
        printf("%d",p3->pos->x);
        p3->pos=p3->pos->next;
    }
}



