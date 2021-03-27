/*STATIC IMPLEMENTATION OF STACK USING C*/
#include<stdio.h>
#define CAPACITY 5   //PRE-PROCESSING MICRO
int stack[CAPACITY]; //GLOBAL ARRAY 
int top=-1;          //GLOBAL DECLERATIONS
push(int);
isfull();
traverse();
isempty();
peek();

void main()
    {
        int ch, item;
        while(1)
        {
            printf("Different choices are:\n");
            printf("1.push\n");
            printf("2.pop\n");
            printf("3.peek\n");
            printf("4.traverse\n");
            printf("5.exit\n");
            printf("enter your choice: ");
            scanf("%d",&ch);
            printf("your choice was: %d\n",ch);
                switch(ch)
                    {
                        case 1:
                                printf("enter element for push:");
                                scanf("%d",&item);
                                push(item);
                                break;
                        case 2: printf("pop command is given\n");
                                pop();
                                break;
                        case 3: peek();
                                break;
                        case 4: traverse();
                                break;
                        case 5: exit(0);
                        default: printf("invalid input\n");
                    }
                printf("\n");
                }
        }

    push(int ele)
        {
        if(isfull())                   //IF ISFULL() IS 1 i.e true then printf()  
            {
                printf("stack is overflow\n"); 
            }
        else                            //now return from isfull() is 0 so, top=-1 ==> top+1==>top=0 points to stack[0] and pushes element
            {
            top++;                      //top=-1 ==> top+1==>top=0
            stack[top]=ele;             //points to stack[0] and pushes element
            printf("pushed element is %d\n",stack[top]);
            }
        }

  isfull()
   {
     if(top==CAPACITY-1)                //i.e top=-1 ==> capacity-1==>5-1==4
      {
       return 1;                       // if stack is full
      }
     else
      {
     return 0;
      }
   }

    traverse()
    {
        if(isempty())
        {
            printf("stack is empty\n");
        }
        else
            {
            int i;
            printf("stack elements are: ");
                for(i=0;i<=top;i++)
                {
                printf("%d ",stack[i]);
                }
            }
        printf("\n");
    }

    isempty()
    {
        if(top==-1)  //top=-1 is initial decleration implies no element in stack 
        {
           return 1;
        }
        else
        {
           return 0;
        }
    }

    peek()
    {
      printf("peek element is: %d\n",stack[top]);
    }

    pop()
    {
        if(isempty())
        {
            printf("stack is underflow\n");
        }
        else
        {
            printf("popped element is: %d\n",stack[top]);  //points to top most element in stack==> stack[4]
            top--;                                        //stack[3]..
        }
    }
