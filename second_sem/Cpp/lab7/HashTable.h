//---------------------------------------------------------------------------

#ifndef HashTableH
#define HashTableH
//---------------------------------------------------------------------------
#endif

#include "Stack.h"
#include <vcl.h>

template <typename T>
class HashTable
{
	public:

		void Add_element(String data) //chaining with separate lists
		{
			int index = Get_hash(data);

			hash_table[index].Push(data);
		}

		int Get_hash(String data)  // hash function
		{
			int result = 0;
			for(int i = 1; i <= data.Length(); ++i)
			{
				result += (int)data[i];
			}

			return result % 10;
		}

		void Show_table(TMemo* Memo1)
		{
			String str;
			Memo1 ->Lines->Add("\n\n\n\n");

			for(int i = 0; i < 10; ++i)
			{
				str = "";
				for(int k = 0; k < hash_table[i].Get_Size(); ++k)
				{
					str += hash_table[i][k];
					str += "; ";
				}

				String resultString = String(i + 1) + ":  ";
				String resultString2 = resultString + str;
				Memo1->Lines->Add(resultString2);
			}
		}

		String Find_element(String data)
		{
			String result = "doesnt exist";

			for (int i = 0; i < 10; ++i)
			{
				for (int k = 0; k < hash_table[i].Get_Size(); ++k)
				{
					if (hash_table[i][k] == data)
					{
						result = "exists on index " + (String)(i + 1);
						return result;
					}
				}
			}

			return result;
		}

		String Delete_elemenet(String data)
		{
			String result = "";

			for (int i = 0; i < 10; ++i)
			{
				for (int k = 0; k < hash_table[i].Get_Size(); ++k)
				{
					if (hash_table[i][k] == data)
					{
						if(k == hash_table[i].Get_Size() - 1)
						{
							hash_table[i].Pop();
							return "deleted";
						}

						else
						{
							return ("No access to this element");
						}
					}
				}
			}

			return "No such element";
        }

	Stack<String> hash_table[10];
};
