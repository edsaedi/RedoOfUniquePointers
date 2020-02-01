#pragma once
template <class T>
class DuplicateUniquePointer
{
private:
	T* pointer = nullptr;

public:
	DuplicateUniquePointer() = default;
	~DuplicateUniquePointer()
	{
		if (pointer != nullptr)
		{
			delete pointer;
		}
	}

	explicit DuplicateUniquePointer(T* item)
	{
		pointer = item;
	}

	DuplicateUniquePointer(nullptr_t) {

	}

	DuplicateUniquePointer(const DuplicateUniquePointer& other) = delete;
	DuplicateUniquePointer& operator=(const DuplicateUniquePointer& other) = delete;

	DuplicateUniquePointer(DuplicateUniquePointer&& other)
	{
		pointer = other.pointer;
		other.pointer = nullptr;
	}
	DuplicateUniquePointer& operator= (DuplicateUniquePointer&& other) noexcept
	{
		if (this->pointer != nullptr) {
			delete this->pointer;
		}

		this->pointer = other.pointer;
		other.pointer = nullptr;

		return *this;
	}
	T* Get() const
	{
		return pointer;
	}

	void Reset(T* newValue)
	{
		if (this->pointer != nullptr) {
			delete this->pointer;
		}
		pointer = newValue;
	}
};

