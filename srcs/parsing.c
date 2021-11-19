#include "ft_ping.h"

static void	parsing_option(char *option, t_handle *handle)
{
	char	check = 1;

	for (int i = 1; option[i]; i++)
	{
		if (check)
		{
			if (option[i] == 'v')
				handle->option.verbose = true;
			else if (option[i] == 'h')
				handle->option.help = true;
			else
			{
				free(handle->ip);
				error_option(i, option);
			}
		}
	}
}

static void	check_destination(t_handle *handle)
{
	int			status;
	struct addrinfo		hints;
	struct addrinfo		*tmp_ptr;
	const char 		*check_ip = NULL;
	struct sockaddr_in	ip4;

	if (!ft_strchr(handle->destination, '.'))
	{
		free(handle->ip);
		error_destination_name(handle);
	}
	bzero(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	if (status = getaddrinfo(handle->destination, NULL,
			&hints, &handle->res)!= 0)
	{
		free(handle->ip);
		error_getaddrinfo();
	}
	tmp_ptr = handle->res;
	while (tmp_ptr)
	{
		if (tmp_ptr->ai_family == AF_INET)
		{
			ft_memcpy(&(handle->ip4), (void *)tmp_ptr->ai_addr,
						sizeof(struct sockaddr_in));
			check_ip = inet_ntop(AF_INET, &(handle->ip4.sin_addr),
									handle->ip, INET_ADDRSTRLEN);
			handle->res = tmp_ptr;
			break ;
		}
		if (tmp_ptr->ai_family == AF_INET6)
			printf("Ipv6 quoi que ca veuille dire !\n");
		tmp_ptr = tmp_ptr->ai_next;
	}
	if (!check_ip)
	{
		freeaddrinfo(handle->res);
		free(handle->ip);
		error_inet_ntop();
	}
	if (!tmp_ptr)
	{
		freeaddrinfo(handle->res);
		free(handle->ip);
		error_hostname_cannot_reach(handle);
	}
}

void		set_reverse_dns(t_handle *handle)
{
	char buf[NI_MAXHOST];
	print_handle(handle);
	if (getnameinfo((struct sockaddr *)&(handle->ip4),
			sizeof(struct sockaddr_in), buf, sizeof(buf), NULL, 0, NI_NAMEREQD))
	{
		freeaddrinfo(handle->res);
		free(handle->ip);
		error_reverse_dns();
	}
	handle->reverse_dns = (char *)malloc((ft_strlen(buf) + 1) * sizeof(char));
	ft_memcpy((void *)handle->reverse_dns, (void *)buf, ft_strlen(buf) + 1);
}

void		parsing(t_handle *handle)
{
	for (int i = 1; i < handle->argc; i++)
	{
		if (handle->argv[i][0] == '-')
			parsing_option(handle->argv[i], handle);
		else
			handle->destination = handle->argv[i];
	}
	check_destination(handle);
	set_reverse_dns(handle);
	print_handle(handle);
}
