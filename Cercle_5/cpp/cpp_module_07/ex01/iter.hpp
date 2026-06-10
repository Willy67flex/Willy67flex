#ifndef iter_HPP
# define iter_HPP

#include <iostream>

template	<typename T, typename F>

void iter(T *array, const size_t length, F func)
{
	if (!array)
		return;

	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

#endif