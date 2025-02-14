// Segrregate odd and even nodes in LL

#include<bits/stdc++.h>
using namespace std;

typedef class Node
{
    public:
        int data;
        Node *next;

        Node(int iNo)
        {
            data = iNo;
            next = NULL;
        }

        Node()
        {
            data = 0;
            next = NULL;
        }
}NODE,*PNODE;

class SinglyLL
{   
    public:
        PNODE First;
        int iCount;

        SinglyLL();
        ~SinglyLL();

        void Display();
        int Count();

        void InsertLast(int);
        void EvenAndOdd();
};

SinglyLL :: SinglyLL()
{
    First = NULL;
    iCount = 0;
}

SinglyLL :: ~SinglyLL()
{
    PNODE temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        temp = First;
        First = First->next;
        delete temp;
    }
}

int SinglyLL :: Count()
{
    return iCount;
}

void SinglyLL :: Display()
{
    cout<<"The elements of the LinkedList are : \n";

    PNODE temp = First;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }

    cout<<"NULL";
}

void SinglyLL :: InsertLast(int iNo)
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

        temp->next = newn;
    }

    iCount++; 
}

void SinglyLL :: EvenAndOdd()
{
    PNODE evenStart = NULL;
    PNODE evenEnd = NULL;

    PNODE oddStart = NULL;
    PNODE oddEnd = NULL;

    PNODE temp = First;

    while(temp != NULL)
    {
        if(temp->data % 2 == 0)
        {
            if(evenStart == NULL)
            {   
                evenStart = evenEnd = temp;
            }

            else
            {
                evenEnd->next = temp;
                evenEnd = evenEnd->next;
            }
        }

        else
        {
            if(oddStart == NULL)
            {
                oddStart = oddEnd = temp;
            }

            else
            {
                oddEnd->next = temp;
                oddEnd = oddEnd->next;
            }
        }

        temp = temp->next;
    }

    if(oddStart == NULL || evenStart == NULL)
    {
        return;
    }

    evenEnd->next = oddStart;
    oddEnd->next = NULL;

    First = evenStart;
}

int main()
{
    SinglyLL sobj;

    sobj.InsertLast(1);
    sobj.InsertLast(2);
    sobj.InsertLast(3);
    sobj.InsertLast(4);
    sobj.InsertLast(5);
    sobj.InsertLast(6);
    sobj.InsertLast(7);
    sobj.InsertLast(8);
    
    sobj.Display();
    cout<<"\nNumber of elements in the linked list are : "<<sobj.Count()<<"\n\n";

    sobj.EvenAndOdd();
    sobj.Display();

    return 0;
}