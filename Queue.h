#ifndef QUEUE_H
#define QUEUE_H

template <typename V>
class Queue
{

private:
	struct Node
	{
		V values;
		Node* next;
	};
	Node* firstNode;
	Node* lastNode;
	V dummy;
	int siz;


public:
	Queue();
	Queue(const Queue<V>&);
	Queue<V>& operator=(const Queue<V>&);
  void push( const V&);
	void pop();
	V& front();
	V& back();
	int size() const;
	bool empty() const;
	void clear();
	~Queue();

};

template <typename V>
Queue<V>::Queue()
{
	siz = 0;
	firstNode = nullptr;
	lastNode = nullptr;
	dummy = V();
}


template <typename V>
Queue<V>::Queue(const Queue<V>& original)
{
	this->siz = original.siz;
	lastNode = nullptr;
	firstNode = nullptr;
	dummy = V();


	for (Node* temp = original.firstNode; temp; temp = temp->next)
	{
		Node* p = new Node;
		p->values = temp->values;
		p->next = nullptr;
		if (lastNode) lastNode->next = p;
		else firstNode = p;

		lastNode = p;
	}


}

template <typename V>
Queue<V>& Queue<V>::operator=( const Queue<V>& original )
{
	if (this!=&original)			// self copy check
	{
		//clear first.
		while (firstNode)
		{
			Node* temp = firstNode;
			firstNode = firstNode->next;
			delete temp;
			siz--;
		}

		// copy theen.
		this->firstNode = original.firstNode;
		this->siz = original.siz;
		for (Node* travel = original.firstNode; travel; travel = travel->next)
		{
			Node* p = new Node;
			p->values = travel->values;
			p->next = nullptr;
			if (lastNode) lastNode->next = p;
			else firstNode = p;
			lastNode = p;
		}

	}
	return *this;

}

template <typename V>
void Queue<V>::push( const V& value )
{
	Node* temp = new Node;
	temp->values = value;
	temp->next = nullptr;
	if(lastNode) lastNode->next = temp;
	else firstNode = temp;

	lastNode = temp;
	siz++;
}

template <typename V>
void Queue<V>::pop()
{
	if (firstNode)
	{
		Node* temp = firstNode;
		firstNode = firstNode->next;
		delete temp;
		siz--;
		if (firstNode == nullptr) 
		{
			lastNode = nullptr;
		}
	}
}

template <typename V>
V& Queue<V>::front()
{
	if(firstNode) return firstNode->values;
	else return dummy; // fristNode = nullptr;
}

template <typename V>
V& Queue<V>::back()
{
	if(lastNode) return lastNode->values;
	else return dummy;
}

template<typename V>
int Queue<V>::size() const
{
	return siz;
}

template <typename V>
bool Queue<V>::empty() const
{
	return siz == 0? true : false;
}

template <typename V>
void Queue<V>::clear()
{
	while (firstNode)
	{
		Node* temp = firstNode;
		firstNode = firstNode->next;
		delete temp;
		siz--;
	}
	firstNode = nullptr;
	lastNode = nullptr;
}

template <typename V>
Queue<V>::~Queue()
{
	while (firstNode)
	{
		Node* temp = firstNode;
		firstNode = firstNode->next;
		delete temp;
	}
}

#endif