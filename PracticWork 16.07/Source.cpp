#include <iostream>

class Stack
{
private:
	enum { EMPTY = -1, FULL = 9 };
	int data[FULL + 1];
	int topIndex;

public:
	Stack()
	{
		topIndex = EMPTY;
	}
	~Stack() = default;

	bool IsFull() const
	{
		return topIndex == FULL;
	}

	void Push(int elem)
	{
		if (!IsFull())
		{
			topIndex++;
			data[topIndex] = elem;
		}
	}

	bool IsEmpty()const
	{
		return topIndex == EMPTY;
	}

	int Pop()
	{
		if (!IsEmpty())
		{
			return data[topIndex--];
		}
		return 0;
	}

	int GetCount() const
	{
		return topIndex + 1;
	}

	void Clear()
	{
		topIndex = EMPTY;
	}

	int Peek() const
	{
		if (!IsEmpty())
		{
			return data[topIndex];
		}
		return 0;
	}
};

int main()
{
	Stack st;
	st.Push(20);
	std::cout << "Count: " << st.GetCount() << std::endl;
	std::cout << "Peek: " << st.Peek() << std::endl;
	st.Push(11);
	st.Push(25);
	st.Push(70);
	st.Push(90);
	std::cout << "Count: " << st.GetCount() << std::endl;
	std::cout << "Pop: " << st.Pop() << std::endl;
	std::cout << "Count: " << st.GetCount() << std::endl;
	while (!st.IsEmpty())
	{
		std::cout << "Element: " << st.Pop() << std::endl;
	}
	std::cout << "Count: " << st.GetCount() << std::endl;

	return 0;
}