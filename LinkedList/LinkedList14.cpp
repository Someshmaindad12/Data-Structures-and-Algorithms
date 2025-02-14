// find pairs with given sum in dll

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
        vector<pair<int,int>> findPairSum(int);

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

vector<pair<int,int>> DoublyLL :: findPairSum(int iNo)
{
    int iSum = 0;
    vector<pair<int,int>> iResult;

    PNODE left = First;
    PNODE right = First;

    while(right->next != NULL)
    {
        right = right->next;
    }

    while(left != NULL && right != NULL && left != right && left->next != right)
    {
        iSum = left->data + right->data;

        if(iSum == iNo)
        {
            iResult.push_back({left->data,right->data});
            left = left->next;
            right = right->prev;
        }

        else if(iSum < iNo)
        {
            left = left->next;
        }

        else
        {
            right = right->prev;
        }
    }
    

    return iResult;
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
    dobj.InsertLast(2);
    dobj.InsertLast(4);
    dobj.InsertLast(5);
    dobj.InsertLast(6);
    dobj.InsertLast(8);
    dobj.InsertLast(9);

    dobj.Display();
    cout<<"The number of elements in the linked list are : "<<dobj.Count()<<"\n\n";

    vector<pair<int,int>> iRet = dobj.findPairSum(7);
    
    cout<<"The pair with the summation are : ";
    
    for(auto it : iRet)
    {
        cout<<"("<<it.first<<", "<<it.second<<")"<<"\t";
    }

    return 0;
}