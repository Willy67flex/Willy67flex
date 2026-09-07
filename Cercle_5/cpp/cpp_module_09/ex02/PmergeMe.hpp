#ifndef PmergeMe_HPP
# define PmergeMe_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>
# include <ctime>
# include <sys/time.h>

typedef struct	s_numberPair
{
	int	smaller;
	int	bigger;
}	t_numberPair;

class PmergeMe
{
	private:
		std::vector<int>	_v;
		std::deque<int>		_d;
		std::vector<size_t>	_jacobsthalSuit;
		int					_size;


	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		~PmergeMe();

		PmergeMe	&operator=(const PmergeMe &other);

		void	sort(bool key, PmergeMe &p, double &duration);
		void	sortVector();
		void	sortDeque();

		template	<typename T>
		void	sortPair(T &pairs);

		template	<typename T>
		void	mergePairs(T &left, T &right, T &pairs);

		template	<typename T>
		void	jacobsthalSuit(T &pair);

		void	setVector(const int &n);
		void	setDeque(const int &n);

		void	printVector();
		void	printDeque();

		void	incrSize();
		int		getSize();

};

#endif