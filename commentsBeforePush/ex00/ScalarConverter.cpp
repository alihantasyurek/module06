#include "ScalarConverter.hpp"
#include "PseudoLiteral.hpp"


void ScalarConverter::convert(std::string input)
{
    if (pseudoLiteral::is_pseudo(input))
        return pseudoLiteral::print_pseudo(input);

    ScalarConverter::toChar(input);
    ScalarConverter::toInt(input);
    ScalarConverter::toFloat(input);
    ScalarConverter::toDouble(input);

}


void ScalarConverter::toChar(std::string input)
{
    std::cout << "char: " ;
    try
	{
		if(std::atoi(input.c_str()) > 255)
			throw std::exception(); // When throwing exceptions in C++, you must throw an instance of a type (an object). For example, std::exception() is a temporary object of type std::exception created using its default constructor.
		else if(input.length() == 1 && !std::isdigit(input[0]) && std::isprint(input[0])) //a
			std::cout << "'" <<static_cast<char>(input[0]) << "'" << std::endl;
		else if(std::isprint(static_cast<char>(std::atoi(input.c_str())))) // 42.1f == 42 == * // need numbers first 
			std::cout << "'" << static_cast<char>(std::atoi(input.c_str())) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;

	}
    catch(const std::exception& e)
    {
        std::cout << "impossible" << std::endl;
    }
    
}

void	ScalarConverter::toInt(std::string input)
{
	std::cout << "int: ";
	try {
		int num = std::stoi(input); // 42.1f == 42(int); it needs to see number first
		std::cout << num << std::endl;

	} 
	catch (const std::invalid_argument& ia) 
	{
		if (input.length() == 1 && std::isprint(input[0]))//a? 
			std::cout << static_cast<int>(input[0]) << std::endl;
		else
			std::cout << "impossible" << std::endl;
	} 
	catch (const std::out_of_range& oor) {
		std::cout << "impossible" << std::endl;
	}
}

void ScalarConverter::toFloat(std::string input)
{
	std::cout << "float: ";
	try
	{
		if(std::isdigit(input[0]))
			std::cout << std::fixed << std::setprecision(1) << static_cast<float>(std::stof(input)) << "f";
		else if (input.length() == 1 && std::isprint(input[0]))
			std::cout << std::fixed << std::setprecision(1) << static_cast<float>(input[0])<< "f";
		else
			std::cout << std::fixed << std::setprecision(1) << static_cast<float>(std::stof(input)) << "f";
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
}

void ScalarConverter::toDouble(std::string input)
{
	std::cout << "double: ";
	try
	{
		if(std::isdigit(input[0]))
			std::cout << std::fixed << std::setprecision(1) << static_cast<double>(std::strtod(input.c_str(), nullptr));
		else if (input.length() == 1 && std::isprint(input[0]))
			std::cout << std::fixed << std::setprecision(1) << static_cast<double>(input[0]);
		else
			std::cout << std::fixed << std::setprecision(1) << static_cast<double>(std::strtod(input.c_str(), nullptr));


		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
	
}
