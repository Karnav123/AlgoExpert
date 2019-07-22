#pragma once
#include <memory>
class ABC
{
private:
	struct Data;
	std::unique_ptr<Data> currentData;

	// To store the values of the Data for future comparisons.
	static std::unique_ptr<Data> prevData;

public:
	ABC();
	~ABC();

	// some methods
};