#include<iostream>
#include<fstream>
#include<string>
#include<cstdio>
#include<cstdlib>

typedef int INFO_RC;
struct NODE;
typedef NODE * PT_NODE;
              struct NODE {
                         	INFO_RC info;
                            PT_NODE next;
                                        };
    struct QUEUE{
					PT_NODE front;
					PT_NODE back;
                                };
void create_Queue(QUEUE &q)
{
   q.front=NULL,q.back=NULL;
}
int empty(QUEUE q)
{
 (q.front == 0, q.back==0);
  return ! q.front;
  return ! q.back;
} 
void purge_Queue(QUEUE &q)
{
   q.front = q.back = NULL;
}
void deq (QUEUE &q, int & item)
{
if(q.front == NULL)
q.back = NULL;
else
     {
		item = q.front -> info;
   	   	q.front = q.front ->next;
        }
} 
void enq (QUEUE &q, const int & item)
{

  PT_NODE  P = new NODE;
  P -> info = item;
  P -> next = NULL;

 if(q.front == NULL)
     q.front = P; 
 else
     q.back -> next = P;
     q.back = P; 
}
