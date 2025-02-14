// Sort the LL

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

typedef class Node
{
    public:
        int data;
        Node *next;

        Node()
        {
            this->data = 0;
            this->next = NULL;
        }

        Node(int iNo)
        {
            this->data = iNo;
            this->next = NULL;
        }

}NODE,*PNODE;

class SinglyLL 
{
    private:
        PNODE First;
        int iCount;

    public:
        SinglyLL();

        void InsertLast(int);
        void Display();
        int Count();
        void SortLL();
};

SinglyLL :: SinglyLL()
{
    this->First = NULL;
    this->iCount = 0;
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

void SinglyLL :: Display()
{
    PNODE temp = First;

    cout<<"The elements of the linked list are : \n";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }

    cout<<"NULL \n";
}

int SinglyLL :: Count()
{
    return iCount;
}

void SinglyLL :: SortLL()
{ 
    int *Arr = new int[iCount];
    PNODE temp = First;

    for(int iCnt = 0; iCnt < iCount; iCnt++)
    {
        Arr[iCnt] = temp->data;
        temp = temp->next;
    }

    temp = First;

    sort(Arr,Arr + iCount);
    
    for(int iCnt = 0; iCnt < iCount; iCnt++)
    {
        temp->data = Arr[iCnt];
        temp = temp->next;
    }
}

int main()
{
    SinglyLL sobj;
    int iPos = 0;

    sobj.InsertLast(51);
    sobj.InsertLast(41);
    sobj.InsertLast(31);
    sobj.InsertLast(21);
    sobj.InsertLast(11);
    sobj.InsertLast(1);

    cout<<"Before sorting the LL \n";
    sobj.Display(); 
    cout<<"Number of Nodes in SLL are : "<<sobj.Count()<<"\n\n";

    cout<<"After sorting the LL \n";
    sobj.SortLL();
    sobj.Display();

    return 0;
}