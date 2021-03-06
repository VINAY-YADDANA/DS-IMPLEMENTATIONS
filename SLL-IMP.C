/******************************************************************************
SINGLE LINKED LIST IMPLEMENTATION
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* link;     
};
struct node* root=NULL;
int len;
void append(void);
void insert(void);
/*void addatend(void);*/
int length(void);
void display(void);
void delete(void);


void main()
{   
    int ch;
    while(1)
    {
        printf("Single linked list operations!\n");
        printf("1.Append\n");
        printf("2.Insert at location:\n");
       /* printf("3.Add at end\n"); */
        printf("4.Length\n");
        printf("5.Display nodes\n");
        printf("6.Delete a node\n");
        printf("7.Quit\n");
        
        printf("Enter your choice:");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1: append();
                    break;
            case 2: insertat();
                    break;
            /*case 3: addatend();
                    break;*/
            case 4: len = length();
                    printf("length of Single linked list is:%d\n\n",len);
                    break;
            case 5: display();
                    break;
            case 6: delete();
                    break;
            case 7: exit(1);
            
            default: printf("Invalid input\n");
        }
    }
}
void append()
{
   struct node* temp;
   
   temp=(struct node*)malloc(sizeof(struct node));
   
   printf("Enter node data:");
   scanf("%d",&temp->data);
   temp->link=NULL;
   if(root==NULL)
   {
        root=temp;
   }
   else
   {
        struct node* p;
        
        p=root;
        
        while(p->link!=NULL)
        {
            p=p->link;
        }
        
        p->link=temp;
   }
    
}

int length()
{
    int count=0;
    struct node* temp;
    temp=root;
    
    while(temp!=NULL)
    {
        count++;
        temp=temp->link;
    }
    
    return count;
}

void display()
{   struct node* temp;
    temp=root;
    if(temp==NULL)
    {
      printf("No Nodes to display\n");  
    }
    while(temp!=NULL)
    {
        printf("%d-->",temp->data);
        temp = temp->link;
    }
}

void insertat(void)
{
    int loc,len,i=1;
    struct node *temp,*p;
    printf("Enter location where to insert:");
    scanf("%d",&loc);
    len=length();
    if(loc>len)
    {
        printf("Entered location is out of Single linked list boundary i.e:%d",len);
    }
    else
    {   
        p=root;
        while(i<loc)
        {
            p=p->link;
            i++;
        }
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter data for new node:");
        scanf("%d",&temp->data);
        temp->link=NULL;
       // temp=p;
        temp->link=p->link;
        p->link=temp;
        
    }
    
    
    
}
/*void addatend(void)
{
    
}*/
void delete(void)
{
    struct node* temp;
    int loc;
    printf("Enter location to delete node:");
    scanf("%d",&loc);
    if(loc>length())
    {
        printf("Invalid location\n");
    }
    else if(loc=1)
    {
        temp=root;
        root=temp->link;
        temp->link=NULL;
        free(temp);
    }
    else
    {
        struct node *p,*q;
        int i=1;
        p=root;
        while(i<loc-1)
        {
            p=p->link;
            i++;
        }
        q=p->link;
        p->link=q->link;
        q->link=NULL;
        free(q);
        
    }

    
}
