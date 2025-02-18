/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 22:50:26 by koseki.yusu       #+#    #+#             */
/*   Updated: 2025/02/18 15:35:28 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <stdint.h>

typedef struct Data
{
    std::string str;
    int n;
    float f;
    double d;
} Data;

class Serializer{
    private:
		Serializer();
		~Serializer();
        Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};