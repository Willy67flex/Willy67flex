#include "easyfind.hpp"

const char *OccurrenceNotFound::what() const throw()
{
	return "Occurrence not found in container";
}


template <typename T>

typename T::iterator easyfind(T &container, int n)
{
	typename T::iterator	i = std::find(container.begin(), container.end(), n);

	if (i == container.end())
		throw OccurrenceNotFound();

	return i;
}
