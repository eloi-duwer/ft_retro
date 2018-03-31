// ------------------------------------------------------------	//
//																//
//																//
// ------------------------------------------------------------	//

#ifndef TOTO_HPP
# define TOTO_HPP

class Toto
{
	public:
	
		Toto( void );
		Toto( Toto const & src );
		virtual ~Toto( void );

		Toto &							operator=( Toto const & rhs );
		friend std::ostream &				operator<<(std::ostream & o, Toto const & i);

		std::string		getName( void ) const noexcept;
		unsigned int		getNbToto( void ) const noexcept;
	
	private:

		std::string		_name;
		unsigned int		_nbToto;
};

#endif
