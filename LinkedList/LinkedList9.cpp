// Delete the Nth node of LL

#include<iostream>
using namespace std;

typedef class Node
{
    public:

        Node *prev;
        int data;
        Node *next;

        Node()
        {
            this->prev = NULL;
            this->data = 0;
            this->next = NULL;
        }

        Node(int iNo)
        {
            this->prev = NULL;
            this->data = iNo;
            this->next = NULL;
        }
}NODE,*PNODE;

class DoublyLL 
{
    private:
        PNODE First;
        int iCount;

    public:
        DoublyLL();

        void InsertLast(int);

        void DeleteLast();
        void DeleteFirst();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

DoublyLL :: DoublyLL()
{
    this->First = NULL;
    this->iCount = 0;
}

void DoublyLL :: InsertLast(int iNo)
{
    PNODE newn = new NODE(iNo);

    if(First == NULL)
    {
        First = newn;
    }

    else 
    {
        PNODE temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        newn->prev = temp;
        temp->next = newn;
    }

    iCount++;
}

void DoublyLL :: Display()
{
    PNODE temp = First;

    cout<<"The elements of the linked list are : \n NULL <-> ";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | <-> ";
        temp = temp->next;
    }

    cout<<"NULL \n";
}

int DoublyLL :: Count()
{
    return iCount;
}

void DoublyLL :: DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }

    else if(iCount == 1)
    {
        delete First;
        First = NULL;
    }

    else
    {
        First = First->next;
        delete First->prev;
        First->prev = NULL;
    }

    iCount--;
}

void DoublyLL :: DeleteLast()
{
    if(First == NULL)
    {
        return;
    }

    else if((First->next == NULL) && (First->prev == NULL))
    {
        delete First;
        First = NULL;
    }

    else
    {
        PNODE temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    iCount--;
}

void DoublyLL :: DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }

    else if(iPos == iCount)
    {
        DeleteLast();
    }

    else
    {
        PNODE temp = First;

        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

int main()
{
    DoublyLL dobj;
    int iPos = 0;

    dobj.InsertLast(1);
    dobj.InsertLast(11);
    dobj.InsertLast(21);
    dobj.InsertLast(51);
    dobj.InsertLast(101);
    dobj.InsertLast(111);

    dobj.Display(); 
    cout<<"Number of Nodes in DLL are : "<<dobj.Count()<<"\n\n";
    
    cout<<"Enter the position that you want to delete : ";
    cin>>iPos;

    dobj.DeleteAtPos(iPos);
    dobj.Display();
    cout<<"Number of Nodes in DLL are : "<<dobj.Count()<<"\n\n";

    return 0;
}