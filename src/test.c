/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:28:08 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/05/13 18:40:04 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*get_path(char **env)
{
	char	*paths;
	int		counter;

	paths = NULL;
	counter = 0;
	while (env[counter])
	{
		if (ft_strncmp(ft_substr(env[counter], 0, 4), "PATH", 4) == 0)
		{
			paths = env[counter];
			break;
		}
		counter++;
	}
	if (paths == NULL)
		return ("Error");
	else
	{
		paths = ft_substr(paths, 5, ft_strlen(paths));
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

int main(int argc, char const *argv[], char **envp)
{
	(void)argc;
	(void)argv;

	printf("%s\n", get_path(envp));
	return 0;
}



// int main(int argc, char** argv)
// {
// 	int	fd[2];
	
// 	if (pipe(fd) == -1)
// 		return 1;
	
// 	int	pid1 = fork();
// 	if (pid1 < 0)
// 		return 2;
// 	if (pid1 == 0)
// 	{
// 		dup2(fd[1], STDOUT_FILENO);
// 		close(fd[1]);
// 		close(fd[0]);
// 		execlp("ping", "ping", "-c", "5", "google.com", NULL);
// 	}

// 	int pid2 = fork();

// 	if (pid2 < 0)
// 		return 3;
// 	if (pid2 == 0)
// 	{
// 		dup2(fd[0], STDIN_FILENO);
// 		close(fd[0]);
// 		close(fd[1]);
// 		execlp("grep", "grep", "bytes", NULL);
// 	}

// 	close(fd[0]);
// 	close(fd[1]);

// 	waitpid(pid1, NULL, 0);
// 	waitpid(pid2, NULL, 0);
// }
