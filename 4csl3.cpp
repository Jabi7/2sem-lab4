e a stack using queue(s)
#include<iostream>

using namespace std;

//creates circles of data that are to be linked
class Node
{
   public:
	//stores data
	int data;

	//pointer to move to next node
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
	Node *head;
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

//implements linked list to create a queue
class QueueLL
{
   public:
	Node *front;                                      
	Node *end;
	LinkedList l2;

	//initializes front and end to NULL
	QueueLL()
	{
		front = NULL;
		end = NULL;
	}

	//adds element at the start
	void enqueue(int value)
	{
		l2.insertAt(1,value);
		Node *current = l2.head;
		while(current->next!=NULL)
		{
			current = current->next;
		}
		//update front and end pointers
		front = current;
		end = l2.head;
	}

	//removes element from the end
	void dequeue()
	{
		l2.deletionAt(l2.countItems());
		Node *current = l2.head;
		while(current->next!=NULL)
		{
			current = current->next;
		}
		//update front and end pointers
		front = current;
		end = l2.head;
	}


	//returns size of the queue
	int size()
	{
		return l2.countItems();
	}

	//checks if the queue is empty
	bool isEmpty()
	{
		if(front == NULL)
		    return true;

		return false; 
	}

	//displays the data in front and end pointers
	void frontendDisplay()
	{
		//front data
		cout<<"Front pointer data: "<<front->data<<endl;

		//end data
		cout<<"End pointer data: "<<end->data<<endl;
	}

	//displays the contents of the queue
	void display()
	{
		l2.display();
	}

};

class Stack
{
   public:
   	//creating queue
   	QueueLL q1;
   	
   	//pushes element into stack
   	void push(int value)
   	{
   		q1.enqueue(value);
   	}
   	
   	//pops element from the stack 
   	void pop()
   	{
		for(int i=1;i<q1.size();i++)
		{
			q1.enqueue(q1.front->data);
			q1.dequeue();
		}
		
		q1.dequeue();
		return;
   	}
   	
   	//returns the size of the stack
   	int size()
   	{
   		return q1.size();
   	}
   	
   	//displays the contents of the stack
   	void display()
   	{
   		q1.display();
   		cout<<endl;
   	}
   	
   	//checks if the stack is empty
   	bool isEmpty()
   	{
   		return q1.isEmpty();
	}
   		
};

//driver function
int main()
{
	Stack s1;
	for(int i=1;i<6;i++)
	{
		s1.push(i);
	}
	s1.display();
	s1.pop();
	s1.display();
	s1.pop();
	s1.display();
	
	//return statement
	return 0;
}