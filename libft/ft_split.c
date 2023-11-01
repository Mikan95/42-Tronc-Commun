/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:07:45 by ameechan          #+#    #+#             */
/*   Updated: 2023/11/01 15:29:12 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c);
static char	*fill_word(char const *s, size_t start, size_t len, char c);
static void	fill_table(char **words, char const *s, char c);
static void	*ft_free(char **words, int count);

/*
size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < count * size)
	{
		*(ptr + i) = '\0';
		i++;
	}
	return ((void *)ptr);
}
 */
char	**ft_split(char const *s, char c)
{
	char	**words;

	if (ft_strlen(s) == 0)
		return (NULL);
	words = ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (!words)
		return (NULL);
	fill_table(words, s, c);
	return (words);
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
			words[j] = fill_word(s, start, i, c);
			if (!words[j])
				ft_free(words, j);
			start = -1;
			j++;
		}
		i++;
	}
}

static char	*fill_word(char const *s, size_t start, size_t end, char c)
{
	char	*ptr;
	size_t	i;

	ptr = malloc((end - start + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < end && s[start] != c)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static int	word_count(char const *s, char c)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			res++;
		i++;
	}
	return (res);
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
	count = word_count(argv[1], argv[2][0]) + 1;
	char	**res = ft_split(argv[1], argv[2][0]);

	printf("str: %s\n", argv[1]);
	printf("Elements of given array: \n");
	for (int i = 0; i < count; i++)
	{
		printf("%s\n", res[i]);
	}
}
 */
