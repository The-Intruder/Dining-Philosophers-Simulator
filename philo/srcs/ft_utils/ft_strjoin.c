/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:37:39 by mnaimi            #+#    #+#             */
/*   Updated: 2022/04/18 02:38:11 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo_head.h"

/* -------------------------------------------------------------------------- */

char	*ft_strjoin(char const *s1, char const *s2, char sep)
{
	size_t	i;
	char	*output_str;
	size_t	output_i;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (i == 0)
		return ((char *)ft_calloc(sizeof(char), 1));
	if (sep)
		++i;
	output_str = (char *) ft_calloc(sizeof(char), i + 1);
	if (!output_str)
		return (NULL);
	i = 0;
	output_i = 0;
	while (s1[i])
		output_str[output_i++] = s1[i++];
	i = 0;
	if (sep)
		output_str[output_i++] = sep;
	while (s2[i])
		output_str[output_i++] = s2[i++];
	output_str[output_i] = '\0';
	return (output_str);
}

/* -------------------------------------------------------------------------- */