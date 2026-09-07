#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _size(0) {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe::~PmergeMe() {}

PmergeMe	&PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_v = other._v;
		_d = other._d;
		_jacobsthalSuit = other._jacobsthalSuit;
		_size = other._size;
	}
	return *this;
}

void	PmergeMe::sort(bool key, PmergeMe &p, double &duration)
{
	clock_t	start = 0;
	clock_t	end = 0;

	if (key == 0)
	{
		start = clock();
		p.sortVector();
		end = clock();
		duration = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
	}
	else
	{
		start = clock();
		p.sortDeque();
		end = clock();
		duration = static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
	}
}

template	<typename T>
void	PmergeMe::mergePairs(T &left, T &right, T &pairs)
{
	size_t	i = 0, j = 0, k = 0;

	while (i < left.size() && j < right.size())
	{
		if (left[i].bigger < right[j].bigger)
			pairs[k++] = left[i++];
		else
			pairs[k++] = right[j++];
	}
	while (i < left.size())
		pairs[k++] = left[i++];
	while (j < right.size())
		pairs[k++] = right[j++];
}

template	<typename T>
void	PmergeMe::sortPair(T &pairs)
{
	if (pairs.size() <= 1)
		return;

	size_t			mid = pairs.size() / 2;
	T				left(pairs.begin(), pairs.begin() + mid);
	T				right(pairs.begin() + mid, pairs.end());

	sortPair(left);
	sortPair(right);

	mergePairs(left, right, pairs);
}

template	<typename T>
void	PmergeMe::jacobsthalSuit(T &pair)
{
	size_t				x = 1;
	T					y;
	size_t				size = pair.size();

	_jacobsthalSuit.clear();
	_jacobsthalSuit.push_back(1);
	y.push_back(1);
	for (size_t i = 0; _jacobsthalSuit[i] < size; i++)
	{
		y.push_back(static_cast<int>(x));
		if (i != 0)
		{
			x = x + 2 * static_cast<size_t>(y[i]);
			_jacobsthalSuit.push_back(x);
		}
		else
		{
			x = x + 2 * 1;
			_jacobsthalSuit.push_back(x);
		}
	}
}

void	PmergeMe::sortVector()
{
	std::vector<t_numberPair>	Vpair;
	t_numberPair				pair;
	bool						is_pair = 0;
	int							solitary_number = -1;
	std::vector<int>			mainChain;
	std::vector<int>			smallers;

	if (!(_v.size() % 2 == 0))
	{
		is_pair = 1;
		solitary_number = _v.back();
		_v.pop_back();
	}
	for (size_t i = 0; i < _v.size(); i += 2)
	{
		if (_v[i] < _v[i + 1])
		{
			pair.smaller = _v[i];
			pair.bigger = _v[i + 1];
		}
		else
		{
			pair.smaller = _v[i + 1];
			pair.bigger = _v[i];
		}
		Vpair.push_back(pair);
	}

	sortPair(Vpair);

	mainChain.push_back(Vpair[0].smaller);
	for (size_t i = 0; i < Vpair.size(); i++)
		mainChain.push_back(Vpair[i].bigger);

	for (size_t i = 1; i < Vpair.size(); i++)
		smallers.push_back(Vpair[i].smaller);
	
	if (solitary_number != -1)
		smallers.push_back(solitary_number);
	
	jacobsthalSuit(smallers);

	int	lastJacob = 0;
	int	i = 0;
	int	currentJacob;
	int	startPoint;
	
	while (lastJacob < static_cast<int>(smallers.size()))
	{
		currentJacob = _jacobsthalSuit[i];
		
		if (currentJacob < static_cast<int>(smallers.size()))
			startPoint = currentJacob;
		else
			startPoint = static_cast<int>(smallers.size());
		
		for (int j = startPoint; j > lastJacob; j--)
		{
			std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), smallers[j - 1]);
			mainChain.insert(it, smallers[j - 1]);
		}
		
		lastJacob = startPoint;
		i++;
	}
	_v = mainChain;
}

void	PmergeMe::sortDeque()
{
	std::deque<t_numberPair>	Dpair;
	t_numberPair				pair;
	bool						is_pair = 0;
	int							solitary_number = -1;
	std::deque<int>				mainChain;
	std::deque<int>				smallers;

	if (!(_d.size() % 2 == 0))
	{
		is_pair = 1;
		solitary_number = _d.back();
		_d.pop_back();
	}
	for (size_t i = 0; i < _d.size(); i += 2)
	{
		if (_d[i] < _d[i + 1])
		{
			pair.smaller = _d[i];
			pair.bigger = _d[i + 1];
		}
		else
		{
			pair.smaller = _d[i + 1];
			pair.bigger = _d[i];
		}
		Dpair.push_back(pair);
	}

	sortPair(Dpair);

	mainChain.push_back(Dpair[0].smaller);
	for (size_t i = 0; i < Dpair.size(); i++)
		mainChain.push_back(Dpair[i].bigger);

	for (size_t i = 1; i < Dpair.size(); i++)
		smallers.push_back(Dpair[i].smaller);
	
	if (solitary_number != -1)
		smallers.push_back(solitary_number);
	
	jacobsthalSuit(smallers);

	int	lastJacob = 0;
	int	i = 0;
	int	currentJacob;
	int	startPoint;
	
	while (lastJacob < static_cast<int>(smallers.size()))
	{
		currentJacob = _jacobsthalSuit[i];
		
		if (currentJacob < static_cast<int>(smallers.size()))
			startPoint = currentJacob;
		else
			startPoint = static_cast<int>(smallers.size());
		
		for (int j = startPoint; j > lastJacob; j--)
		{
			std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), smallers[j - 1]);
			mainChain.insert(it, smallers[j - 1]);
		}
		
		lastJacob = startPoint;
		i++;
	}
	_d = mainChain;
}

void	PmergeMe::setVector(const int &n)
{
	_v.push_back(n);
}

void	PmergeMe::setDeque(const int &n)
{
	_d.push_back(n);
}

void PmergeMe::printVector()
{
	if (_v.empty())
	{
		std::cout << "The vector is empty" << std::endl;
		return ;
	}
	for (size_t i = 0; i < _v.size(); ++i)
	{
		if (i > 10)
		{
			std::cout << "[...]";
			break ;
		}
		std::cout << _v[i] << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::printDeque()
{
	if (_d.empty())
	{
		std::cout << "The deque is empty" << std::endl;
		return ;
	}
	for (size_t i = 0; i < _d.size(); ++i)
	{
		if (i > 10)
		{
			std::cout << "[...]";
			break ;
		}
		std::cout << _d[i] << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::incrSize()
{
	_size++;
}

int	PmergeMe::getSize()
{
	return _size;
}
