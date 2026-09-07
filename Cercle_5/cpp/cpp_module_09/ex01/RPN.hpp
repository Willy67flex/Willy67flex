#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <list>

class RPN
{
	private:
		std::list<int>	_data;

	public:
		RPN();
		RPN(const RPN &other);
		~RPN();

		RPN	&operator=(const RPN &other);

		void	calculate(const char &op);

		int		getResult() const;
		void	setData(const int &value);

};

#endif