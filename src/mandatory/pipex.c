/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:12:23 by namoreir          #+#    #+#             */
/*   Updated: 2023/11/20 16:44:29 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_cmd(t_pipex *pipex)
{
	int		i;
	char	*temp;

	pipex->cmd = ft_split(pipex->av[pipex->nb_cmd_curr], ' ');
	if (!pipex->cmd)
		wenting_wrong(error_msg("Error spliting cmd\n", 6), pipex, 2);
	i = -1;
	temp = NULL;
	while (pipex->cmd[++i])
	{
		temp = pipex->cmd[i];
		pipex->cmd[i] = ft_strtrim(pipex->cmd[i], "'");
		free(temp);
	}
}

void	check_cmd(t_pipex *pipex)
{
	int		i;
	char	*cmd;

	get_cmd(pipex);
	i = 0;
	while (pipex->paths[i])
	{
		cmd = ft_strjoin(pipex->paths[i], (const char *)pipex->cmd[0]);
		if (access(cmd, F_OK) == 0
			&& execve(cmd, pipex->cmd, pipex->envp) == -1)
		{
			free(cmd);
			wenting_wrong(error_msg("Error executing cmd\n", 7), pipex, 2);
		}
		free(cmd);
		i++;
	}
	wenting_wrong(error_msg("Error to find path\n", 8), pipex, 2);
}

void	create_child(t_pipex *pipex)
{
	pipex->pid = fork();
	if (pipex->pid == -1)
		wenting_wrong(error_msg("Error while creating fork\n", 5), pipex, 2);
	if (pipex->pid == 0)
	{
		//redirecionando a saída padrão para o pipe
		dup2(pipex->fd[1], STDOUT_FILENO);
		close(pipex->fd[0]);
		close(pipex->fd[1]);
		//redirecionando a entrada padrão para o infile
		dup2(pipex->fd_inf, STDIN_FILENO);
		check_cmd(pipex);
	}
	pipex->pid_2 = fork();
	if (pipex->pid_2 == -1)
		wenting_wrong(error_msg("Error while creating fork\n", 5), pipex, 2);
	if (pipex->pid_2 == 0)
	{
		pipex->nb_cmd_curr++;
		//redirecionando a entrada padrão para o pipe
		dup2(pipex->fd[0], STDIN_FILENO);
		close(pipex->fd[0]);
		close(pipex->fd[1]);
		//redirecionando a saída padrão para o outfile
		dup2(pipex->fd_outf, STDOUT_FILENO);
		check_cmd(pipex);
	}
}
