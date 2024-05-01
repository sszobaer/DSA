#include <bits/stdc++.h>
#define size 5

using namespace std;

class Queue{
 private:
     int items[size],front, rear;

 public:
    Queue(){
    front = -1;
    rear = -1;
    }

    bool isFull(){
    if (front== 0 && rear == size-1){
        return true ;}
        if (front == rear+1){
            return true;
        }
    return false;
    }

    bool isEmpty(){
    if(front == -1)
        return true;
    else
        return false;
    }

    void enQueue(int element){
    if(isFull()){
        cout<<"Queue is overflow";
    }
    else{
        if(front == -1)front = 0;
        rear = (rear+1)%size;
        items[rear] = element;
         cout<<"\n Inserted"<<element<<endl;
    }

    }

    int deQueue(){
    int element;
    if(isEmpty()){
        cout<<"Queue is underflow"<<endl;
        return (-1);
    }
    else{
        element = items[front];
        if(front == rear){
            front = -1;
            rear =-1;
        }
        else{
            front = (front + 1)%size ;
        }
        return (element);
    }
    }

    void display()
    {
        int i;
        if(isEmpty()){
            cout<<"\n Empty Queue"<<endl;
        }
        else{
            cout<<"Front =  "<<front;
            cout<<"\n items = ";
            for(i=front; i != rear; i=(i+1)%size)
                cout<<items[i];
            cout<<items[i];
            cout<<"\n Rear = "<<rear;
        }
    }
};

int main()
{
    Queue q;


  q.deQueue();

  q.enQueue(1);
  q.enQueue(2);
  q.enQueue(3);
  q.enQueue(4);
  q.enQueue(5);


  q.enQueue(6);

  q.display();

  int elem = q.deQueue();

  if (elem != -1)
    cout << endl
       << "Deleted Element is : " << elem;

  q.display();

  q.enQueue(7);

  q.display();

  q.enQueue(9);

  return 0;

}
