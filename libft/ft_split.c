/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:37:55 by mmarcele          #+#    #+#             */
/*   Updated: 2022/05/23 17:19:37 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_word(char const *s, char c)
{
	size_t	num_obj;
	int		check;

	num_obj = 0;
	check = 0;
	while (*s != 0)
	{
		if (*s != c)
		{
			check = 1;
		}
		else if (*s == c && check == 1)
		{
			num_obj++;
			check = 0;
		}
		s++;
	}
	if (check == 1)
	{
		num_obj++;
	}
	return (num_obj);
}

static int	get_length(const char *s, char c)
{
	size_t	length;

	length = 0;
	while (*s != c && *s != 0)
	{
		length++;
		s++;
	}
	return (length);
}

static char	**free_out(char **output, int word)
{
	while (word != 0)
	{
		free(output[word]);
		word--;
	}
	free(output);
	return (NULL);
}

static char	**fill_output(char const *s, char c, char **output, size_t word)
{
	size_t	ch;

	while (*s != 0)
	{
		if (*s != c)
		{
			output[word] = malloc(sizeof(char) * (get_length(s, c) + 1));
			if (output[word] == NULL)
			{
				free_out(output, word);
				return (NULL);
			}
			ch = 0;
			while (*s != c && *s != 0)
				output[word][ch++] = *s++;
			output[word++][ch] = 0;
			s--;
		}
		s++;
	}
	output[word] = 0;
	return (output);
}

char	**ft_split(char const *s, char c)
{
	char	**output;
	size_t	word;

	if (s == NULL)
		return (NULL);
	output = malloc(sizeof(char *) * (get_word(s, c) + 1));
	if (output == NULL)
		return (NULL);
	word = 0;
	return (fill_output(s, c, output, word));
}
