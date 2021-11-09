#include "ft_ping.h"

void	error_usage(void)
{
	printf("Usage: ft_ping [-v verbose] [-h help] {destination}\n");
	exit(EXIT_FAILURE);
}

void	error_option(int pre, char *option)
{
	printf("ft_ping: invalid option %.*s '%c'\n\n", pre + 1, option, option[pre]);
	error_usage();
}

void	error_malloc()
{
	printf("Critical error memory\n");
	exit(EXIT_FAILURE);
}

void	error_destination_name(t_handle *handle)
{
	printf("ft_ping: %s: Temporary failure in name resolution\n", handle->destination);
	exit(EXIT_FAILURE);
}

void	error_socket(void)
{
	printf("ft_ping: Cannot create the socket!\n");
	exit(EXIT_FAILURE);
}

void	error_socketopt(void)
{
	printf("ft_ping: Cannot set option for socket!\n");
	exit(EXIT_FAILURE);
}

void	error_getaddrinfo(void)
{
	printf("getaddrinfo : ERROR\n");
	exit(EXIT_FAILURE);
}

void	error_inet_ntop(void)
{
	printf("inet_ntop : ERROR\n");
	exit(EXIT_FAILURE);
}

void	error_hostname_cannot_reach(t_handle *handle)
{
	printf("ft_ping : %s : No address associated with hostname\n", handle->destination);
	error_usage();
}

void	error_reverse_dns(void)
{
	printf("Could not resolve reverse lookup of hostname !\n");
	exit(EXIT_FAILURE);
}

