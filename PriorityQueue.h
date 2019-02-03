#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H


template <typename V>
class PriorityQueue
{
private:
	V* values;
	size_t CAP;
	size_t siz;
	void capacity(const size_t&);				// enlarge twice 

public:
	PriorityQueue(size_t=2);
	PriorityQueue(const PriorityQueue<V>&);
	~PriorityQueue() { delete [] values; }
	PriorityQueue<V>& operator= (const PriorityQueue<V>&);
	void push(const V&);
	void pop();
	V top() const { return values[0]; }
	size_t size() { return siz; }
	bool empty() { return siz == 0 ? true : false; }
	void clear() { siz = 0; }
};

template<typename V>
PriorityQueue<V>::PriorityQueue(size_t num)
{
	values = new V[num];
	CAP = num;
	siz = 0;

	for (size_t i = 0; i < num; i++)
	{
		values[i] = V();											
	}
}

template<typename V>
PriorityQueue<V>::PriorityQueue(const PriorityQueue<V>& original)
{
	siz = original.siz;
	CAP = original.CAP;

	values = new V[CAP];

	for (size_t i = 0; i < CAP; i++)
	{
		values[i] = original.values[i];				
	}
}

template<typename V>
PriorityQueue<V>& PriorityQueue<V>::operator=(const PriorityQueue<V>& original)
{
	siz = original.siz;
	CAP = original.CAP;

	values = new V[CAP];

	for (size_t i = 0; i < CAP; i++)
	{
		values[i] = original.values[i];				
	}
}

template<typename V>
void PriorityQueue<V>::push(const V& val)
{
	if (siz == CAP) capacity(CAP);			// siz is not index;
	values[siz] = val;
	size_t P_index = 0;
	V temp = V();

	for (size_t index = siz; index != 0;)
	{
		P_index = (index + 1)/2 - 1;							//  The rule: a parent can only have two children

		if (values[index] < values[P_index]) break;  // no promotions

		// swap 
		temp = values[index];
		values[index] = values[P_index];
		values[P_index] = temp;

		// set index
		index = P_index;
	}

	siz++;
}

template<typename V>
void PriorityQueue<V>::pop()				// setter
{	
	siz--;
	size_t index = 0;
	size_t l_index = 0;
	size_t r_index = 0;

	for(;;)									
	{
		l_index = index * 2 + 1;								// find siz's competitor;
		r_index = index * 2 + 2;								// find siz's competitor;

		if (l_index > siz) break;							// if there is no left child 
		if (r_index > siz)										// if there is no right child 
		{
			if (values[l_index] < values[siz]) break;				// the values[siz] "wins"
			else
			{																								// the left wins
				values[index] = values[l_index];
				index = l_index;
			}
		}
		else if (values[l_index] < values[siz] && values[r_index] < values[siz]) break;	//the values[siz] wins   what important is == not <
		else if (values[l_index] < values[r_index])				// the right wins
		{
			values[index] = values[r_index];
			index = r_index;
		}
		else																						 // the left wins
		{
			values[index] = values[l_index];
			index = l_index;
		}
	}

	values[index] = values[siz];
	
}

template<typename V>
void PriorityQueue<V>::capacity(const size_t& num) 
{
	CAP = num * 2;
	V *temp = new V[num * 2];
	
	for (size_t i = 0; i < num; i++)
	{
		temp[i] = values[i];
	}
	for (size_t j = num; j < CAP; j++)
	{
		temp[j] = V();
	}

	values = temp;
}


#endif