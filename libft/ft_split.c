/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:07:45 by ameechan          #+#    #+#             */
/*   Updated: 2023/10/31 16:00:39 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c);
static char	*fill_word(char *s, size_t start, size_t len);
static void	ft_free(char **words);

char	**ft_split(char const *s, char c)
{
	char			**words;
	unsigned int	i;
	unsigned int	j;

	if (ft_strlen(s) == 0)
		return (NULL);
	words = ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (!words)
		ft_free(words);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			fill_word((char *)s, j, i - (j - 1));
			j = i + 1;
		}
		i++;
	}
	return (words);
}

static void	ft_free(char **words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
}

static char	*fill_word(char *s, size_t start, size_t len)
{
	char	*ptr;
	size_t	i;

	ptr = ft_calloc(len, sizeof(char));
	i = 0;
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
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
/*
int	main(int argc, char **argv)
{
	(void)argc;
	printf("str: %s\n", argv[0]);
	printf("%s", ft_split(argv[0], argv[1][0])[0]);
}
*/
