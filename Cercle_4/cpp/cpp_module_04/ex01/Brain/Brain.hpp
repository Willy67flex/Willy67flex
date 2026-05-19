#ifndef Brain_HPP
# define Brain_HPP

# include <iostream>

class Brain
{
	private:

		std::string	ideas[100];

	public:

		Brain();
		Brain(const Brain &other);
		~Brain();

		Brain	&operator=(const Brain &other);

		void		setIdea(int i, std::string idea);
		std::string	getIdea(int i);

};


#endif