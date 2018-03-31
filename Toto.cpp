#include "Toto.hpp"

// STATIC ########################################################

// ###############################################################

// CANONICAL #####################################################

Toto::Toto ( void )
{
	return ;
}

Toto::Toto ( Toto const & src )
{
	*this = src;
	return ;
}

Toto &				Toto::operator=( Toto const & rhs )
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_nbToto = rhs.getNbToto();
	}
	return (*this);
}

Toto::~Toto ( void )
{
	return ;
}

// ###############################################################

// CONSTRUCTOR POLYMORPHISM ######################################

// ###############################################################

// OVERLOAD OPERATOR #############################################

std::ostream &				operator<<(std::ostream & o, Toto const & i)
{
	(void)i;
	return (o);
}

// ###############################################################

// PUBLIC METHOD #################################################

// ###############################################################

// GETTER METHOD #################################################

std::string			Toto::getName( void ) const noexcept
{
	return(this->_name);
}
unsigned int			Toto::getNbToto( void ) const noexcept
{
	return(this->_nbToto);
}

// ###############################################################

// SETTER METHOD #################################################

// ###############################################################

// PRIVATE METHOD ################################################

// ###############################################################

// EXCEPTION METHOD ##############################################

// ###############################################################

// EXTERNAL ######################################################

// ###############################################################
