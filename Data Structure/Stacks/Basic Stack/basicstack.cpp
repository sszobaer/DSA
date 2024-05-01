#include <iostream>
using namespace std;

int stack[100], n=100, top=-1;

bool push(int val) {
   if(top>=n-1)
   cout<<"Stack is full"<<endl;

   else {
      top++;
      stack[top]=val;


   }
}
bool pop() {
   if(top<=-1)
   cout<<"Stack is empty"<<endl;
   else {
      cout<<"The popped element is "<< stack[top] <<endl;
      top--;
   }
}
void display() {
   if(top>=0) {
      cout<<"Stack elements are:";
      for(int i=top; i>=0; i--)
      cout<<stack[i]<<" "<<endl;
   } else
   cout<<"Stack is empty"<<endl;
}
int main() {
   int ch, val;
   cout<<"1) Push in stack"<<endl;
   cout<<"2) Pop from stack"<<endl;
   cout<<"3) Display stack"<<endl;

   do {
      cout<<"Enter your choice: "<<endl;
      cin>>ch;
      switch(ch) {
         case 1: {
            cout<<"Enter value to be pushed:"<<endl;
            cin>>val;
            push(val);
            break;
         }
         case 2: {
            pop();
            break;
         }
         case 3: {
            display();
            break;
         }

         default: {
            cout<<"The choice is invalid"<<endl;
         }
      }
   }while(ch!=4);
   return 0;
}
