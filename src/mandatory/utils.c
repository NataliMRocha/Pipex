/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:35:35 by natali            #+#    #+#             */
/*   Updated: 2023/11/20 14:15:32 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_file(t_pipex *pipex)
{
	pipex->fd_inf = open(pipex->av[1], O_RDONLY);
	pipex->fd_outf = open(pipex->av[pipex->ac - 1],
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->fd_inf < 0)
	{
		if (pipex->fd_outf >= 0)
			close(pipex->fd_outf);
		close(pipex->fd[0]);
		close(pipex->fd[1]);
		wenting_wrong(error_msg("Error while open infile\n", 4), pipex, 1);
	}
	if (pipex->fd_outf < 0)
	{
		close(pipex->fd[0]);
		close(pipex->fd[1]);
		close(pipex->fd_inf);
		wenting_wrong(error_msg("Error while deal with outfile\n", 2),
			pipex, 1);
	}
}

void	get_path(t_pipex *pipex)
{
	int		i;

	i = 0;
	while (!ft_strnstr(pipex->envp[i], "PATH=", 5))
		i++;
	pipex->paths_temp = ft_split(pipex->envp[i] + 5, ':');
	if (pipex->paths_temp == NULL)
		wenting_wrong(error_msg("Error spliting path", 9), pipex, 2);
	i = 0;
	while (pipex->paths_temp[i])
		i++;
	pipex->paths = malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (pipex->paths_temp[++i])
		pipex->paths[i] = ft_strjoin(pipex->paths_temp[i], "/");
	pipex->paths[i] = NULL;
	i = 0;
	while (pipex->paths_temp[i])
	{
		free(pipex->paths_temp[i]);
		i++;
	}
	free(pipex->paths_temp);
}
