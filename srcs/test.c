#include "ft_ping.h"

void			print_handle(t_handle *handle)
{
	printf("/********************************\\\n");
	printf("|           TEST HANDLE          |\n");
	printf("\\********************************/\n\n");
	printf("handle->argc = %d\n", handle->argc);
	printf("handle->argv = \n");
	for (int i = 0; i < handle->argc; i++)
		printf("%d) %s\n", i, handle->argv[i]);
	if (handle->option.verbose == true)
		printf("handle->vervose = TRUE\n");
	else
		printf("handle->vervose = FALSE\n");
	if (handle->option.help == true)
		printf("handle->help = TRUE\n");
	else
		printf("handle->help = FALSE\n");
	printf("handle->destination = %s\n", handle->destination);
	printf("handle->ip = %s\n", handle->ip);
	printf("handle->reverse_dns = %s\n", handle->reverse_dns);
	if (g_loop == true)
		printf("g_loop = true\n");
	else
		printf("g_loop = false\n");
	printf("handle->socket->fd = %d\n", handle->socket_fd);
}
