// This code is of Singly Linear LinkedList using C++ and Object Orientation
#include<iostream>
using namespace std ;  

typedef  struct node
{
    int data ;
    struct node *next ; 
} NODE , *PNODE;

class SinglyLL
{
    public :
    PNODE head;
    int iCount; 

    SinglyLL()
    {
        head = NULL;
        iCount = 0 ;
    }

    void InsertFirst(int no)
    {
        PNODE newn = NULL;
        newn = new NODE;
        newn ->data = no ; 
        newn ->next = NULL;

        if(head == NULL)
        {
            head = newn ;
        }
        else 
        {
            newn->next= head;
            head=newn;
        }
        iCount++;
    }
    void InsertLast(int no)
    {
        PNODE newn = NULL;
        newn = new NODE ;
        newn ->data = no ; 
        newn ->next = NULL;

        PNODE temp = NULL;
        if(head ==  NULL)
        {
            head = newn;
        }
        else 
        {
            temp = head ;
            while(temp ->next != NULL)
            {
                temp = temp->next;
            }
            temp->next =  newn;

        }
        iCount++;
    }
    void Display()
    {
        PNODE temp  = NULL;
        temp = head ;
        while(temp!= NULL)
        {
            cout<<"|"<<temp->data<<"|->";
            temp =temp->next;
        }
        cout<<"NULL\n";
        
    }
    int Count()
    {
        return iCount;
    }

    void DeleteFirst()
    {
        PNODE temp = NULL;
        if(head == NULL)
        {
            return ;
        }
        if(head->next == NULL)
        {
            delete head ;
            head = NULL;
        }
        else
        {
            temp = head;
            head = head ->next ;
            delete temp;
        }
        iCount--;
    }
    void DeleteLast()
    {
        PNODE temp = NULL;
        if(head == NULL)
        {
            return ;
        }
        if(head ->next == NULL)
        {
            delete head ;
            head = NULL;
        }
        else 
        {
            temp = head ; 
            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }
        iCount--;
    }
    void InsertAtPos(int no , int ipos)
    {
        int i = 0 ; 
        int CountNodes = 0 ; 
        PNODE newn = NULL;
        PNODE temp = NULL;

        CountNodes = Count();
        newn = new NODE;
        newn->data = no ; 
        newn ->next = NULL;

        if((ipos < 1) || (ipos > CountNodes+1))
        {
            cout<<"Invalid Position !!!\n";
            return;
        }
        if(ipos == 1)
        {
            InsertFirst(no);
        }
        else if(ipos == CountNodes+1)
        {
            InsertLast(no );
        }
        else 
        {
            temp = head;
            for(i = 1 ; i< ipos-1 ; i++)
            {
                temp = temp->next ;
            }
            newn ->next = temp->next;
            temp->next = newn ;
        }
        iCount++;

    }
    void DeleteAtPos(int ipos )
    {
        int i = 0 ; 
        int CountNodes = 0 ; 
        PNODE target = NULL;
        PNODE temp = NULL;

        CountNodes = Count();
        

        if((ipos < 1) || (ipos > CountNodes))
        {
            cout<<"Invalid Position !!!\n";
            return;
        }
        if(ipos == 1)
        {
            DeleteFirst();
        }
        else if(ipos == CountNodes)
        {
            DeleteLast();
        }
        else 
        {
            temp = head;
            for(i = 1 ; i< ipos-1 ; i++)
            {
                temp = temp->next ;
            }
            target= temp->next ;
            temp->next = temp->next->next;
            delete target;
        }
        iCount--;

    }

};
int main()
{
    SinglyLL sobj;
    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.InsertLast(101);
    sobj.InsertLast(111);

    // sobj.DeleteFirst();
    // sobj.DeleteLast();

    sobj.InsertAtPos(74,4);
    sobj.Display();
    sobj.DeleteAtPos(4);

    sobj.Display();

    int iRet= 0 ; 
    iRet =  sobj.Count();
    cout<<"Total nodes are : "<<iRet<<"\n";
    return 0  ;
}
