//Matthew Martinez
//CSCI 3333
//Quadratric Probing
#include <iostream>
#include <vector>
#pragma once

using namespace std;

template<class THING>
class quadraticHashTable
{
private:
	int table_size;//Table Size
	int current_size;
	enum EntryType { FILLED, EMPTY, DELETED };

	class HashEntry
	{
	public:
		THING element;
		int info;
	};

	HashEntry *table;

	int findEmptyBucket(int current)
	{
		int index = 1;
		int next = 0;

		while(table[next].info == FILLED)
		{
			next = (current + (index * index)) % table_size;

			index++;
		}
		return next;
	}

	int findNewTableSize(int newSize)
	{
		if (isPrime(newSize))
			return newSize;
		else
			return nextPrime(newSize);
	}

	//Find the next prime number
	int nextPrime(int n)
	{
		if (n <= 0)
			n = 3;
		if (n % 2 == 0)
			n++;
		for (; !isPrime(n); n += 2);
		return n;
	}

	//Check for primality
	bool isPrime(int n)
	{
		if (n == 2 || n == 3)
			return true;
		if (n == 1 || n % 2 == 0)
			return false;
		for (int i = 3; i <= sqrt(n); i += 2)
			if (n % i == 0)
				return false;

		return true;
	}

	void rehash()
	{
		//Calculate new table size
		int newTableSize = findNewTableSize(table_size * 2);

		//Creat New Table
		quadraticHashTable<THING> newTable(newTableSize);

		for (int i = 0; i < table_size; ++i)
		{
			newTable.insert(table[i].element);
		}

		table_size = newTableSize;
		delete[]table;
		table = newTable.table;
	}

	//Pass value and size of table. Return bucket number
	int hashFunction(int value, int size)
	{
		return value % size;
	}

public:

	//Constructor
	quadraticHashTable(int hash_size)
	{
		table_size = hash_size;//Set Table Size
		table = new HashEntry[table_size];//Array of node HashEntry
		current_size = 0;//Current elements in the array	
		
		//Set all elements to empty
		for (int i = 0; i < table_size; ++i)
		{
			table[i].info = EMPTY;
			table[i].element = NULL;
		}
	}

	void insert(THING item)
	{
		current_size++;

		int hash_key = hashFunction(item, table_size);//Find bucket

		if (table[hash_key].info == EMPTY || table[hash_key].info == DELETED)
		{
			table[hash_key].element = item;
			table[hash_key].info = FILLED;
		}
		else if (table[hash_key].info == FILLED)
		{
			int newHashKey = findEmptyBucket(hash_key);
			table[newHashKey].element = item;
			table[newHashKey].info = FILLED;
		}

		//Check if table is half full
		if (current_size >= (table_size / 2))
			rehash();
	}

	bool contains(THING item)
	{
		int current = hashFunction(item, table_size);
		int next = 0;

		//Check first place it should be at
		if (table[current].element == item)
			return true;
		else
		{
			int i = 1;

			//Check until an empty bucket is found. If bucket empty, exit.
			while(table[next].info != EMPTY)
			{
				next = (current + (i * i)) % table_size;

				if (table[next].element == item)
					return true;

				++i;
			}
		}
		return false;
	}

	void remove(THING x)
	{
		int current = hashFunction(x, table_size);
		int next = 0;

		if (table[current].element == x)
		{
			table[current].info = DELETED;
			table[current].element = NULL;
			cout << x << " removed" << endl;
			current_size--;
		}
		else
		{
			//Check no more then half the table
			for (int i = 1; i < table_size / 2; ++i)
			{
				next = (current + (i * i)) % table_size;

				if (table[next].element == x)
				{
					table[next].info = DELETED;
					table[next].element = NULL;
					cout << x << " removed" << endl;
					current_size--;
				}
			}
		}
	}

	void testDisplay()
	{
		for (int i = 0; i < table_size; ++i)
			cout << table[i].element << endl;

		cout << endl << "Table Size: " << table_size << endl;
		cout << "# of elements: " << current_size << endl;
	}

};