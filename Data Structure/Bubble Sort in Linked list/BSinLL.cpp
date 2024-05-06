#include <iostream>
using namespace std;

class node 
{
public:
    int data;
    node* next;

    node(int val) 
    {
        data = val;
        next = NULL;
    }

    static void bubbleSort(node* start) 
    {
        if (!start || !start->next)
            return; 

        bool swapped; 
        node* ptr1;
        node* lptr = NULL;

        do {
            swapped = false;
            ptr1 = start;

            while (ptr1->next != lptr) 
            {
                if (ptr1->data > ptr1->next->data) {
                    swap(ptr1->data, ptr1->next->data);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1; 
        } while (swapped);
    }

    static void display(node* head) 
    {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() 
{
    node* head = new node(5);
    head->next = new node(3);
    head->next->next = new node(8);
    head->next->next->next = new node(1);
    head->next->next->next->next = new node(6);

    cout << "Original list: ";
    node::display(head);

    node::bubbleSort(head);

    cout << "Sorted list: ";
    node::display(head);

    return 0;
}
