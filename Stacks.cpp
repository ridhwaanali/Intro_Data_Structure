//
//  main.cpp
//  stackppw
//
//  
//  
//
#include <cmath>
#include <iostream>
#include <stack>
using namespace std;

int top = -1;
int zstack[10];

void Push(int value)
{
    if (top == 9)
    {
        cout << "Stack Overflow!" << endl;
    }
    else
    {
        top++;
    zstack[top] = value;
    }
}
void Pop()
{
    if (top == -1)
    {
        cout << "Stack Underflow! Stack is empty" << endl;
    }
    else
    {
        top--;
        cout << zstack[top] << " has been popped" << endl;
    }
}
void Display()
{
    if (top == -1)
    {
        cout << " empty stack :( " << endl;
    }
    else
    {
        cout << " the stack from bottom to top is as followed:" << endl;
        for(int i = 0; i<=top; i++)
        {
            cout << " " << zstack[i];
        }
        cout << endl;
    }
}
void Empty()
{
    if (top < 0)
    {
        cout << "the stack IS empty" << endl;
    }
    else
    {
        cout << "the stack is NOT empty" << endl;
    }
}
void Purge()
{
    cout << "The stack has been killed. All information has been erased" << endl;
    top = -1;
}

int main()
{
    int value;
    int choice;
    do
    {
    cout << "1. Push a number\t" ;
    cout << "2. Pop a number" << endl;
    cout << "3. Display Stack\t" ;
    cout << "4. Stack Empty?" << endl;
    cout << "5. Display Top\t  ";
    cout << "6. Purge the Stack\t";
    cout << "7. Escape" << endl;
        
    cin >> choice;
    
    switch(choice)
            {
case 1:
        {
                if (choice == 1)
                {
                cout << "Enter a value" << endl;
            cin >> value;
                cout << "the number " << value << " has been remembered!" << endl;
            Push(value);
            break;
            }
        }
case 2:
        {
            if (choice == 2)
            {
                Pop();
                break;
            }
        }
case 3:
        {
            if (choice ==3)
            {
                Display();
                break;
            }
        }
case 4:
        {
            if (choice ==4)
            {
                Empty();
                break;
            }
        }
case 5:
                {
            if (choice == 5)
                    {
                        cout  <<  zstack[top] << " is at top of the stack" << endl;
                        break;
                    }
                }
case 6:
                {
            if (choice == 6)
                    {
                Purge();
                        break;
                    }
                }
default:
                {
                    cout << "Please enter a valid option" << endl;
                }
        }
    }while (choice != 7 );
    cout << "exiting..............." << endl;
    return 0;
        
    
}

