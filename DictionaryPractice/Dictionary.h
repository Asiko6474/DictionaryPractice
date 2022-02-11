#pragma once




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

}

template<typename TKey, typename TValue>
inline const bool Dictionary<TKey, TValue>::containsKey(const TKey object)
{
	return false;
}

template<typename TKey, typename TValue>
inline const bool Dictionary<TKey, TValue>::containsValue(const TValue object)
{
	return false;
}

template<typename TKey, typename TValue>
inline const bool Dictionary<TKey, TValue>::tryGetValue(const TKey key, const TValue& value)
{
	return false;
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::addItem(const TKey& key, const TValue& value)
{

}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key)
{
	return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key, TValue& value)
{
	return false;
}

template<typename TKey, typename TValue>
inline const int Dictionary<TKey, TValue>::getCount()
{
	return 0;
}
