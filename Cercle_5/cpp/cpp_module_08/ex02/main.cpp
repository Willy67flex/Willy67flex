#include "MutantStack.hpp"

int	main()
{
	std::cout << "--- Test du Sujet (MutantStack) ---" << std::endl;
	MutantStack<int>	mstack;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size: " << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();
	
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int>	s(mstack);

	std::cout << "\n--- Comparaison avec std::list (Même contenu) ---" << std::endl;
	std::list<int>	mlist;

	mlist.push_back(5);
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);

	std::list<int>::iterator	lit = mlist.begin();
	std::list<int>::iterator	lite = mlist.end();

	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}

	std::cout << "\n--- Test Reverse Iterators ---" << std::endl;
	MutantStack<int>::reverse_iterator	rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator	rite = mstack.rend();

	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}

	std::cout << "\n--- Vector Test ---" << std::endl;
	MutantStack<int, std::vector<int> > vstack;
	vstack.push(42);
	vstack.push(43);
	MutantStack<int, std::vector<int> >::iterator vit = vstack.begin();
	std::cout << *vit << std::endl;

	std::cout << "\n--- Test Forme Canonique (Copie) ---" << std::endl;
	MutantStack<int>	copyStack(mstack);

	std::cout << "Size de la copie: " << copyStack.size() << std::endl;
	
	MutantStack<int>	assignStack;

	assignStack = mstack;
	std::cout << "Size de l'assignation: " << assignStack.size() << std::endl;

	std::cout << "\n--- Test Const Iterators ---" << std::endl;
	const MutantStack<int>				constStack = mstack;
	MutantStack<int>::const_iterator	cit = constStack.begin();
	MutantStack<int>::const_iterator	cite = constStack.end();

	while (cit != cite)
	{
		std::cout << *cit << std::endl;
		++cit;
	}

	return 0;
}
