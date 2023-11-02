/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:07:45 by ameechan          #+#    #+#             */
/*   Updated: 2023/11/02 13:23:09 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c);
static char	*fill_word(char const *s, size_t start, size_t len);
static void	fill_table(char **words, char const *s, char c);
static void	*ft_free(char **words, int count);

char	**ft_split(char const *s, char c)
{
	char	**words;

	words = ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (!words || !s)
		return (NULL);
	fill_table(words, s, c);
	return (words);
}

static int	word_count(char const *s, char c)
{
	int	count;
	int	flag;
	int	i;

	count = 0;
	flag = 0;
	i = 0;
	while (*s)
	{
		if (flag == 0 && *s != c)
		{
			flag = 1;
			count++;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (count);
}

static void	fill_table(char **words, char const *s, char c)
{
	size_t	i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			words[j] = fill_word(s, start, i);
			if (!words[j])
				ft_free(words, j);
			start = -1;
			j++;
		}
		i++;
	}
}

static char	*fill_word(char const *s, size_t start, size_t end)
{
	char	*ptr;
	size_t	i;

	ptr = malloc((end - start + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (start < end)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static void	*ft_free(char **words, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(words[i]);
		i++;
	}
	free(words);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	(void)argc;
	int	count;
	count = word_count(argv[1], argv[2][0]);
	char	**res = ft_split(argv[1], argv[2][0]);

	printf("str: %s\n", argv[1]);
	printf("Elements of given array: \n");
	for (int i = 0; i < count; i++)
	{
		printf("%s\n", res[i]);
	}
}
 */
