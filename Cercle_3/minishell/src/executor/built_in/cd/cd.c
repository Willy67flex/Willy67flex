/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:54:39 by whollebe          #+#    #+#             */
/*   Updated: 2026/03/11 13:40:38 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	change_directory(t_data *data, char *path)
{
	t_env	*oldpwd;
	t_env	*pwd;
	char	*new_oldpwd;
	char	*new_pwd;

	new_oldpwd = getcwd(NULL, 0);
	if (chdir(path) == -1)
	{
		ft_chdir_error(data, path);
		free(new_oldpwd);
		return (-1);
	}
	new_pwd = getcwd(NULL, 0);
	oldpwd = get_env_node(data->env, "OLDPWD");
	pwd = get_env_node(data->env, "PWD");
	if (oldpwd)
		update_existing_env(oldpwd, new_oldpwd, 0, 0);
	else
		add_env_node(data, ft_strdup("OLDPWD"), new_oldpwd, 0);
	if (pwd)
		update_existing_env(pwd, new_pwd, 0, 0);
	else
		add_env_node(data, ft_strdup("PWD"), new_pwd, 0);
	return (0);
}

void	return_to_old_folder(t_data *data, char **str)
{
	t_env	*oldpwd;
	char	*value;

	oldpwd = get_env_node(data->env, "OLDPWD");
	if (oldpwd && oldpwd->value)
	{
		if (str[1][1] != '\0')
		{
			ft_option_error(data, str[1][1]);
			return ;
		}
		value = ft_strdup(oldpwd->value);
		if (change_directory(data, oldpwd->value) == -1)
		{
			free(value);
			return ;
		}
		printf("%s\n", value);
		free(value);
	}
	else
	{
		data->exit_code = 1;
		print_custom_error("cd", NULL, "OLDPWD not set");
	}
}

void	start_home(t_data *data, char *str, int key)
{
	t_env	*node;

	node = get_env_node(data->env, "HOME");
	if (node && node->value && key == 0)
		change_directory(data, node->value);
	else if (node && node->value && key == 1)
	{
		if (str[1] == '/')
			change_directory(data, ft_strjoin(node->value, &str[1]));
		else if (str[1] == '\0')
			change_directory(data, node->value);
		else
		{
			data->exit_code = 1;
			print_custom_error("cd", str, "No such file or directory");
		}
	}
	else
	{
		data->exit_code = 1;
		print_custom_error("cd", NULL, "HOME not set");
	}
}

void	ft_cd(t_data *data, char **str)
{
	if (str[1] == NULL)
	{
		start_home(data, str[1], 0);
		return ;
	}
	if (str[2])
	{
		data->exit_code = 1;
		print_custom_error("cd", NULL, "too many arguments");
		return ;
	}
	if (str[1][0] == '~')
	{
		start_home(data, str[1], 1);
		return ;
	}
	if (str[1][0] == '-')
	{
		return_to_old_folder(data, str);
		return ;
	}
	if (change_directory(data, str[1]) == -1)
		return ;
}
