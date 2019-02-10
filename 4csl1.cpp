#include<iostream>

using namespace std;

class Node
{
   public:
	//to store data
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
			//set node to be deleted as temp
			Node *temp = new Node;
			temp = head;
			head = head->next;
			//delete temp
			delete temp;
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
			temp = current->next;
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
		//update front and end pointers
		front = l2.tail;
		end = l2.head;
	}

	//removes element from the end
	void dequeue()
	{
		l2.deletionAt(l2.countItems());
		//update front and end pointers
		front = l2.tail;
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

class StackArr
{
   public:
	//variable that stores index value of starting element
	int top;
	int arr[30];

	//initialize top as -1
	StackArr()
	{
		top = -1;
	}

	//pushes new element into stack
	void push(int value)
	{
		//increment top
		top++;
		//add value to array
		arr[top] = value;
	}

	//pops element from stack
	void pop()
	{
		//displays deleted element
		cout<<"Deleted element: "<<arr[top]<<endl;
		//decrement top
		top--;
	}

	//returns the size of the stack
	int size()
	{
		if(top == -1)
			return 0;
		//stores the no. of elements
		int count = 0;
		for(int i=0;arr[i]!=arr[top];i++)
		{
			count++;
		}

		return count;
	}

	//checks if the stack is empty
	bool isEmpty()
	{
		if(top == -1)
		   return true;

		return false;
	}

	//displays the contents of the stack
	void display()
	{
		for(int i=0;arr[i]!=arr[top];i++)
		{
			cout<<arr[i]<<"->";
		}

		cout<<arr[top]<<endl;
	}

};

class QueueArr
{
   public:
	//variables that store indices for first and last element of the array
	int front,end;
	int arr[30];

	//initialize both front and end as -1
	QueueArr()
	{
		front = -1;
		end = -1;
	}

	//inserts element at the end
	void enqueue(int value)
	{
		//increment end
		end++;
		//insert element
		arr[end] = value;
	}

	//deletes element from the front
	void dequeue()
	{
		if(front == end)
		{
			front = -1;
			end = -1;
		}

			//increment front
			front++;

	}

	//returns size of the queue
	int size()
	{
		if(end == -1)
			return 0;

		int count = 0;                        //stores the number of elements
		for(int i=0;arr[i]!=arr[end];i++)
			count++;

		return count;
	}

	//checks if queue is empty
	bool isEmpty()
	{
		if(end == -1)
			return true;

		return false;
	}

	//displays the contents of queue
	void display()
	{
		//has to display contents between front and end
		int i=front+1;
		while(i>front && i<end)
   		{
			cout<<arr[i]<<"->";
			i++;
		}
		cout<<arr[end]<<endl;
	}
};

//driver function
int main()
{
	//stack implementation using linked list
	cout<<"Stack using LL: "<<endl;
	StackLL s1;
	for(int i=1;i<6;i++)
	{
		s1.push(i);
	}
	s1.display();
	s1.pop();
	s1.display();
	s1.pop();
	s1.display();
	cout<<endl<<endl;

	//queue implementation using linked list
	cout<<"Queue using LL: "<<endl;
	QueueLL q1;
	for(int j=1;j<6;j++)
	{
		q1.enqueue(j);
	}
	q1.display();
	q1.dequeue();
	q1.display();
	q1.dequeue();
	q1.display();
	cout<<endl;

	//stack implementation using arrays
	cout<<"Stack using array: "<<endl;
	StackArr s2;
	for(int k=1;k<6;k++)
		s2.push(k);

	s2.display();
	s2.pop();
	s2.display();
	s2.pop();
	s2.display();

	//queue implementation using arrays
	cout<<"Queue using array: "<<endl;
	QueueArr q2;
	for(int l=1;l<6;l++)
		q2.enqueue(l);

	q2.display();
	q2.dequeue();
	q2.display();
	q2.dequeue();
	q2.display();

	//return statement
	return 0;
}