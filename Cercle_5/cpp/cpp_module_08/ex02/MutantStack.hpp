#ifndef MutantStack_HPP
# define MutantStack_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <list>
#include <vector>

template	<typename T, typename Container = std::deque<T> >
class	MutantStack : public std::stack<T, Container>
{
	public:

		typedef typename Container::iterator				iterator;
		typedef typename Container::const_iterator			const_iterator;
		typedef typename Container::reverse_iterator		reverse_iterator;
		typedef typename Container::const_reverse_iterator	const_reverse_iterator;

		MutantStack();
		MutantStack(const MutantStack<T, Container> &other);
		virtual ~MutantStack();
	
		MutantStack<T, Container>			&operator=(const MutantStack<T, Container> &other);

		iterator				begin();
		iterator				end();

		const_iterator			begin() const;
		const_iterator			end() const;

		reverse_iterator		rbegin();
		reverse_iterator		rend();

		const_reverse_iterator	rbegin() const;
		const_reverse_iterator	rend() const;

};

#include "MutantStack.tpp"

#endif