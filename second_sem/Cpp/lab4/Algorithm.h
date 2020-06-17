//---------------------------------------------------------------------------

#ifndef AlgorithmH
#define AlgorithmH

#include <vcl.h>
#include <vector>
#include <string>
//---------------------------------------------------------------------------
#endif

class Algorithm
{
	public:

        void Push(double number)
        {
			stack.push_back(number);
		}

		double Pop()
        {
            double returnValue = stack[stack.size() - 1];
            stack.pop_back();

            return returnValue;
		}

		int Get_priority(char a)    			  // return priority of operation
        {
            if (a == '+' || a == '-')
                return 2;
            else if (a == '*' || a == '/')
                return 3;
            else return -1;
		}

		double Execute_calculations(String pattern) // returns int equalent of postfix format
		{
			for (int i = 1; i <= pattern.Length(); ++i)
            {
                if (pattern[i] >= 'a' && pattern[i] < 'z')
                {
                    switch (pattern[i])
					{
                    case 'a':
                        Push(9.1);
                        break;

                    case 'b':
                        Push(0.6);
                        break;

                    case 'c':
                        Push(2.4);
                        break;

                    case 'd':
                        Push(3.7);
                        break;

                    case 'e':
                        Push(8.5);
                        break;
                    }
                }

                else if (pattern[i] == '+')
                {
                    Push(Pop() + Pop());
                }

                else if (pattern[i] == '-')
                {
                    double first = Pop();
                    Push(Pop() - first);
                }

                else if (pattern[i] == '*')
                {
                    Push(Pop() * Pop());
                }

                else if (pattern[i] == '/')
                {
					double first = Pop();
                    Push(Pop() / first);
				}
			}

			double return_value =  stack[stack.size() - 1];
			stack.clear();

			return return_value;
		}

		String Get_OPZ(String pattern)   // returns postfix format of expression in infix format
		{
			String result_string;

			for (int i = 1; i <= pattern.Length(); ++i)
			{
				if (pattern[i] >= 'a' && pattern[i] <= 'z')
				{
                    result_string += pattern[i];
                }

                else
                {
                    if (char_stack.size() == 0)
                    {
                        char_stack.push_back(pattern[i]);
                    }

                    else
                    {
                        switch (pattern[i])
                        {
                            case '(':
                                char_stack.push_back(pattern[i]);
                                break;

                            case ')':
                                for (int k = char_stack.size() - 1;; --k)
                                {
                                    if (char_stack[k] == '(')
                                    {
                                        char_stack.erase(char_stack.begin() + k);
                                        break;
                                    }

                                    else
                                    {
                                        result_string += char_stack[k];
                                        char_stack.erase(char_stack.begin() + k);
                                    }
                                }
                                break;

                            case '+':
                            case '-':
                            case '*':
                            case '/':
                                for (int k = char_stack.size() - 1; k >= 0; --k)
                                {
                                    if (char_stack[k] == '(')
                                    {
                                        break;
                                    }

                                    if (Get_priority(pattern[i]) <= Get_priority(char_stack[k]))
                                    {
                                        result_string += char_stack[k];
                                        char_stack.erase(char_stack.begin() + k);
                                    }
                                }

                                char_stack.push_back(pattern[i]);

                                break;
                        }
                    }
                }
            }

            if (char_stack.size() != 0)
            {
                for (int k = char_stack.size() - 1;k >= 0; --k)
                {
                    result_string += char_stack[k];
                }
            }

            char_stack.clear();

			return result_string;
		}

	private:
		std::vector <double> stack;
		std::vector <char> char_stack;
};
