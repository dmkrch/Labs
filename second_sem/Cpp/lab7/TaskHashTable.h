//---------------------------------------------------------------------------

#ifndef TaskHashTableH
#define TaskHashTableH
//---------------------------------------------------------------------------
#endif

#include "HashTable.h"
#include <vcl.h>



template <typename T>
class TaskHashTable : public HashTable<T>
{
public:
	TaskHashTable() : HashTable<T>(){}


	int Get_popular_index()
	{
		  int result_index = 0;
		  int result_counter = 0;

		  for (int i = 0; i < 10; ++i)
		  {
			int temp_counter = 0;

			for(int k = 0; k < hash_table[i].Get_Size(); ++k)
			{
				temp_counter++;
			}

			if (temp_counter > result_counter)
			{
				result_counter = temp_counter;
				result_index = i;
			}
		  }

			return result_index;
	}
};
