/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:20:13 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/05/18 17:58:04 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char const *argv[], char **envp)
{
	int	f1;
	int	f2;
	(void)argc;
	f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);

	if (f1 < 0 || f2 < 0)
		return (-2);
	printf("%i\n", pipex(f1, f2, argv, envp));
	return 0;
}
