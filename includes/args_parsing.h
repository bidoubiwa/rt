/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 21:18:49 by toliver           #+#    #+#             */
/*   Updated: 2019/01/10 12:49:53 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_PARSING_H
# define ARGS_PARSING_H

# define SHORT_FLAGS "d"

typedef enum		e_verbose_mode
{
	NO_VERBOSE,
	ARGS_PARSING,
	INIT,
	PARSING,
	SETTINGS,
	RUNNING,
	PRINTING,
	LOOP,
	ALL_VERBOSE,
	MAX_VERBOSE_MODE,
}					t_verbose_mode;

typedef struct		s_args
{
	int				verbose_mode;
	int				renderer_mode;
	int				print_mode;
	int				debug_mode;
	char			**files;
}					t_args;


/*
** ARGS PARSING
*/

t_args				*args_parsing(int ac, char**av);
t_args				*args_init(void);

void				verbose_args(t_args *args);
void				print_renderer_mode(int mode);
void				print_print_mode(int mode);
void				print_verbose_mode(int mode);
void				print_debug_mode(int mode);
void				print_args_files(char**files);

/*
** USAGE FUNCTIONS
*/

void				print_usage(void);
void				print_print_usage(void);
void				print_verbose_usage(void);
void				print_renderer_usage(void);

/*
** PARSING FUNCTIONS
*/

void				parse_flags_check(t_args *args);
void				parse_arguments(int ac, char **av, t_args *args);
void				parse_smallflag(char *flagvalue, t_args *args);
void				parse_bigflag(char *flagvalue, t_args *args);
void				parse_bigflag_given_value(char *flagvalue, t_args *args);
void				parse_bigflag_default_value(char *flagvalue, t_args *args);
void				parse_verbose_mode(char *flagvalue, t_args *args);
void				parse_render_mode(char *flagvalue, t_args *args);
void				parse_renderer_mode(char *flagvalue, t_args *args);
void				parse_print_mode(char *flagvalue, t_args *args);

#endif
