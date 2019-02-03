#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <list>
#include <queue>

using namespace std;

template<typename V, typename K, unsigned CAP>
class HashTable
{
private:
	struct Node
	{
		K key;
		V value;
	};

	list<Node> data[CAP];			   // chaining
	int(*hashCode)(const K&);   // A pointer to hashCode function
	int siz;									 // occupied elements in array
	int n_siz;								// total nodes
	V dummy;

public: 
	HashTable(int(*HashCode)(const K&) = 0);            // =0 for a "default constructor"
	double loadFactor() const { return 1.0 * siz / CAP; }
	double node_loadFactor() const { return 1.0 * n_siz / CAP; }
	const V& operator[](const K&) const;    // getter
	V& operator[](const K&);								// setter
	bool containKey(const K&) const;				// getter
	void deleteKey(const K&);								// setter
	queue<K> Keys() const;
	int size() const { return siz;}							
	void clear();
	//~Hashtable();
};

template<typename V, typename K, unsigned CAP>
 HashTable<V, K, CAP>::HashTable(int(*HashCode)(const K &))
{
	this->hashCode = HashCode;
	siz = 0;
	n_siz = 0;
	dummy = V();
}

template<typename V, typename K, unsigned CAP>
V& HashTable<V, K, CAP>::operator[]( const K& keyword)
{
	int index = hashCode(keyword) % CAP;
	if (index < 0) index += CAP;

	// find it
	typename list<Node>::iterator it;
	for (it = data[index].begin(); it != data[index].end(); it++)
	{
		if (it->key == keyword) return it->value;
	}

	// if it cannot be found, add it
		if(data[index].empty()) siz++;

		n_siz++;
		Node n = { keyword, V()};
		data[index].push_back(n);
		return data[index].back().value;
}

template<typename V, typename K, unsigned CAP>
const V& HashTable<V, K, CAP>::operator[](const K& keyword) const
{
	int index = hashCode(keyword) % CAP;
	if (index < 0) index += CAP;
	
	typename list<Node>::const_iterator it;
	for (it = data[index].begin(); it != data[index].end(); it++)
	{
		if (it->key == keyword)	return it->value;
	}

	if (it == data[index].end()) return dummy;
}

template<typename V, typename K, unsigned CAP>
bool HashTable<V, K, CAP>::containKey( const K& keyword) const
{
	int index = hashCode(keyword) % CAP;
	if (index < 0) index += CAP;
	
	typename list<Node>::const_iterator it;			// it is like a read-only pointer.
	for (it = data[index].begin(); it != data[index].end(); it++)
	{
		if (it->key == keyword) return true;
	}

	if (it == data[index].end()) return false;
}

template<typename V, typename K, unsigned CAP>
void HashTable<V, K, CAP>::deleteKey(const K& keyword)
{
	int index = hashCode(keyword) % CAP;
	if (index < 0) index += CAP;

	typename list<Node>::const_iterator it;
	for (it = data[index].begin(); it != data[index].end(); it++)
	{
		if (it->key == keyword)
		{
			it = data[index].erase(it);
			n_siz--;
			break;
		}
	}

	if (data[index].empty()) siz--;
}

template<typename V, typename K, unsigned CAP>
queue<K> HashTable<V, K, CAP>::Keys() const
{
	queue<K> keyword;
	for (int i = 0; i < CAP; i++)
	{
			typename list<Node>::const_iterator it;
			for (it = data[i].begin(); it != data[i].end(); it++)
			{
				keyword.push(it->key);
			}
	}
	return keyword;
}

template <typename V, typename K, unsigned CAP>
void HashTable<V, K, CAP>::clear()
{
	for (int i = 0; i < CAP; i++)
	{
		data[i].clear();
	}
	siz = 0;
	n_siz = 0;
}








#endif