#pragma once
#include <exception>

class exception : public std::exception
{
private:
	const char* desc;
public:
	exception(const char* error)
	{
		desc = error;
	}
	const char* what() const noexcept
	{
		return desc;
	}
};