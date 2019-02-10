#include<iostream>

using namespace std;

class Node
{
public:
    //stores data
    int data;

    
    //pointer to movve to next node
    Node* next;

    
    //initializes next pointer as NULL
    Node()
    {
        next = NULL;
    }
};

class LinkedList
{
public:
    //pointer to store start node of the linked list
    Node* head;
    //pointer to point to the last node of the linked list
    Node *tail;

    
    //initializes head as NULL
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    
    void insert(int value)
    {
        //create new node temp
        Node *temp = new Node;
        //set value as data of the node
        temp->data = value;

        
        //shows first element is being inserted
        if(head==NULL)
        {
            //update head;
            head = temp;
        }

        
        else
        {
            //link last element to new node created
            tail->next = temp;
        }

        
        //update tail
        tail = temp;
        cout<<endl;
    }

    
    //Deletion
    void deletion()       //deletes the last element
    {
        //store the tail in temp
        Node *temp = tail;
        //node before tail has to point to NULL
        //tail cannot move back so only way is to use head
        Node *current = head;
        while(current->next != tail)    //objective is to stop current upto node just before tail
        {
            current = current->next;
        }

        
        current->next = NULL;   //this will be the last node now so that the next node can be deleted

        
        //update tail
        tail = current;         //tail now points to the last node and the next node is inaccessible

        
        //delete temp
        delete temp;            //the next node gets deleted from the heap
        cout<<endl;
    }

    
    //inserts node at a specific place and not in the last necessarily (this function works for all positions except head but we have to make required modifications which is present in the IF statement btw)
    void insertAt(int pos,int value)
    {
        //To add node at the position of the header
        if(pos == 1)
        {
            //create a new node
            Node *temp = new Node;
            //assign the entered value as data to the new node
            temp->data = value;
            //link the new node to head
            temp->next = head;
            //update head
            head = temp;
        }

        
        else
        {
            //Reach the place before the position
            Node *current = head;
            int i = 1;
            while(i<pos-1)
            {
                i++;
                current = current->next;
            }                                            //now current points to the node just before the position

            
            //counter variable to count no. of entries
            int count = 0;
            //declare present pointer to initially point to head
            Node *present = head;
            //increment count upto last element and simultaneously increment present pointer
            while(present!=NULL)
            {
                count++;
                present = present->next;
            }

            
            if(pos>count)
            {
                cout<<"The linked list doesn't have that many elements\n";
            }
            
            else
            {
                //Create the node
                Node *temp = new Node;
                temp->data = value;                //value inserted as data to the new node

                
                //Moving pointers like magic
                temp->next = current->next;     //link established between new node and the next node
                current->next = temp;           //current should be linked to the new node (since current points to the node just before the position)
            }
        }
        cout<<endl;
    }

    
    //Deletes element of linked list from a specific position
    void deletionAt(int pos)
    {
        if(pos == 1)
        {
            if(head != NULL)
			{
                //set node to be deleted as temp
                Node *temp = head;
                head = head->next;
                
                //delete temp
                delete temp;
            }
        }

        
        else
        {
            //reach the position just before the node to be deleted
            Node *current = head;
            int i = 1;
            while(i<pos-1)
            {
                i++;
                current = current->next;
            }
            //Create the node temp and set it as the node to be deleted
            Node *temp = new Node;
            temp = current->next; // fault Seg Case for 0 lements
            //link previous node to the next node
            current->next = temp->next;
            //delete temp
            delete temp;
        }
        
        cout<<endl;
    }

    
    //Display
    void display()
    {
        Node *current = head;
        while(current != NULL)    //prints till current reaches last node i.e., till current becomes NULL
        {
            cout<<current->data<<"->";
            current = current->next;
        }
        cout<<"NULL";
    }

    
    //Counts number of items in the linked list
    int countItems()
    {
        //set a counter variable
        int count = 0;
        //move pointer from 1st element till the last and increment it everytime it moves
        Node *current = head;
        while(current !=NULL)
        {
            count++;
            current = current->next;
        }

        
        //return the counter
        return count;
    }
};

//stack using linked list
class StackLL
{
public:
    Node *top;
    LinkedList l1;
    StackLL()
    {
        top = NULL;      //initializes top pointer as NULL
    }

    
    //pushes on top
    void push(int value)
    {
        l1.insertAt(1,value);
        //update top
        top = l1.head;
    }

    
    //pops from top
    void pop()
    {
        l1.deletionAt(1);
        //update top
        top = l1.head;
    }

    
    //checks if the stack is empty
    bool isEmpty()
    {
        if(top == NULL)
            return true;

        
        return false;
    }

    
    //returns size of the stack
    int size()
    {
        return l1.countItems();
    }

    
    //displays value stored in top pointer
    void topDisplay()
    {
        cout<<"Value in top pointer: "<<top->data<<endl;
    }

    
    //displays the contents of the stack
    void display()
    {
        l1.display();
    }
};

class Queue
{
public:
    //creating 2 stacks
    StackLL s1,s2;

    
    //adds elements to the queue
    void enqueue(int value)
    {
        s1.push(value);
    }

    
    //deletes elements from the queue
    void dequeue()
    {
        if(s1.size()==0) 
			return; //Newline
			
        if(s1.size()==1)
        {
            s1.pop();
            return; //Newline
        }
        
        else
		{
            //pushes data from main stack to another stack
            s2.push(s1.top->data);
            //pops element from main stack
            s1.pop();
            cout << "S1 :"; s1.display(); cout << endl; //Newline
            cout << "S2 :"; s2.display(); cout << endl; //Newline
            dequeue();

            
            s1.push(s2.top->data);   //pushes elements back into the main stack 
            s2.pop();     //Newline           //and pops from the alternate stack
        }
    }

    
    //displays the contents of the queue
    void display()
    {
        s1.display();
        cout<<endl;
    }

    
    //returns the size of the queue
    int size()
    {
        return s1.size();
    }

};

//driver function
int main()
{
    Queue q1;
    for(int i=1;i<6;i++)
    {
        q1.enqueue(i);
    }
    //dequeueing twice
    q1.display();
    q1.dequeue();
    q1.display();
	q1.dequeue();
	q1.display();
    
    //return statement
    return 0;
}