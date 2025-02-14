// Reverse the DLL

#include<iostream>
#include<stack>
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
        void DeleteLast();
        void ReverseLLMethod1();
        void ReverseLLMethod2();

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

void DoublyLL :: ReverseLLMethod1()
{
    PNODE temp1 = First;
    PNODE temp2 = First;
    stack<int> st;

    while(temp1 != NULL)
    {
        st.push(temp1->data);
        temp1 = temp1->next;
    }

    int iData = 0;

    while(temp2 != NULL)
    {
        iData = st.top();
        temp2->data = iData;
        st.pop();
        temp2 = temp2->next;
    }
}

void DoublyLL :: ReverseLLMethod2()
{
    if(First == NULL || First->next == NULL)
    {
        return;
    }

    PNODE temp = NULL;
    PNODE current = First;

    while(current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }

    if(temp != NULL)
    {
        First = temp->prev;
    }
}

void DoublyLL :: DeleteLast()
{
    if(First == NULL)
    {
        return;
    }

    else if(First->next == NULL)
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

    dobj.InsertLast(11);
    dobj.InsertLast(21);
    dobj.InsertLast(51);
    dobj.InsertLast(101);
    dobj.InsertLast(111);
    
    dobj.Display();
    cout<<"The number of elements in the linked list are : "<<dobj.Count()<<"\n\n";

    dobj.ReverseLLMethod2();
    dobj.Display();
    cout<<"The number of elements in the linked list are : "<<dobj.Count()<<"\n\n";
    
    return 0;
}