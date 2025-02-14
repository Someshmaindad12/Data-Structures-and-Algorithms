// Delete all occurrences of a given key in a doubly linked list

#include<bits/stdc++.h>
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
    public:
        PNODE First;
        int iCount;

        DoublyLL();
        ~DoublyLL();

        void InsertLast(int);
        void DeleteKeyElement(int);

        void Display();
        int Count();
};

DoublyLL :: DoublyLL()
{
    this->First = NULL;
    this->iCount = 0;
}

DoublyLL :: ~DoublyLL()
{
    PNODE temp = First;

    while(temp != NULL)
    {
        First = First->next;
        delete temp;
        temp = First;
    }
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

void DoublyLL :: DeleteKeyElement(int iNo)
{
    PNODE temp = First;

    while (temp != NULL)
    {
        if(temp->data == iNo)
        {   
            
        }

        else
        {
            temp = temp->next;
        }
    }
    
    
}

void DoublyLL::Display()
{
    cout << "\nThe elements of the linked list are : \nNULL <-> ";

    PNODE temp = First;

    while (temp != NULL)
    {
        cout << "| " << temp->data << " | <-> ";
        temp = temp->next;
    }

    cout << "NULL \n";
}

int DoublyLL :: Count()
{
    return iCount;
}

int main()
{
    DoublyLL dobj;

    dobj.InsertLast(2);
    dobj.InsertLast(2);
    dobj.InsertLast(10);
    dobj.InsertLast(8);
    dobj.InsertLast(4);
    dobj.InsertLast(2);
    dobj.InsertLast(5);
    dobj.InsertLast(2);
    
    dobj.Display();
    cout<<"The number of elements in the linked list are : "<<dobj.Count()<<"\n\n";

    dobj.DeleteKeyElement(2);
    dobj.Display();
    cout<<"The number of elements in the linked list are : "<<dobj.Count()<<"\n\n";
    
    return 0;
}