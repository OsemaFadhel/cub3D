/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:30:18 by ofadhel           #+#    #+#             */
/*   Updated: 2024/01/31 10:41:46 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

size_t	ft_strlen(const char *s)
{
	int	c;

	c = 0;
	while (s[c] != '\0')
	{
		c++;
	}
	return (c);
}

int	count_words(char const *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != c && s[i])
			{
				i++;
			}
		}
		else
			i++;
	}
	return (words);
}

char	*strsub(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*str;

	str = malloc(sizeof(char) * (len - start + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (start < len)
	{
		str[j] = s[start];
		j++;
		start++;
	}
	str[j] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (NULL);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j] = strsub(s, index, i);
			index = -1;
			j++;
		}
		i++;
	}
	split[j] = '\0';
	return (split);
}

char	**read_map(char *file, t_game *game)
{
	int		fd;
	char	*line;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = malloc(sizeof(char) * 10000000);
	read(fd, line, 10000000);
	map = ft_split(line, '\n');
	free(line);
	return (map);
}
