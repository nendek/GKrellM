/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 13:20:51 by eduriez           #+#    #+#             */
/*   Updated: 2019/06/02 12:24:53 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Monitor.hpp"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc > 2)
	{
		std::cout << "usage:" << std::endl;
		std::cout << "./ft_gkrellm [v]" << std::endl;
		return (0);
	}
	Monitor *monitor = new Monitor();
	if (argc == 1)
	{
		monitor->ncursesChoice();
	}
	else
	{
		if (argv[1][0] == 'v' && argv[1][1] == '\0')
		{
			monitor->sfmlChoice();
		}
		else
		{
			std::cout << "usage:" << std::endl;
			std::cout << "./ft_gkrellm [v]" << std::endl;
			return (0);
		}
	}
	delete monitor;
	return (0);
}
