#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct node

{
    
    int info;
    
    struct node *next;
    
}*start;


class link_llist

{
    
public:
    
    node* create_node(int);
    
    void insert_begin();
    
    void insert_pos();
    
    void insert_last();
    
    void delete_pos();
    
    void delete_begin();
    
    void delete_last();
    
    void display();
    
    link_llist()
    
    {
        
        start = NULL;
        
    }
    
};



int main()

{
    
    int choice;
    
    link_llist ll;
    
    start = NULL;
    
    while (1)
        
    {
        
        cout<<endl<<"---------------------------------"<<endl;
        
        cout<<endl<<"linked list"<<endl;
        
        cout<<endl<<"---------------------------------"<<endl;
        
        cout<<"1.Insert Node at beginning"<<endl;
        
        cout<<"2.Insert node at last"<<endl;
        
        cout<<"3.Insert node at position"<<endl;
        
        cout<<"4.Delete a node at position"<<endl;
        
        cout<<"5.Delete node at beginning"<<endl;
        
        cout<<"6.Delete noode at Last"<<endl;
        
        cout<<"7.Display Linked List"<<endl;
        
        cout<<"8.Exit "<<endl;
        
        cout<<"Enter your choice : ";
        
        cin>>choice;
        
        switch(choice)
        
        {
                
            case 1:
                
                cout<<"Inserting Node at Beginning: "<<endl;
                
                ll.insert_begin();
                
                cout<<endl;
                
                break;
                
            case 2:
                
                cout<<"Inserting Node at Last: "<<endl;
                
                ll.insert_last();
                
                cout<<endl;
                
                break;
                
            case 3:
                
                cout<<"Inserting Node at position:"<<endl;
                
                ll.insert_pos();
                
                cout<<endl;
                
                break;
                
            case 4:
                
                cout<<"Delete node at position: "<<endl;
                
                ll.delete_pos();
                
                break;
                
            case 5:
                
                cout<<"Delete node at beginning"<<endl;
                
                ll.delete_begin();
                
                
                break;
                
            case 6:
                
                cout <<"Delete a node at last"<<endl;
                
                ll.delete_last();
                
                break;
                
            case 7:
                
                cout<<"Display elements of link list"<<endl;
                
                ll.display();
                
                cout<<endl;
                
                break;
                
            case 8:
                
                cout<<"Exiting..."<<endl;
                
                exit(1);
                
                break;
                
            default:
                
                cout<<"Wrong choice"<<endl;
                
        }
        
    }
    
}


node *link_llist::create_node(int value)

{
    
    struct node *temp;
    
    temp = new(struct node);
    
    if (temp == NULL)
        
    {
        
        cout<<"Memory not allocated "<<endl;
        
        return 0;
        
    }
    
    else
        
    {
        
        temp->info = value;
        
        temp->next = NULL;
        
        return temp;
        
    }
    
}


void link_llist::insert_begin()

{
    
    int value;
    
    cout<<"Enter the value to be inserted: ";
    
    cin>>value;
    
    struct node *temp, *p;
    
    temp = create_node(value);
    
    if (start == NULL)
        
    {
        
        start = temp;
        
        start->next = NULL;
        
    }
    
    else
        
    {
        
        p = start;
        
        start = temp;
        
        start->next = p;
        
    }
    
    cout<<"Element Inserted at beginning"<<endl;
    
}


void link_llist::insert_last()

{
    
    int value;
    
    cout<<"Enter the value to be inserted: ";
    
    cin>>value;
    
    struct node *temp, *s;
    
    temp = create_node(value);
    
    s = start;
    
    while (s->next != NULL)
        
    {
        
        s = s->next;
        
    }
    
    temp->next = NULL;
    
    s->next = temp;
    
    cout<<"Element Inserted at last"<<endl;
    
}

void link_llist::insert_pos()

{
    
    int value, pos, counter = 0;
    
    cout<<"Enter the value to be inserted: ";
    
    cin>>value;
    
    struct node *temp, *s, *ptr = NULL;
    
    temp = create_node(value);
    
    cout<<"Enter the postion at which node to be inserted: ";
    
    cin>>pos;
    
    int i;
    
    s = start;
    
    while (s != NULL)
        
    {
        
        s = s->next;
        
        counter++;
        
    }
    
    if (pos == 1)
        
    {
        
        if (start == NULL)
            
        {
            
            start = temp;
            
            start->next = NULL;
            
        }
        
        else
            
        {
            
            ptr = start;
            
            start = temp;
            
            start->next = ptr;
            
        }
        
    }
    
    else if (pos > 1  && pos <= counter)
        
    {
        
        s = start;
        
        for (i = 1; i < pos; i++)
            
        {
            
            ptr = s;
            
            s = s->next;
            
        }
        
        ptr->next = temp;
        
        temp->next = s;
        
    }
    
    else
        
    {
        
        cout<<"Positon out of range"<<endl;
        
    }
    
}


void link_llist::delete_pos()

{
    
    int pos, i, counter = 0;
    
    if (start == NULL)
        
    {
        
        cout<<"List is empty"<<endl;
        
        return;
        
    }
    
    cout<<"Enter the position of value to be deleted: ";
    
    cin>>pos;
    
    struct node *s, *ptr = NULL;
    
    s = start;
    
    if (pos == 1)
        
    {
        
        start = s->next;
        
    }
    
    else
        
    {
        
        while (s != NULL)
            
        {
            
            s = s->next;
            
            counter++;
            
        }
        
        if (pos > 0 && pos <= counter)
            
        {
            
            s = start;
            
            for (i = 1;i < pos;i++)
                
            {
                
                ptr = s;
                
                s = s->next;
                
            }
            
            ptr->next = s->next;
            
        }
        
        else
            
        {
            
            cout<<"Position out of range"<<endl;
            
        }
        
        free(s);
        
        cout<<"Element Deleted"<<endl;
        
    }
    
}

void link_llist::delete_begin()

{
    node *temp;
    temp = start;
    start = start -> next;
    delete temp;
}

void link_llist::delete_last()
{
    node *temp1, *temp2;
    if(start == NULL)
        cout << "The list is empty!" << endl;
    else
    {
        temp1 = start;
            while (temp1 ->next != NULL)
            {
                temp2=temp1;
                temp1 = temp1 -> next;
            }
        delete temp1;
        temp2->next= NULL;
    }
    
}

void link_llist::display()

{
    
    struct node *temp;
    
    if (start == NULL)
        
    {
        
        cout<<"The List is Empty"<<endl;
        
        return;
        
    }
    
    temp = start;
    
    cout<<"Elements of list are: "<<endl;
    
    while (temp != NULL)
        
    {
        
        cout<<temp->info<<"->";
        
        temp = temp->next;
        
    }
    
    cout<<"NULL"<<endl;
    
}
