#include <iostream>

#include <memory>

#include "DuplicateUniquePointer.h"

template <typename T, typename... Arguments>
DuplicateUniquePointer<T> make_my_unique(Arguments... args)
{
	return DuplicateUniquePointer<T>(new T{ std::forward(args...) });
}

struct Point
{
	int x{};
	int y{};

	Point(int tx, int ty) : x(tx), y(ty) {}
};

int main()
{

	auto t = make_my_unique<Point>(1, 2);


	return 0;

	//DuplicateUniquePointer<int> a{ new int(42) };

	//a = DuplicateUniquePointer<int>(nullptr);

	//a.Reset(nullptr);

	//a = nullptr;

	////a = new int(56);

	//std::cout << "Hello World!\n";
}