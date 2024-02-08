/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:31:20 by ofadhel           #+#    #+#             */
/*   Updated: 2024/02/08 15:05:48 by ofadhel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_remove_line(char *s1)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	while (s1[i] && s1[i] != '\n')
		i++;
	if (!s1[i])
	{
		free(s1);
		return (NULL);
	}
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) - i + 1));
	if (!new)
		return (NULL);
	i++;
	j = 0;
	while (s1[i])
		new[j++] = s1[i++];
	new[j] = '\0';
	free(s1);
	return (new);
}
