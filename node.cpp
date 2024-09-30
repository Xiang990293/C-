using namespace std;

template <typename T>
struct node
{
	T value;
	node<T> *next;

	node(T value1)
	{
		value = value1;
		next = nullptr;
	}

	node(){
		value = T();
		next = nullptr;
	}
};