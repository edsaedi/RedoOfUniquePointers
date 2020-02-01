#pragma once
template<class T>
class UniquePointer
{
private:
	T* pointer;
public:
	UniquePointer() = default;
	~UniquePointer()
	{
		if (pointer != nullptr)
		{
			delete pointer;
			pointer = nullptr;
		}
	}
	UniquePointer(T item)
	{
		pointer = new T{ item };
	}
	UniquePointer(const UniquePointer& other) = delete;
	UniquePointer operator= (const UniquePointer& other) = delete;
	UniquePointer operator= (UniquePointer&& other)
	{
		pointer = other.pointer;
		other.pointer = nullptr;
	}
	UniquePointer(UniquePointer&& other) noexcept
	{
		pointer = other.pointer;
		other.pointer = nullptr;
	}
	//UniquePointer(UniquePointer<T> other) { pointer = other.Get(); }
	T Get() { return pointer; }

};

