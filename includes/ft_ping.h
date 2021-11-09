#ifndef FT_PING_H
#define FT_PING_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

#define PING_PKT_SIZE 64

typedef enum {false, true} bool;

typedef struct			s_option
{
	bool		verbose;
	bool		help;
}				t_option;

typedef struct 			s_handle
{
	int			argc;
	int			socket_fd;
	char			*ip;
	char 			**argv;
	char			*destination;
	char			*reverse_dns;
	struct sockaddr_in	ip4;
	struct addrinfo		*res;
	t_option		option;
}				t_handle;

typedef struct			s_ping_pkt
{
	struct icmphdr		hdr;
	char			msg[PING_PKT_SIZE - sizeof(struct icmphdr)];
}				t_ping_pkt;

extern bool g_loop;

/*\
 *		Test functions
\*/

void		print_handle(t_handle *handle);

/*\
 *		Tools functions
\*/

int		ft_strlen(const char *str);
char		ft_strchr(const char *str, char to_find);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *s1, void *s2, size_t n);
void		StopTheCount(int wech);

/*\
 *		Init functions
\*/

/*\
 *		Parsing functions
\*/

void		parsing(t_handle *handle);

/*\
 *		Loop functions
\*/

void		loop_ping(t_handle *handle);
unsigned short	calc_checksum(void *b, int len);

/*\
 *		Error functions
\*/

void		error_usage(void);
void		error_option(int pre, char *option);
void		error_malloc(void);
void		error_destination_name(t_handle *handle);
void		error_socket(void);
void		error_socketopt(void);
void		error_getaddrinfo(void);
void		error_inet_ntop(void);
void		error_hostname_cannot_reach(t_handle *handle);
void		error_reverse_dns(void);

#endif
