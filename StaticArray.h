// Programmer: Rixiao Zhang


#ifndef STATICARRAY_H
#define STATICARRAY_H


template< typename V, int CAP >
class StaticArray
{
private:
	V values[CAP];
	V dummy;

public:

	StaticArray();
	int capacity() const { return CAP; }
	V& operator[](int index);
	V operator[](int index) const;

};


template<typename V, int CAP>
StaticArray<V, CAP>::StaticArray()
{
	dummy = V();			// initialize dummy to the default value.

	for ( int i = 0; i < CAP; i++)
	{
		values[i] = V();
	}

}



template <typename V, int CAP>
V& StaticArray<V, CAP>::operator[](int index)
{
	if (index < 0 || index >= 100)
	{
		return dummy;
	}

	return values[index];
}


template <typename V, int CAP>
V StaticArray<V, CAP>::operator[](int index) const
{
	if (index < 0 || index >= 100)
	{
		return V();
	}

	return values[index];
}


#endif
