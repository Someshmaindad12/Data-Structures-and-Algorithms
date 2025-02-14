// remove duplicate from sorted array

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
        void removeDuplicate();

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

void DoublyLL :: removeDuplicate()
{
    PNODE temp = First;
    PNODE tempX = NULL;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp->next->data == temp->data)
        {
            tempX = temp->next;

            temp->next = temp->next->next;

            if(temp->next->next != NULL)
            {
                temp->next->next->prev = temp;    
            }

            delete tempX;
            iCount--;
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

    dobj.InsertLast(1);
    dobj.InsertLast(1);
    dobj.InsertLast(1);
    dobj.InsertLast(2);
    dobj.InsertLast(3);
    dobj.InsertLast(4);

    dobj.Display();
    cout<<"The number of elements in the linked list are : "<<dobj.Count()<<"\n\n";

    dobj.removeDuplicate();
    dobj.Display();
    cout<<"The number of elements in the linked list are : "<<dobj.Count()<<"\n\n";
    
    return 0;
}