#ifndef Span_HPP
# define Span_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <ctime>
#include <cstdlib>

class	Span
{
	private:

		std::vector<int>	_value;
		unsigned int		_N;

	public:

		Span(unsigned int N);
		Span(const Span &other);
		~Span();

		Span		&operator=(const Span &other);

		void		addNumber(int n);

		template	<typename Iterator>
		void		addNumber(Iterator begin, Iterator end)
		{
			if (std::distance(begin, end) + _value.size() > _N)
				throw NbOfIntegerExceeds();
			_value.insert(_value.end(), begin, end);
		}

		int			shortestSpan() const;
		int			longestSpan() const;

		class	NbOfIntegerExceeds : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class SpanImpossible : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

#endif