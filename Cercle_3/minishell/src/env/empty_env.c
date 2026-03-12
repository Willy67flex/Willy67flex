/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:39:32 by whollebe          #+#    #+#             */
/*   Updated: 2026/03/11 13:22:56 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	build_oldpwd(t_data *data)
{
	t_env	*node;

	node = malloc(sizeof(t_env));
	if (!node)
		exit(free_all(data, 1));
	node->flag = 0;
	node->key = ft_strdup("OLDPWD");
	if (!node->key)
	{
		free(node);
		exit(free_all(data, 1));
	}
	node->next_env = NULL;
	node->print = 0;
	node->value = NULL;
	env_add_back(&data->env, node);
}

void	incr_shlvl(t_data *data)
{
	int		value;
	t_env	*node;

	node = get_env_node(data->env, "SHLVL");
	value = ft_atoi(node->value);
	free(node->value);
	value++;
	node->value = ft_itoa(value);
}

void	build_pwd(t_data *data)
{
	char	*pwd;
	t_env	*node;

	pwd = build_env_pwd("PWD=", data);
	node = new_env_node(pwd);
	free(pwd);
	if (!node)
		exit(free_all(data, 1));
	env_add_back(&data->env, node);
}

void	check_env(t_data *data)
{
	t_env	*node;

	if (get_env_node(data->env, "OLDPWD") == NULL)
		build_oldpwd(data);
	if (get_env_node(data->env, "PWD") == NULL)
		build_pwd(data);
	if (get_env_node(data->env, "PATH") == NULL)
	{
		node = new_env_node("PATH=/usr/local/bin:/usr/local/sbin:"
				"/usr/bin:/usr/sbin:/bin:/sbin");
		if (!node)
			exit(free_all(data, 1));
		node->flag = 1;
		env_add_back(&data->env, node);
	}
	if (get_env_node(data->env, "SHLVL") == NULL)
	{
		node = new_env_node("SHLVL=1");
		if (!node)
			exit(free_all(data, 1));
		env_add_back(&data->env, node);
	}
	else
		incr_shlvl(data);
}
