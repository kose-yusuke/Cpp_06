/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 22:50:26 by koseki.yusu       #+#    #+#             */
/*   Updated: 2025/02/18 15:07:10 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cstdlib>


class ScalarConverter{
    private:
        // インスタンス化をしない→ユーティリティクラスとして設計. privateに
        ScalarConverter();                      
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
        
        static bool isCharLiteral(const std::string& literal);
        static bool isIntLiteral(const std::string& literal);
        static bool isFloatLiteral(const std::string& literal);
        static bool isDoubleLiteral(const std::string& literal);

    public:
        static void convert(const std::string& literal);
};