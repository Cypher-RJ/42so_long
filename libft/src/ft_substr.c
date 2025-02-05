/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcesar-d <rcesar-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:43:16 by rcesar-d          #+#    #+#             */
/*   Updated: 2024/10/14 15:38:42 by rcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	slen;
	size_t	alloc_size;

	slen = ft_strlen(s);
	if (slen - start < len)
		alloc_size = slen - start;
	else
		alloc_size = len;
	if (start >= slen)
		return (ft_strdup(""));
	str = (char *)malloc(alloc_size + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[start + i] && i < alloc_size)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
