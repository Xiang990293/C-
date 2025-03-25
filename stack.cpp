#include "node.cpp"
using namespace std;

template <typename T>
struct stack
{
	node<T>* top;
	int length;

	stack()
	{
		top = new node<T>();
		length = 0;
	}

	void push(node<T>* input)
	{
		input->next = top->next;
		top->next = input;
		length++;
	}

	void push(T input)
	{
		push(new node<T>(input));
	}

	node<T>* pop()
	{
		node<T>* return_node;
		if (top->next != nullptr)
			return_node = top->next;
		else
			return new node<T>(-1);
		if (length > 1)
			top->next = top->next->next;
		else
			top->next = nullptr;
		length--;
		return return_node;
	}

	void print()
	{
		node<T>* current = top;
		if (length == 0)
		{
			cout << "stack is empty" << endl;
			return;
		}
		while (current->next != nullptr)
		{
			current = current->next;
			cout << current->value << " ";
		}
		cout << endl;
	}
};