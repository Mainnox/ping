#include "ft_ping.h"

bool g_loop = true;

static void		check_root(void)
{
	uid_t		uid;

	uid = getuid();
	if (uid != 0)
	{
		printf("ft_ping need to be run on sudo mode for raw socket !\n");
		exit(0);
	}
}

static t_handle	init_handle(int argc, char **argv)
{
	t_handle handle;

	handle.argc = argc;
	handle.argv = argv;
	handle.socket_fd = 0;
	handle.destination = NULL;
	handle.option.verbose = false;
	handle.option.help = false;
	handle.reverse_dns = NULL;
	handle.ip = malloc(sizeof(INET_ADDRSTRLEN));
	if (!handle.ip)
		error_malloc();
	ft_bzero(handle.ip, INET_ADDRSTRLEN);
	return (handle);
}

int		main(int argc, char **argv)
{
	t_handle handle;

	if (argc == 1)
		error_usage();
	//check_root();
	handle = init_handle(argc, argv);
	parsing(&handle);
	signal(SIGINT, StopTheCount);
	loop_ping(&handle);
	print_handle(&handle);
	free(handle.ip);
	free(handle.reverse_dns);
	freeaddrinfo(handle.res);
	return (0);
}
