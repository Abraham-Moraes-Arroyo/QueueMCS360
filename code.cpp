/*
Queue is an container, which operate on the first-in, first-out principle (FIFO). 
Queue properties are essentially like those of a line that may form in front of store, where customers wait to enter.
That is, all the elements get inserted at the rear of the queue and removed from the front of the queue.  
*/

/*
Functions working on queues
push(e) - pushes an element e inside the queue, subsequent elements go to the back of the queue
front_node() - shows (does not remove) element at the front of queue
rear_node()  - shows (does not remove) element at the back of queue
size()  - returns the number of elements in the queue
empty() - returns true if queue is empty, otherwise false
pop()   - removes the first element in the queue

*/

#include<iostream>

using namespace std;


struct QueueNode {
  int n;        // an integer
  QueueNode *next;   //pointer to the next QueueNode. i.e. every QueueNode carries the address of the next QueueNode
};

class Queue {
    private:
    // this means that, at all times, we have access to the front and rear nodes addresses (and values via ->)
    QueueNode *front;    // this private member variable is just a pointer to the first QueueNode
    QueueNode *rear;     // this private member variable is just a pointer to the last QueueNode
 
    public:
    Queue(){    //constructor
      // recall, the NULL is a null pointer constant, which may be converted to any pointer type
      // set the front and rear pointer to NULL value to avoid picking up any random value in memory
      front = NULL;  
      rear = NULL; 
    }
    
    // By default, we insert a new value (QueueNode) at the rear of the queue, i.e. any new QueueNode always becomes the rear QueueNode,
    // so any new QueueNode needs to be made to point to NULL
    // When we have a single QueueNode, that QueueNode will be the front and rear QueueNode simultaneously
    // In general, front pointer points to the first QueueNode and rear pointer points to the last QueueNode

    // The way to understand the queue is to see the queue from the perspective of a person in the very front of the queue.
    // From that person's perspective, the "next" person is the second person in the queue. That is, the notion of who is next
    // goes from the front of the queue to the end of the queue. So, when we add the new node to the queue, we take the
    // the currently last node and make it point to the node that is just being inserted (ie. new_node)
    // and then we set the new node the new rear node. See our textbook, page 367 for an illustration.  

    void push(int value) {
        QueueNode *new_node = new QueueNode();    // create a new QueueNode;
        new_node->n = value;            // set its value
        new_node->next = NULL;          // make the QueueNode pointer point to the next QueueNode.

        // first we check if we have only a single QueueNode in our queue
        // rear QueueNode points to NULL every time, now if front also points to NULL
        // then front QueueNode is the same as rear QueueNode, namely the newly created new_QueueNode QueueNode
        if (front == NULL){
           front = rear = new_node;  // front and rear pointers have the same address
        }
        // otherwise, we insert the new QueueNode to the end of the queue via the pointers
        // recall: every QueueNode carries the address of the next QueueNode, so we set the current 
        // rear's next value be the address of the newly created QueueNode; after that we make the newly created QueueNode our new rear
        else {
          rear->next = new_node;   
          rear = new_node;
        } 
    }
    
    void show() {
         QueueNode *tmp = front; // this tmp pointer points to address of front node
         while (tmp != NULL){
           // here we show current QueueNode's data, its address (for illustration purpose), and the address of the next QueueNode
           // recall: every QueueNode carries the address of the next QueueNode
           cout << "[ " << tmp->n<< " | " << tmp << " | " << tmp->next << " ]";
           tmp = tmp->next;      
         }
         cout << endl;
    }
    
    int front_node() {

        int r;             // value to be returned
        QueueNode *tmp = front;  // this new node pointer is a temporary node; we can also call it *tmp, for example
        // return some special integer (like -1) to avoid segmentation fault, if the queue is empty;
        if (front == NULL)  
           return -1;
        r = tmp->n; // access the value
        return r;
    } 

    int rear_node() {

        int r;             // value to be returned
        QueueNode *tmp = rear;  // this new node pointer is a temporary node; we can also call it *tmp, for example
        // return some special integer (like -1) to avoid segmentation fault, if the queue is empty;
        if (rear == NULL)  
           return -1;
        r = tmp->n; // access the value
        return r;
    }

    int size() {
        QueueNode *curr;
    
        // We start at the front and loop until we reach the rear node, incrementing the counter as we go;
        curr = front;
        if (front == NULL)
           return 0; // return value 0 if the stack is empty to avoid segmentation fault
        int cnt = 1; // linked 
        while(curr->next != NULL) {
          curr = curr->next;
          cnt++;
        }
        return cnt;
    } 

   bool empty(){
        // we have access to front and rear nodes at all times; so, this is an easy check
        if ((front == NULL) and (rear == NULL))  
           return true;
        else
           return false;
    }

    // This function returns the value from the back of the queue, and deletes the node
    int pop() {            
        int r;             // value to be returned
        QueueNode *tmp = front;  // here we create a tmporary node, set it = to front
        if (front == NULL) // if top already points to NULL, return some special integer (like -1) to avoid segmentation fault; 
           return -1;
        r = tmp->n; // access value to be returned
        front = front->next; // shift the pointer so that second node becomes the first
        delete tmp; // delete the first node
        return r;
    }
};


int main() {
    Queue Q;  //creating an empty queue

    Q.push(1);
    Q.push(2);
    Q.push(4);
    Q.push(8);
    Q.show();

    cout << Q.front_node() << endl;
    cout << Q.rear_node() << endl;
    cout << Q.size() << endl;
    cout << Q.empty() << endl;
    cout << Q.pop() << endl;
    Q.show();
    return 0;
}
