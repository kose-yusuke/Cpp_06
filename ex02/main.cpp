/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:45:12 by koseki.yusu       #+#    #+#             */
/*   Updated: 2025/02/18 15:55:05 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


static Base *generate(void)
{
	switch (rand() % 3)
	{
	case 0:
		return (new A());
	case 1:
		return (new B());
	case 2:
		return (new C());
	}
    return (NULL);
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
		std::cout << "A is the identified type" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B is the identified type" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C is the identified type" << std::endl;
	else
		std::cout << "unknown type" << std::endl;
}

void identify(Base& p)
{
    try {
        (void)dynamic_cast<A &>(p);
        std::cout << "Class A" << std::endl;
        return;
    } catch (std::bad_cast &e) {
    }
    try {
        (void)dynamic_cast<B &>(p);
        std::cout << "Class B" << std::endl;
        return;
    } catch (std::bad_cast &e) {
    }
    try {
        (void)dynamic_cast<C &>(p);
        std::cout << "Class C" << std::endl;
        return;
    } catch (std::bad_cast &e) {
    }
    std::cout << "Unknown type" << std::endl;
}


int main()
{
    srand((int)time(NULL));
    for (int i = 0; 5 > i; i++)
    {
        Base *tmp = generate();
        if (tmp == NULL)
        {
            std::cout << "no type here" << std::endl;
            return (1);
        }
        else{
            std::cout << "test start" << std::endl;
            identify(tmp);
            identify(*tmp);
            delete tmp;
            std::cout << "test end" << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}