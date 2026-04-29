#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "constructor called" << std::endl;
}

Harl::~Harl()
{
	std::cout << "destructor called" << std::endl;
}

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle" 
			  << "-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put"
			  << "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
			  << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for"
			  << "years, whereas you started working here just last month." << std::endl;
}

void	coucou()
{
	return ;
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain( std::string level )
{
	std::string	str[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	// TypeDeRetour (NomDeLaClasse::*NomDuTableau[])(ParametresDeLaFonction)
	void (Harl::*function[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (str[i] == level)
		{
			// this = cree une instance pour executer la fonction sur lui meme(Harl du main)
			(this->*function[i])();
			return ;
		}
	}
}
