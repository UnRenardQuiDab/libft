/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:26:00 by bwisniew          #+#    #+#             */
/*   Updated: 2023/11/08 17:01:52 by bwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != '\0')
			size++;
		while (s[i] && s[i] != c)
			i++;
		i++;
	}
	return (size);
}

static char	*ft_create_word(char *s, char c)
{
	char	*word;
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = malloc((sizeof(char) * i) + 1);
	ft_memcpy(word, s, i);
	word[i] = '\0';
	return (word);
}



char	**ft_split(char const *s, char c)
{
	size_t	nb_word;
	size_t	i;
	size_t	i_strs;
	char	**strs;

	nb_word = ft_count_word(s, c);
	strs = malloc((sizeof(char *) * nb_word) + 1);
	if (!strs)
		return (0);
	i = 0;
	i_strs == 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		
		while (s[i])
		{
			/* code */
		}
		
		
	}
	
}
