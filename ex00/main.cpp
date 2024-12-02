/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 22:50:18 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/12/02 15:20:35 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv){
    if (argc != 2)
    {
        std::cout << "Error : input 1 argument" << std::endl;
        return (1);
    }
    ScalarConverter::convert(argv[1]);
}