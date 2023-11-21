/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoreir <namoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:19:28 by namoreir          #+#    #+#             */
/*   Updated: 2023/11/20 12:34:12 by namoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
// perror
# include <stdio.h>
# include <errno.h>
// strerror
# include <string.h>
// exit
# include <stdlib.h>
//open close read write access dup dup2 execve fork pipe
# include <unistd.h>
// open access
# include <fcntl.h>
//fork wait
# include <sys/types.h>
// wait
# include <sys/wait.h>
// libft
# include "../../libft/libft.h"

# define ACCESS_OK 0
# define ACCESS_KO 1

typedef struct s_pipex	t_pipex;
struct					s_pipex
{
	int		nb_cmd;
	int		nb_cmd_curr;
	int		fd_inf;
	int		fd_outf;
	int		ac;
	int		*fd;
	char	**av;
	char	**paths;
	char	**paths_temp;
	char	**envp;
	char	**cmd;
	pid_t	pid;
	pid_t	pid_2;
};

void	open_file(t_pipex *pipex);
void	check_cmd(t_pipex *pipex);
void	get_path(t_pipex *pipex);
void	wenting_wrong(int error, t_pipex *pipex, int flag);
int		error_msg(char *str1, int error);
void	get_cmd(t_pipex *pipex);
void	create_child(t_pipex *pipex);
void	ft_free(t_pipex *pipex);

#endif