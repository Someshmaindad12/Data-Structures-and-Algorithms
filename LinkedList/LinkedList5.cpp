// Reverse SLL

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
        int iCount;
        PNODE First;

    public:
        SinglyLL();
        ~SinglyLL();

        void Display();
        int Count();

        void InsertLast(int);
        void ReverseLL();
        void ReverseLLMethod2();
};

SinglyLL :: SinglyLL()
{
    this->iCount = 0;
    this->First = NULL;
}

SinglyLL :: ~SinglyLL()
{
    PNODE temp = First;

    while(temp != NULL)
    {
        First = First->next;
        delete temp;
        temp = First;
    }
}

void SinglyLL :: Display()
{
    PNODE temp = First;

    cout<<"Elements of the linked list are : \n";

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

void SinglyLL :: ReverseLL()
{
    stack<int> st;
    PNODE temp = First;

    while(temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    int iData = 0;
    temp = First;

    while(temp != NULL)
    {
        iData = st.top();
        temp->data = iData;
        st.pop();
        temp = temp->next;
    }
}

void SinglyLL :: ReverseLLMethod2()
{
    PNODE temp = First;
    PNODE Front = NULL;
    PNODE prev = NULL;
    
    while(temp != NULL)
    {
        Front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = Front;
    }

    First = prev;
}

int main()
{
    SinglyLL sobj;

    sobj.InsertLast(11);
    sobj.InsertLast(12);
    sobj.InsertLast(13);
    sobj.InsertLast(14);
    sobj.InsertLast(15);
    sobj.InsertLast(16);
    sobj.Display();
    cout<<"Number of elements in the linked list are : "<<sobj.Count()<<endl;

    sobj.ReverseLLMethod2();
    sobj.Display();
    
    return 0;
}