////
//  main.cpp
//  queue
//
#include<iostream>
#include<fstream>
#include<string>

typedef int INFO_RC;
using namespace std;

struct QUEUE{
    INFO_RC i[30];
    int front;
    int back;
    };


void create_queue(QUEUE&);



void form_queue(QUEUE&);



bool empty(QUEUE&);
void enque(QUEUE&, int);
int deque(QUEUE&, int&);
void purge(QUEUE&);


void create_queue(QUEUE &queue){
    queue.front = 0;
    queue.back = 0;
    
}
void enque(QUEUE &queue, int item){
    queue.i[queue.back] = item;
    queue.back = queue.back + 1;
    
}
void deque(QUEUE &queue, int *item){
    if(!empty(queue)){
        *item = queue.i[queue.front];
        queue.front = queue.front + 1;
        
    }
    
}



void form_queue(QUEUE &queue){
    
    create_queue(queue);
    int num_items;
    cout << "How many numbers do you want to store? ";
    cin >> num_items;
    int item;
    
    for(int i=0; i < num_items; i++){
        cout << "Enque data " << (i+1) << ": ";
        cin >> item;
        enque(queue, item);
        
    }
    
}
bool empty(QUEUE &queue){
    
    if(queue.front >= queue.back){
        return true;
    }else{
        return false;
        
    }
    
}



void print_queue(QUEUE &queue){
    for(int i = queue.front; i < queue.back; i++){
        cout << queue.i[i] << " ";
    }
    cout << endl;
    
}
void purge(QUEUE &queue){
    while(!empty(queue)){
        int item;
        deque(queue, &item);
    }
    queue.front = 0;
    queue.back = 0;
}

int main(){
    QUEUE data;
 
    QUEUE queue_1_9;
    QUEUE queue_10_19;
    QUEUE queue_20_29;
    QUEUE queue_30_more;
    form_queue(data);
    create_queue(queue_1_9);
    create_queue(queue_10_19);
    create_queue(queue_20_29);
    create_queue(queue_30_more);
    
    cout << "Queue: ";
    
    print_queue(data);
    while(!empty(data)){
        int item;
        deque(data, &item);
        if(item < 10){
            enque(queue_1_9, item);
        }
        else if(item >= 10 && item < 20){
            enque(queue_10_19, item);
        }
        else if(item >= 20 && item < 29){
            
            enque(queue_20_29, item);
            }
        else if(item >= 30){
            enque(queue_30_more, item);
            
        }
        
    }
    
    cout << "The result is the categorized data:" << endl;
    cout << "1 to 9:\t";
    print_queue(queue_1_9);
    cout << "10 to 19:\t";
    print_queue(queue_10_19);
    cout << "20 to 29:\t";
    print_queue(queue_20_29);
    cout << "30 or more:\t";
    print_queue(queue_30_more);
    return 0;
    
}

