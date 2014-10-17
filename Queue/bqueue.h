// The 'deque' class
// Modified form the original LDeque class
// Assignment for the first experiment of Data Structure class
// Matthew Mi
// 20121957

#include <cassert>

// Include the link class
#include "link.h"

// Implementations for linked deque function members
// Linked deque implementation
template <typename E> class BQueue {
private:
	Link<E>* head;       // Pointer to head queue node
	Link<E>* tail;        // Pointer to tail queue node
	int size;                // Number of elements in queue

public:
	BQueue(int sz = defaultSize) // Constructor 
	{
		head = tail = new Link<E>(); size = 0;
	}

	~BQueue() { clear(); delete head; }      // Destructor

	void clear() {           // Clear queue
		while (head->next != NULL) { // Delete each link node
			tail = head;
			delete tail;
		}
		tail = head;
		size = 0;
	}

	void enqueueHead(const E& it) { // Put element on head
		head->next = new Link<E>(it, head->next);
		size++;
	}

	void enqueueTail(const E& it) { // Put element on tail
		tail->next = new Link<E>(it, NULL);
		tail = tail->next;
		size++;
	}

	E dequeueHead() {              // Remove element from head
		assert(size != 0, "Queue is empty");
		E it = head->next->element;  // Store dequeued value
		Link<E>* ltemp = head->next; // Hold dequeued link
		head->next = ltemp->next;       // Advance head
		if (tail == ltemp) tail = head; // Dequeue last element
		delete ltemp;                    // Delete link
		size--;
		return it;                       // Return element value
	}

	E dequeueTail() {              // Remove element from tail
		assert(size != 0, "Queue is empty");
		E it = tail->element;  // Store dequeued value
		Link<E>* ltemp = head;
		while (ltemp->next->next != NULL) ltemp = ltemp->next; // Hold dequeued link
		tail = ltemp;
		ltemp = ltemp->next;
		delete ltemp;                    // Delete link
		size--;
		return it;                       // Return element value
	}

	const E& headValue() const { // Get head element
		assert(size != 0, "Queue is empty");
		return head->next->element;
	}

	const E& tailValue() const { // Get tail element
		assert(size != 0, "Queue is empty");
		return tail->element;
	}

	virtual int length() const { return size; }
};
