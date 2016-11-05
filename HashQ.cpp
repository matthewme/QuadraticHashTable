
#include<iostream>
#include "quadraticHashTable.h"
using namespace std;

int main()
{
	//part 1:
	//quadraticHashTable<int> table(10);

	//table.insert(4371);
	//table.insert(1323);
	//table.insert(6173);
	//table.insert(4199);
	//table.insert(4344);
	//table.insert(9679);
	//table.insert(1989);

	//table.testDisplay();

	//part 2:  Implement a method to find if a given number is in the table

	quadraticHashTable<int> table2(17); //what are 2 reasons 17 was chosen for this test?
	//1) 17 is prime
	//2) evaluate by %17

	table2.insert(4371);
	table2.insert(1323);
	table2.insert(6173);
	table2.insert(4199);
	table2.insert(4344);
	table2.insert(6613);
	table2.insert(1224);

	table2.testDisplay();

	//if (table2.contains(1224))
	//	cout << "Correct!" << endl;
	//else
	//	cout << "Wrong!" << endl;

	//if (table2.contains(1700))
	//	cout << "Wrong!" << endl;
	//else
	//	cout << "Correct!" << endl;

	//////part 3:
	//////-Initialize table size to be a prime number
	//////-When table fills to half size (or over), resize
	//////  to a larger table of prime size to ensure hashing never fails.
	//quadraticHashTable<int> table3(23);

	//for (int i = 0; i<100; i++)
	//	table3.insert(rand());

	//table3.testDisplay();

	//for (int i = 0; i<10000; i++)
	//	table3.insert(rand());

	//table3.testDisplay();

	////part 4: Implement void remove(int x).
	//table2.remove(1224);
	//table2.insert(1241);

	//table2.testDisplay();

	//cout << endl<<endl;
	//table2.remove(4371);
	//table2.remove(1323);
	//table2.remove(6173);
	//table2.remove(4199);
	//table2.remove(4344);
	//table2.remove(6613);
	//table2.remove(1224);

	//table2.testDisplay();




	return 0;
}