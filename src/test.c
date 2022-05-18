/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:28:08 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/05/18 17:57:44 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**get_path(char **env)
{
	char	*temp;
	char	**paths;
	int		counter;

	temp = NULL;
	counter = 0;
	while (env[counter])
	{
		if (ft_strncmp(ft_substr(env[counter], 0, 4), "PATH", 4) == 0)
		{
			temp = env[counter];
			break;
		}
		counter++;
	}
	if (temp == NULL)
		return (NULL);
	else
	{
		temp = ft_substr(temp, 5, ft_strlen(temp));
		paths = ft_split(temp, ':');
		free(temp);
		return (paths);
	}
}


void	print_big(char **big)
{
	int	counter;

	counter = 0;
	while (big[counter])
	{
		ft_printf("%s\n", big[counter]);
		counter++;
	}
}

int	pipex(int f1, int f2, const char** argv, char **envp)
{
	int		fd[2];
	char	**paths;
	int		counter;
	char	*cmd;

	paths = get_path(envp);
	counter = 0;
	
	if (pipe(fd) == -1)
		return 1;
	
	int	pid1 = fork();
	if (pid1 < 0)
		return 2;
	if (pid1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		dup2(f1, STDIN_FILENO);
		close(f1);
		close(fd[1]);
		close(fd[0]);
		while (paths[counter++])
		{
			cmd = ft_strjoin(paths[counter], argv[2]);
			execve(cmd, paths, envp);
			perror("Error");
			free(cmd);
		}
	}

	int pid2 = fork();
	counter = 0;

	if (pid2 < 0)
		return 3;
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(f2, STDOUT_FILENO);
		close(f2);
		close(fd[0]);
		close(fd[1]);
		while (paths[counter++])
		{
			cmd = ft_strjoin(paths[counter], argv[3]);
			execve(cmd, paths, envp);
			perror("Error");
			free(cmd);
		}
	}

	close(fd[0]);
	close(fd[1]);

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return 0;
}
