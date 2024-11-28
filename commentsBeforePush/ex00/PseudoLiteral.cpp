#include "PseudoLiteral.hpp"

bool pseudoLiteral::is_pseudo(const std::string input)
{
        if ( (input.compare( "nan" ) == 0 ) || ( input.compare( "nanf" ) == 0 )
        || ( input.compare( "+inf" ) == 0 ) || ( input.compare( "+inff" ) == 0 ) 
        || ( input.compare( "-inf" ) == 0 ) || ( input.compare( "-inff" ) == 0 ) 
        || ( input.compare( "-inff" ) == 0 ) || ( input.compare( "-inff" ) == 0 )  
        || ( input.compare( "+inff" ) == 0 ) || ( input.compare( "+inff" ) == 0 ) ) {
            return true;
        }
    
    return false;
}
	
void	pseudoLiteral::print_pseudo(std::string input)
{
		std::cout << "char: " << "impossible" << "\n";
		std::cout << "int: " << "impossible" << "\n";
		std::cout << "float: " << ((input[input.size() - 1] == 'f') ? input : (input + 'f')) << std::endl;
		std::cout << "double: " << input << "\n";
}