#include "Map.hpp"

Map::Map()
{
	getmaxyx(stdscr,this->height,this->width);
}

Map::~Map()
{
	std::cout << "Map destroyed\n";
}

std::string Map::getOutput(void)
{
	std::string output = "The map is ";
	// output << "The map height is ";
	output += std::to_string(this->height);
	output += " tall and ";
	output += std::to_string(this->width);
	output += " wide \n";
	
	return output;
}


std::ostream &	operator<<(std::ostream & o, Map const & i)
{
	o << "The map height is " << i.height 
	<< " and the map width is " << i.width << std::endl;
	return (o);
}