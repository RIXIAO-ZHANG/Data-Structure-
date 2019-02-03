// Programmer: Rixiao Zhang 
#ifndef SORTABLEARRAY_H
#define SORTABLEARRAY_H


#include <algorithm> 

template <typename V>
class SortableArray
{
private:
	V* value;
	int CAP;
	V dummy;
	void mergeSort(int, int,int);

public:
	SortableArray(int = 2);								// The default constructor 
	SortableArray(const SortableArray<V>&); // The copy constructor
	~SortableArray() { delete[] value; }		// Destructor 
	SortableArray& operator= (const SortableArray<V>&);// Assignment operator function
	int capacity() const { return CAP; }
	void capacity(int);
	V operator[](int) const;
	V& operator[](int);
	void sort(int,int);
	/*
	The int parameter specifies how many elements to sort, 
	starting from element zero to this "fill-line". 
	That is, sort(10) should sort only elements [0] through [9]. 
	Sorting should IGNORE inUse and assume that all elements below the fill line are in use.
	*/
};


template <typename V>
SortableArray<V>::SortableArray(int capacity)
{
	dummy = V();

	this->CAP = capacity;
	value = new V[CAP];

	for (int i = 0; i < CAP; i++)
	{
		value[i] = V();
	}
}


template <typename V>
SortableArray<V>::SortableArray(const SortableArray<V>& original)
{
	dummy = original.dummy;

	this->CAP = original.CAP;
	value = new V[CAP];

	for (int i = 0; i < CAP; i++)
	{
		value[i] = original.value[i];
	}
}

template <typename V>
SortableArray<V>& SortableArray<V>::operator= (const SortableArray<V>& original)		// void!!!!
{
	if (this != &original)								// To make sure it is not a self copy.
	{
		delete[] value;

		CAP = original.CAP;
		value = new V[CAP];

		for (int i = 0; i < CAP; i++)
		{
			value[i] = original.value[i];
		}

		dummy = original.dummy;
	}

	return *this;													// return a self reference
}


template<typename V>
void SortableArray<V>::capacity(int size)
{

	V* temp = new V[size];

	//int limit = min(size, CAP);

	int limit;
	if (size >= CAP)
	{
		limit = CAP;
	}
	else {
		limit = size;
	}



	for (int i = 0; i < limit; i++)
	{
		temp[i] = value[i];
	}

	for (int i = limit; i < size; i++)
	{
		temp[i] = V();
	}

	delete[] value;

	value = temp;

	this->CAP = size;

}


template<typename V>
V& SortableArray<V>::operator[](int index)
{
	if (index < 0)
	{
		return dummy;
	}
	else if (index >= CAP)
	{
		capacity(2 * index);
	}

	return value[index];

}

template<typename V>
V SortableArray<V>::operator[](int index) const
{
	if (index < 0 || index >= CAP)
	{
		return V();
	}

	return value[index];
}


template<typename V>
void SortableArray<V>::sort(int leftLimit, int rightLimt)	// give me starting index and the size
{

	if (leftLimit < rightLimt)
	{
		int midLimit = floor((rightLimt+leftLimit)/ 2);
		sort(leftLimit, midLimit);			// divide    
		sort(midLimit+1, rightLimt);  //	 divide			
		mergeSort(leftLimit, midLimit, rightLimt);			// conquer 
	}
}



template<typename V>
void SortableArray<V>::mergeSort(int leftLimit, int midLimit, int rightLimit)		// index 
{

	int LeftSize = midLimit -leftLimit + 1;
	int RightSize = rightLimit - midLimit;

	int *LeftArray = new int[LeftSize+1];				// one more space for sentinel card 
	int *RightArray = new int[RightSize+1];			// one more space for sentinel card 

	// copy 
	for (int i = 0; i < LeftSize; i++)
	{
		LeftArray[i] = value[leftLimit+i];
	}

	for (int i = 0; i < RightSize; i++)
	{
		RightArray[i] = value[midLimit + 1 + i];
	}

	LeftArray[LeftSize] = INT_MAX;
	RightArray[RightSize] = INT_MAX;


	int i = 0; 
	int j = 0;
	for (int k = leftLimit; k < (rightLimit+1); k++)
	{
		if (LeftArray[i] <= RightArray[j])				// from lo-hi
		{
			value[k] = LeftArray[i];
			i++;
		}
		else
		{
			value[k] = RightArray[j];
			j++;
		}
	}

	delete[] LeftArray;
	delete[] RightArray;
}



#endif 