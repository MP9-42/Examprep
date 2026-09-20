#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int picoshell(char **cmds[])
{
	int prev_fd = -1;
	int exit_code = 0;
	int i = 0;
	int fd[2];
	int status;
	pid_t pid;

	if  (!cmds)
		return(1);
	while (cmds[i])
	{
		if (cmds[i + 1] && pipe(fd) == -1)
		{
			if (prev_fd != -1)
				close(prev_fd);
			return(1);
		}
		pid = fork();
		if (pid == -1)
		{
			if (prev_fd != -1)
				close(prev_fd);
			if (cmds[i + 1])
			{
				close(fd[0]);
				close(fd[1]);
			}
			return(1);
		}
		if (pid == 0)
		{
			if (cmds[i + 1])
			{
				dup2(fd[1], 1);
				close(fd[0]);
				close(fd[1]);
			}
			if (prev_fd != -1)
			{
				dup2(prev_fd, 0);
				close(prev_fd);
			}
			if (!cmds[i][0])
				exit(1);
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		if (prev_fd != -1)
			close(prev_fd);
		if (cmds[i + 1])
		{
			close(fd[1]);
			prev_fd = fd[0];
		}
		i++;
	}
	while (wait(&status) != -1)
	{
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			exit_code = 1;
		if (WIFSIGNALED(status))
			exit_code = 1;
	}
	return(exit_code);
}

int main(int argc, char **argv)
{
	int  cmds_size = 1;
	for (int i = 1; i < argc; i++)
		if (!strcmp(argv[i], "|"))
			cmds_size++;
	char ***cmds = calloc(cmds_size + 1, sizeof(char **));
	if (!cmds)
	{
		dprintf(2, "Malloc error: %m\n");
		return(1);
	}
	cmds[0] = argv + 1;
	int cmds_i = 1;
	for(int i = 1; i < argc; i++)
	{
		if (!strcmp(argv[i], "|"))
		{
			cmds[cmds_i] = argv + i + 1;
			argv[i] = NULL;
			cmds_i++;
		}
	}
	int ret = picoshell(cmds);
	if (ret)
		perror("picoshell");
	free(cmds);
	return(ret);
}