// DLL is palindrome or NOT

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
        bool Palindrome();
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

bool SinglyLL :: Palindrome()
{
    bool bFlag = false;

    if(First == NULL || First->next == NULL)
    {
        bFlag = true;
        return bFlag;
    }

    stack<int> st;
    bFlag = true;

    PNODE temp = First;

    while(temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = First;

    while(temp != NULL)
    {
        if(temp->data == st.top())
        {
            temp = temp->next;
            st.pop();   
        }

        else
        {
            bFlag = false;
            break;
        }
    }

    return bFlag; 
    
}

int main()
{
    SinglyLL sobj;
    int iPos = 0;

    sobj.InsertLast(1);
    sobj.InsertLast(11);
    sobj.InsertLast(21);
    sobj.InsertLast(21);
    sobj.InsertLast(11);
    sobj.InsertLast(1);

    sobj.Display(); 
    cout<<"Number of Nodes in SLL are : "<<sobj.Count()<<"\n\n";

    bool bRet = sobj.Palindrome();
    
    if(bRet == true)
    {
        cout<<"Linked list is padlindrome\n";
    }

    else
    {
        cout<<"Linked list is NOT padlindrome\n";
    }

    return 0;
}