#include <iostream>
#include <cstdlib>
using namespace std;
 
#define SIZE 3


class Human {
	public: string name;
	public: int age;
	
	public: Human(string _n, int _a) {
		name = _n;
		age = _a;
	}
	
	public: Human() {
	}

};
 

template <class X>
class queue
{
    X *arr;         //array
    int capacity;   //max size
    int front;      //first element
    int rear;       //last element
    int count;      //size
 
public:
    queue(int size = SIZE);    
 
    void dequeue();
    void enqueue(X x);
    int size();
    bool isEmpty();
    bool isFull();
    public: PrintQueue() {
    	int index = 0;
    	for(int i = 0;i<count;i++) {
    		index = front + i;
    		if (index > count-1) {
    			index = index - count;
			}
    		cout << index << " " << arr[index].name << endl;
		}
	}
};
 

template <class X> //template contructor
queue<X>::queue(int size)
{
    arr = new X[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}
 
template <class X>//template remove element
void queue<X>::dequeue()
{
    cout << "Remove " << arr[front].name << endl;
 
    front = (front + 1) % capacity;
    count--;
}
 

template <class X>//template add elemnt
void queue<X>::enqueue(X item)
{
	if (count < capacity) {
    	rear = (rear + 1) % capacity;
    	arr[rear] = item;
    	count++;
	    cout << "Add " << item.name <<  " count is " << count << " front " << front << " rear " << rear << " capacity " << capacity << endl;
	} else {
		cout << "Queue is full" << endl;
	}
}
 
template <class X>//template get size
int queue<X>::size() {
    return count;
}
 
template <class X>//template is empty
bool queue<X>::isEmpty() {
    return (size() == 0);
}
 
template <class X>//template is full
bool queue<X>::isFull() {
    return (size() == capacity);
}



 
int main()
{

 	queue<Human> HumanQueue(3);
 	HumanQueue.enqueue(Human("Ivans",20));
 	HumanQueue.enqueue(Human("Ivars",33));
 	HumanQueue.enqueue(Human("Asta",44));
 	HumanQueue.dequeue();
 	HumanQueue.enqueue(Human("Karolis",55));
 	HumanQueue.enqueue(Human("Egita",66));
 	HumanQueue.PrintQueue();
    return 0;
}
