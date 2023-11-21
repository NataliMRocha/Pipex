/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:34:39 by natali            #+#    #+#             */
/*   Updated: 2023/11/20 12:50:20 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error_msg(char *str1, int error)
{
	ft_putstr_fd("Pipex: ", 2);
	ft_putstr_fd(str1, 2);
	return (error);
}

void	wenting_wrong(int error, t_pipex *pipex, int flag)
{
	if (flag != 1)
	{
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		close(pipex->fd_inf);
		close(pipex->fd_outf);
		ft_free(pipex);
	}
	exit(error);
}

void	ft_free(t_pipex *pipex)
{
	int	i;

	i = -1;
	if (pipex->paths != NULL)
	{
		while (pipex->paths[++i])
		{
			free(pipex->paths[i]);
			pipex->paths[i] = NULL;
		}
		free(pipex->paths);
		pipex->paths = NULL;
	}
	i = -1;
	if (pipex->cmd != NULL)
	{
		while (pipex->cmd[++i])
		{
			free(pipex->cmd[i]);
			pipex->cmd[i] = NULL;
		}
		free(pipex->cmd);
		pipex->cmd = NULL;
	}
}
