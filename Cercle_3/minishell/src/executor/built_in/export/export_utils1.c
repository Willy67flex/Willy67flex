/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:17:02 by whollebe          #+#    #+#             */
/*   Updated: 2026/03/11 10:56:48 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*strdup_check_key_return_2(char *key)
{
	char	*result;
	size_t	i;

	result = malloc(sizeof(char) * strlen(key));
	i = 0;
	while (i < (strlen(key) - 1))
	{
		result[i] = key[i];
		i++;
	}
	result[i] = '\0';
	free(key);
	return (result);
}

char	*ft_strjoin_and_free(char *s1, char *s2, int key)
{
	char	*newstr;
	size_t	lens1;
	size_t	lens2;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	newstr = malloc(lens1 + lens2 + 1);
	if (!newstr)
		return (free(s1), free(s2), NULL);
	ft_strlcpy(newstr, s1, lens1 + 1);
	ft_strlcat(newstr, s2, lens1 + lens2 + 1);
	if (key == 0 || key == 2)
		free(s1);
	if (key == 1 || key == 3)
		free(s2);
	return (newstr);
}

int	size_env(t_data *data)
{
	t_env	*runner;
	int		i;

	runner = data->env;
	i = 0;
	while (runner != NULL)
	{
		if (runner->flag == 1)
			runner = runner->next_env;
		else
		{
			runner = runner->next_env;
			i++;
		}
	}
	return (i);
}

int	check_is_a_valide_key(char *key, char *s)
{
	size_t	i;
	int		flag;

	flag = find_pos_char(s, '=', ft_strlen(s));
	i = 0;
	if (!((key[i] >= 'A' && key[i] <= 'Z') || (key[i] >= 'a' && key[i] <= 'z')
			|| key[i] == '_'))
		return (1);
	i++;
	while (key[i])
	{
		if ((key[i] == '+' && key[i + 1] == '\0') && (flag != -1))
			return (2);
		if (!((key[i] >= 'A' && key[i] <= 'Z')
				|| (key[i] >= 'a' && key[i] <= 'z') || key[i] == '_'
				|| (key[i] >= '0' && key[i] <= '9')))
			return (1);
		i++;
	}
	return (0);
}

int	print_export_error(char *s, char *key, char *value, int nb)
{
	if (nb == 0)
	{
		ft_putstr_fd("Minishell: export: `", 2);
		ft_putstr_fd(s, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		free(key);
		free(value);
		return (1);
	}
	if (nb == 1)
	{
		print_custom_error("s", NULL, "command not found");
		free(key);
		free(value);
		return (127);
	}
	free(key);
	free(value);
	return (0);
}
