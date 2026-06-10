#ifndef easyfind_HPP
# define easyfind_HPP

# include <iostream>
# include <algorithm>
#include <vector>
#include <list>
#include <deque>

class	OccurrenceNotFound : public std::exception
{
	public:
		virtual const char *what() const throw();
};

template	<typename T>

typename T::iterator	easyfind(T &container, int n);

#include "easyfind.tpp"

#endif