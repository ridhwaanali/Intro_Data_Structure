#include <cmath>
#include <iostream>
#include <stack>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

class Stack
{
    struct node *top;
public:
    Stack()
    {
        top = NULL;
    }
    void Push();
    void Pop();
    void Display();
    void Empty();
    void Purge();
};
void Stack::Push()
{
    int value;
    struct node *ptr;
    cout << "Enter an ID to enter" << endl;
    cin >> value;
    ptr = new node;
    ptr->data = value;
    ptr->next = NULL;
    if(top != NULL)
        ptr->next=top;
        top=ptr;
    cout << value << " has been remembered!" << endl << endl;
    
}
void Stack::Pop()
{
    struct node *temp;
    if (top == NULL)
    {
        cout << "Stack Underflow! Stack is empty" << endl;
    }
    else
    {
        temp=top;
        top=top->next;
        cout << "Top has been popped" << endl;
        delete temp;
    }
}
void Stack::Display()
{
    struct node *ptr1=top;
    if (top == NULL)
    {
        cout << " empty stack :( " << endl;
    }
    else
    {
        cout << " the stack from top to bottom is as followed:" << endl;
        while (ptr1 != NULL)
        {
            cout << ptr1->data << "\t" << endl;
            ptr1=ptr1->next;
        }
    }cout << "NULL" << endl;
}
void Stack::Empty()
{
    if (top == NULL)
    {
        cout << "the stack iS empty" << endl;
    }
    else
    {
        cout << "the stack is NOT empty" << endl;
    }
}


int main()
{
    int choice;
    Stack s;
    do
    {
    cout << "1. Push an ID number\t" ;
    cout << "2. Pop an ID number" << endl;
    cout << "3. Display Stack\t" ;
    cout << "4. Stack Empty?" << endl;
    cout << "5. Escape" << endl;
        
    cin >> choice;
    
    switch(choice)
            {
case 1:
        
            s.Push();
            break;
        
case 2:
        {
            s.Pop();
            break;
        }
case 3:
        {
            s.Display();
            break;
        }
case 4:
        {
            s.Empty();
            break;
        }

default:
                {
                    cout << "Please enter a valid option" << endl;
                }
        }
    }while (choice != 5 );
    cout << "exiting..............." << endl;
    return 0;
        
    
}
    

    

    

    
    
    
    

