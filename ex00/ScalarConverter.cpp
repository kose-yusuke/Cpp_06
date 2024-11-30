/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 22:50:29 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/30 23:07:47 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool ScalarConverter::isCharLiteral(const std::string& literal) {
    return literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'';
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

void ScalarConverter::convert(const std::string& literal){
    
}

