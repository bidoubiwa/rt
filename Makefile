# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toliver <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/20 19:50:33 by toliver           #+#    #+#              #
#    Updated: 2019/01/11 19:17:22 by cvermand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rt

LIBS = ./libs/libft/libft.a \
	   ./libs/libftg/libftg.a \
	   ./libs/ft_printf/libftprintf.a \

INCLUDES = -I includes/ -I ./libs/libft/includes/ -I ./libs/libftg/includes/ -I ./libs/ft_printf/includes/ -I ./SDL2.framework/Versions/A/Headers/

LIBG = ./SDL2.framework/Versions/A/SDL2 

LIBGFLAGS = -F ./ -framework SDL2

FLAGS = -Wall -Wextra -Werror -Ofast

OBJS = $(addprefix objs/, $(addsuffix .o, \
		$(addprefix core/, \
			main \
			errors \
			$(addprefix editor/, \
				$(addprefix init/, \
					init \
					) \
				$(addprefix settings/, \
					settings \
					) \
				$(addprefix running/, \
					running \
					) \
				$(addprefix quit/, \
					quit \
					) \
				launch_editor \
				) \
			) \
		$(addprefix args_parsing/, \
			args_parsing \
			parse_args \
			usage \
			big_flag \
			small_flag \
			parse_mode \
			$(addprefix verbose/, \
				verbose_args \
				verbose_args_mode_bool \
				verbose_args_mode_multi \
				verbose_args_files \
			) \
		) \
		$(addprefix init/, \
			init \
			$(addprefix verbose/, \
			verbose_env \
			)\
		) \
	$(addprefix parsing/, \
		parsing \
		$(addprefix json_parser/, \
			array_recursive \
			elem_struct_functions \
			free_structure \
			json_parser \
			json_errors \
			json_utils \
			print_elem_architecture \
			recognize_number \
			recognize_string \
			recognize_bool \
			recognize_null \
			recognize_array \
			recognize_object \
			object_recursive \
			recognize_type \
			recognize_key \
			singleton \
		) \
		$(addprefix rt_parsing/, \
			color_utils \
			defaults \
			init_object \
			key_utils \
			key_types_utils \
			key_types_number \
			malloc_structures \
			parse_arithmetic_values \
			parse_cameras \
			parse_colors \
			parse_light \
			parse_object \
			parse_objects \
			parse_object_direction \
			parse_object_direction_extension \
			parse_scene \
			parse_world_coord \
			parse_vectors \
			parsing \
			required \
		) \
		$(addprefix verbose/, \
			verbose_arithmetic_values \
			verbose_parsing \
			verbose_parsing_loops \
			verbose_parsing_printing \
		) \
	) \
	$(addprefix settings/, \
		settings \
		ray \
		renderer_init \
		$(addprefix verbose/, \
			verbose_settings \
		) \
	) \
		$(addprefix tools/, \
			math_tools \
			general_tools \
			vector \
			$(addprefix colors_handling/, \
				colors_init \
				rgb_functions \
				) \
			) \
		\
		)) 


HEADERS = includes/rt.h \
		  includes/rt_structs.h \
		  includes/rt_color_structs.h \
		  includes/rt_obj_structs.h \
		  includes/rt_ray_structs.h \
		  includes/rt_material_structs.h \
		  includes/json_parser.h \
		  includes/json_parser_errors.h \
		  includes/libft_errors.h \
		  includes/rt_errors.h \
		  includes/editor.h \
		  includes/editor_struct.h \
		  includes/rt_required_information.h \

all: $(NAME)

$(NAME): objs $(OBJS) $(HEADERS) 

	@printf "\033[92m\033[1:32mCompiling -------------> \033[91m$(NAME)\033[0m:\033[0m%-16s\033[32m[✔]\033[0m\n"
	@make -C ./libs/libft
	@make -C ./libs/libftg
	@make -C ./libs/ft_printf
	@gcc -o $(NAME) $(FLAGS) $(LIBS) $(LIBG) $(LIBGFLAGS) $(OBJS) $(INCLUDES)

	
objs/%.o: srcs/%.c
	@printf  "\033[1:92mCompiling $(NAME)\033[0m %-31s\033[32m[$<]\033[0m\n" ""
	@gcc -o $@ -c $< $(FLAGS) $(INCLUDES)
	@printf "\033[A\033[2K"

objs:
	@mkdir -p objs/core/editor/init
	@mkdir objs/core/editor/settings
	@mkdir objs/core/editor/running
	@mkdir objs/core/editor/quit
	@mkdir -p objs/settings/verbose
	@mkdir -p objs/args_parsing/verbose
	@mkdir -p objs/init/verbose
	@mkdir -p objs/parsing/verbose
	@mkdir -p objs/parsing/rt_parsing
	@mkdir -p objs/parsing/json_parser
	@mkdir -p objs/tools/colors_handling

clean:
#	@	make -C ./libs/libft clean
#	@	make -C ./libs/libftg clean
#	@	make -C ./libs/ft_printf clean
	@printf  "\033[1:32mCleaning object files -> \033[91m$(NAME)\033[0m\033[1:32m:\033[0m%-16s\033[32m[✔]\033[0m\n"
	@rm -rf objs

fclean: clean
	@printf  "\033[1:32mCleaning binary -------> \033[91m$(NAME)\033[0m\033[1:32m:\033[0m%-16s\033[32m[✔]\033[0m\n"
	@	rm -f $(NAME)
	@	rm -f $(MLX)
#	@	make -C ./libs/libft fclean
#	@	make -C ./libs/libftg fclean
#	@	make -C ./libs/ft_printf fclean

re:
	@$(MAKE) fclean
	@$(MAKE)
#	@	make -C ./libs/libft re
#	@	make -C ./libs/libftg re
#	@	make -C ./libs/ft_printf re
