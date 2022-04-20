/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:37:39 by mnaimi            #+#    #+#             */
/*   Updated: 2022/04/18 02:38:11 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo_head.h"

/* -------------------------------------------------------------------------- */

static char	*move_chars(const char *set, char *s1_ptr)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1_ptr) - 1;
	while (set[i++] && *s1_ptr)
	{
		if (set[i - 1] == s1_ptr[0])
			s1_ptr++;
		else if (set[i - 1] == s1_ptr[j])
			s1_ptr[j--] = 0;
		else
			continue ;
		i = 0;
	}
	return (s1_ptr);
}

/* - - - - - - - - - - - - - - - - - - <> - - - - - - - - - - - - - - - - - - */

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s1_ptr;
	char	*dummy_ptr;
	char	*final_str;

	if (!s1 || !set)
		return (NULL);
	s1_ptr = ft_strdup(s1);
	if (s1_ptr == NULL)
		return (NULL);
	dummy_ptr = s1_ptr;
	final_str = ft_strdup((const char *)(move_chars(set, s1_ptr)));
	if (final_str == NULL)
		return (NULL);
	free(dummy_ptr);
	return (final_str);
}

/* -------------------------------------------------------------------------- */
