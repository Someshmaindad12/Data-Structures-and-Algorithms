//This code is of Singly Linear LinkedList
#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
int data ;
struct node *next;
}NODE , *PNODE , **PPNODE ;

void InsertFirst(PPNODE head , int no )
{
    PNODE newn = NULL; 
    newn = (PNODE) malloc(sizeof(NODE));
    newn->data = no ;
    newn ->next = NULL;

    if(*head == NULL)
    {
        *head = newn ;
    }
    else 
    {
        newn ->next = *head ;
        *head = newn ;
    }
}
void InsertLast(PPNODE head , int no )
{
   PNODE newn = NULL; 
   PNODE temp = NULL;
    newn = (PNODE) malloc(sizeof(NODE));
    newn->data = no ;
    newn ->next = NULL;

    if(*head == NULL)
    {
        *head = newn ;
    }
    else 
    {
        temp = *head ;
        while(temp->next !=NULL)
        {
            temp = temp->next;
        }
        temp->next = newn ;

    }

}
void Display(PNODE head )
{
    while(head != NULL)
    {
        printf(" |%d |->",head->data);
        head = head->next;
    }
    printf(" NULL\n ");
}
int Count(PNODE head )
{
    int iCount = 0 ;

    while(head!= NULL)
    {
        iCount++;
        head = head ->next;
    }
    return iCount;

}
void DeleteFirst(PPNODE head )
{
    PNODE temp = NULL;
    if(*head == NULL)
    {
        return ;
    }
    if((*head)->next == NULL)
    {
        free(*head );
        *head = NULL;

    }
    else 
    {
        temp = *head ;
        *head = (*head) ->next;
        free(temp);

    }
}
void DeleteLast(PPNODE head )
{
    PNODE temp = NULL;
    if(*head ==NULL)
    {
        return ;
    }
    if((*head)->next == NULL)
    {
        free(*head );
        *head = NULL;
    }
    else 
    {
        temp = *head ;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        free(temp->next);
        temp->next = NULL;


    }
}
void InsertAtPos(PPNODE head , int no , int ipos )
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no ; 
    newn ->next = NULL;

    int i = 0 ; 
    int CountNodes =  0 ; 
    CountNodes = Count(*head);
    if((ipos < 1) ||( ipos > CountNodes+1) )
    {
        printf("Invalid Position");
        return;
    }
    if(ipos ==1 )
    {
        InsertFirst(head ,no);
    }
    else if(ipos == CountNodes+1)
    {
        InsertLast(head,no);
    }
    else 
    {
        temp = *head ;
        for(i = 1 ; i< ipos -1; i++ )
        {
            temp = temp->next;
        }
        newn ->next = temp->next;
        temp->next = newn;

    }
}
void DeleteAtPos(PPNODE head , int ipos)
{
    PNODE temp = NULL;
    PNODE target = NULL;

    int i = 0 ; 
    int CountNodes = 0 ; 
    CountNodes = Count(*head);
    if((ipos < 1 ) || (ipos > CountNodes))
    {
        printf("Invalid Position !!!!");
        return;
    }
    if(ipos == 1)
    {
        DeleteFirst(head);
    }
    else if(ipos == CountNodes)
    {
        DeleteLast(head );
    }
    else 
    {
        temp = *head ;
        for(i =1 ; i<ipos-1 ; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp ->next = target ->next;
        free(target);
    }
}

int main()
{   int iRet = 0 ;
    PNODE first = NULL;
    InsertFirst(&first, 51);
    InsertFirst(&first, 21);
    InsertFirst(&first, 11);

    InsertLast(&first,101);
    InsertLast(&first,111);
    InsertLast(&first,121);
    
    // DeleteFirst(&first);
    // DeleteLast(&first);

    InsertAtPos(&first , 75,4);
    DeleteAtPos(&first , 4);
    
    
    

    iRet = Count(first);
    printf("Total nodes are : %d ",iRet );
    Display(first);


    return 0;
}
