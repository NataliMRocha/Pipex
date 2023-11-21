/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:16:52 by namoreir          #+#    #+#             */
/*   Updated: 2023/11/20 16:47:11 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	t_pipex	ft_init(void)
{
	t_pipex	pipex;

	pipex.nb_cmd = 0;
	pipex.nb_cmd_curr = 2;
	pipex.fd_inf = -1;
	pipex.fd_outf = -1;
	pipex.paths = NULL;
	pipex.paths_temp = NULL;
	pipex.ac = -1;
	pipex.av = NULL;
	pipex.envp = NULL;
	pipex.fd = NULL;
	pipex.cmd = NULL;
	return (pipex);
}

static	t_pipex	get_data(int argc, char *argv[], char *envp[], int *fd)
{
	t_pipex	pipex;

	pipex = ft_init();
	pipex.ac = argc;
	pipex.av = argv;
	pipex.envp = envp;
	pipex.nb_cmd = argc - 3;
	pipex.fd = fd;
	return (pipex);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;
	//fd 0 lê e fd 1 grava
	int		fd[2];

	if (argc != 5)
		wenting_wrong(error_msg("You need 4 arguments\n", 1), &pipex, 1);
	if (!envp)
		wenting_wrong(error_msg("Unexpected error\n", 2), &pipex, 1);
	if (pipe(fd) < 0)
		wenting_wrong(error_msg("Pipe error\n", 3), &pipex, 1);
	pipex = get_data(argc, argv, envp, fd);
	open_file(&pipex);
	get_path(&pipex);
	create_child(&pipex);
	close(fd[0]);
	close(fd[1]);
	waitpid(pipex.pid, NULL, 0);
	waitpid(pipex.pid_2, NULL, 0);
	ft_free(&pipex);
	close(pipex.fd_inf);
	close(pipex.fd_outf);
	return (EXIT_SUCCESS);
}
