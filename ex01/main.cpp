/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 22:50:18 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/12/02 20:51:07 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iomanip>

int main()
{
    Data* data = new Data;
	data->str = "42 Tokyo";
	data->n = 42;
	data->f = 42.0f;
	data->d = 3.14;

	uintptr_t raw = Serializer::serialize(data);
	Data* data2 = Serializer::deserialize(raw);

	std::cout << "Data before serialization" << std::endl;
	std::cout << "data->str: " << data->str << std::endl;
	std::cout << "data->n: " << data->n << std::endl;
	std::cout << "data->f: "  << std::fixed << data->f << std::endl;
	std::cout << "data->d: "  << std::fixed << data->d << std::endl;

	std::cout << std::endl;
	std::cout << "Data after serialization" << std::endl;
	std::cout << "data2->str: " << data2->str << std::endl;
	std::cout << "data2->n: " << data2->n << std::endl;
	std::cout << "data2->f: " << std::fixed << data2->f << std::endl;
	std::cout << "data2->d: " << std::fixed << data2->d << std::endl;

	delete data;
	return (0);
}
