/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhunter <mhunter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:20:53 by mhunter           #+#    #+#             */
/*   Updated: 2022/01/29 16:31:41 by mhunter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	counter(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ft_convert(char *out, long num, int size, int n)
{
	size--;
	if (num == 0)
		out[size] = '0';
	if (n > 0)
	{
		while (size >= 0)
		{
			out[size--] = num % 10 + 48;
			num /= 10;
		}
	}
	else
	{
		while (size--)
		{
			out[size] = num % 10 + 48;
			num /= 10;
		}
	}
}

char	*ft_itoa(int n)
{
	int		i;
	int		size;
	long	num;
	char	*str;

	num = n;
	if (num < 0)
		num = num * (-1);
	size = counter(num);
	if (n < 0)
		size++;
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	i = 0;
	if (n < 0)
		str[i++] = '-';
	ft_convert(str + i, num, size, n);
	str[size] = '\0';
	return (str);
}
