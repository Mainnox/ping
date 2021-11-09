#include "ft_ping.h"

void		loop_ping(t_handle *handle)
{
	int	ttl, check;
	struct	timeval time_out, time_start, time_end;

	ttl = 64;
	time_out.tv_sec = 1;
	time_out.tv_usec = 0;
	handle->socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (handle->socket_fd < 0)
	{
		free(handle->ip);
		free(handle->reverse_dns);
		freeaddrinfo(handle->res);
		error_socket();
	}
	if (setsockopt(handle->socket_fd, SOL_IP, IP_TTL, (const void *)&ttl,
				sizeof(ttl)) != 0)
	{
		free(handle->ip);
		free(handle->reverse_dns);
		freeaddrinfo(handle->res);
		close(handle->socket_fd);
		printf("Ttl cannot be set !\n");
		exit(EXIT_FAILURE);
	}
	if (setsockopt(handle->socket_fd, SOL_IP, SO_RCVTIMEO,
				(const char *)&time_out, sizeof(time_out)) != 0)
	{
		free(handle->ip);
		free(handle->reverse_dns);
		freeaddrinfo(handle->res);
		close(handle->socket_fd);
		printf("Time out cannot be set !\n");
		exit(EXIT_FAILURE);
	}
	while (g_loop)
	{
		check = 1;
		gettimeofday(&time_start, NULL);

		gettimeofday(&time_end, NULL);
	}
}
