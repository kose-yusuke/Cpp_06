/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 22:50:29 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/12/02 16:25:32 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool ScalarConverter::isCharLiteral(const std::string& literal) {
    if (literal.length() == 1 && !std::isdigit(literal[0]))
        return true;
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
        return true;
    return false;
}


bool ScalarConverter::isIntLiteral(const std::string& literal) {
    char* end;
    std::strtol(literal.c_str(), &end, 10);
    return *end == '\0';
}

bool ScalarConverter::isFloatLiteral(const std::string& literal) {
    char* end;
    std::strtof(literal.c_str(), &end);
    return (*end == 'f' && *(end + 1) == '\0') || literal == "-inff" || literal == "+inff" || literal == "nanf";
}

bool ScalarConverter::isDoubleLiteral(const std::string& literal) {
    char* end;
    std::strtod(literal.c_str(), &end);
    return *end == '\0' || literal == "-inf" || literal == "+inf" || literal == "nan";
}

void printConversions(char c, int i, float f, double d, bool charValid) {
    if (std::isnan(f) || std::isinf(f)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
        return;
    }

    if (std::isnan(d) || std::isinf(d)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
        return;
    }

    if (charValid) {
        std::cout << "char: '" << c << "'" << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
    }

    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}


void ScalarConverter::convert(const std::string& literal){
    try {
        if (isCharLiteral(literal))
        {
            char c;
            if (literal.length() == 1)
                c = literal[0];
            else
                c = literal[1];
            printConversions(c, static_cast<int>(c), static_cast<float>(c), static_cast<double>(c),true);
        }
        else if(isIntLiteral(literal))
        {
            int i = std::stoi(literal);
            bool charValid = (i >= 0 && i <= 127 && std::isprint(static_cast<char>(i)));
            printConversions(static_cast<char>(i), i, static_cast<float>(i), static_cast<double>(i), charValid);
        }
        else if(isFloatLiteral(literal))
        {
            float f = std::stof(literal);
            bool charValid = (f >= 0 && f <= 127 && std::isprint(static_cast<char>(f)));
            printConversions(static_cast<char>(f), static_cast<int>(f), f, static_cast<double>(f), charValid);
        }
        else if (isDoubleLiteral(literal)) 
        {
            double d = std::stod(literal);
            bool charValid = (d >= 0 && d <= 127 && std::isprint(static_cast<char>(d)));
            printConversions(static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), d, charValid);
        }
        else 
            throw std::invalid_argument("Invalid literal");
    } catch (const std::invalid_argument& e){
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const std::out_of_range&) {
        std::cerr << "Error: Value out of range" << std::endl;
    } catch (...) {
        std::cerr << "Error: An unknown error occurred" << std::endl;
    }
}
