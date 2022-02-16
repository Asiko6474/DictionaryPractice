#pragma once
#include <iostream>
template<typename TKey, typename TValue>
class Dictionary
{

public:
	Dictionary<TKey, TValue>();

	Dictionary<TKey, TValue>(const Dictionary<TKey, TValue>& other);

	~Dictionary<TKey, TValue>();

	//deletes all items in dictionary
	void clear();

	//checks to see if an item that has the given key is the dictionary
	const bool containsKey(const TKey object);

	//checks to see if an item that has the given value is in the dictionary 
	const bool containsValue(const TValue object);

	const bool tryGetValue(const TKey key, const TValue& value);

	//Creates a new item with the given key and value and adds it to the dictionary
	void addItem(const TKey& key, const TValue& value);

	//removes the item that has the given key
	bool remove(const TKey key);

	//removes the item that has the given key and gives back the value of the item that was removed
	bool remove(const TKey key, TValue& value);

	//gets the number of items in teh dictionary
	const int getCount();

	const int operator = (const Dictionary<TKey, TValue> other);

private:
	struct Item
	{
		TKey itemKey;
		TValue itemValue;
	};

	Item* m_items = nullptr;
	int m_count = 0;

};

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::clear()
{
	delete[] m_items;
}

template<typename TKey, typename TValue>
inline const bool Dictionary<TKey, TValue>::containsKey(const TKey object)
{
	for (int i = 0; i < getCount(); i++)
	{
		if (m_items[i].itemKey == object)
			return true;
	}
	return false;
}

template<typename TKey, typename TValue>
inline const bool Dictionary<TKey, TValue>::containsValue(const TValue object)
{
	for (int i = 0; i < getCount(); i++)
	{
		//check if the value of item is equal to object
		if (m_items[i].itemValue == object)
			return true;//return true
	}
	return false;
}

template<typename TKey, typename TValue>
inline const bool Dictionary<TKey, TValue>::tryGetValue(const TKey key, const TValue& value)
{
	for (int i = 0; i < getCount(); i++)
	{
		//compares the key and the values
		if (m_items[i].itemKey == key && m_items[i].itemValue == value)
			return true; // returns true
	}
	return false;
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::addItem(const TKey& key, const TValue& value)
{
	//Make new item array that is 1 more
	Item* newArrayItem = new Item[m_count + 1];
	//for loop to copy the values in the old to the new

	for (int i = 0; i < getCount(); i++)
	{
		//set the new array at teh index of i to the m_items at the index of i
		newArrayItem[i] = m_items[i];

	}
	//delete old array
	delete[] m_items;
	//add the value to the new array
	newArrayItem[m_count].itemValue = value;
	newArrayItem[m_count].itemKey = key;

	//increase count
	m_count++;
	//then make m_ites equal to the new array
	m_items = newArrayItem;

	//makes the items print
	std::cout << " " << m_items->itemValue;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key)
{
	//Make new item array that is 1 less
	Item* newArrayItem = new Item[m_count - 1];
	//check if the key exists
	if (containsKey(key))
	{
		//iterate through the array of items...
		for (int i = 0; i < getCount(); i++)
		{
			//iterate with i
			newArrayItem[i] = m_items[i];
		}
		//find its index
		newArrayItem[m_count].itemKey = key;
		//delete key
		delete[] m_items;
		//copy all of the values form the new array to the old array
		m_items = newArrayItem;
		//count - 1
		m_count--;
	}
	return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key, TValue& value)
{
	//Make a temp item
	Item* tempItems = new Item[m_count - 1];
	//chekc if it was a key and value
	if (containsKey(key) && containsValue(value))
	{
		//iterate through the array of m_items
		for (int i = 0; i < getCount(); i++)
		{
			tempItems[i] = m_items[i];
		}
		//set the temp items key and value
		tempItems[m_count].itemKey = key;
		tempItems[m_count].itemValue = value;
		//delete[] m_items
		delete[] m_items;
		//m_items is temp items
		m_items = tempItems;
		m_count--;//decrease m_count

	}
	return false;
}

template<typename TKey, typename TValue>
inline const int Dictionary<TKey, TValue>::getCount()
{
	return m_count;
}

template<typename TKey, typename TValue>
inline const int Dictionary<TKey, TValue>::operator=(const Dictionary<TKey, TValue> other)
{
	*m_items = *other.m_items;
}

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::Dictionary()
{
	m_count = 0;
	m_items = nullptr;
}

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::Dictionary(const Dictionary<TKey, TValue>& other)
{
	m_count = other.m_count;
	m_items = other.m_items;
}

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::~Dictionary()
{
	m_items = nullptr;
	m_count = 0;
}
