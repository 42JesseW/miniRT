# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jevan-de <jevan-de@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/17 17:01:23 by jevan-de      #+#    #+#                  #
#    Updated: 2021/02/12 14:48:25 by jevan-de      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = 				miniRT
CFLAGS = 			-Wall -Wextra -Werror -g -fsanitize=address -fno-omit-frame-pointer
CLINKSIOS =			-lm -lpthread
CLINKSLINUX =		-lXext -lX11 -lm -lz -lpthread

MLXDIRMAIN = 		mlx
LIBFTDIR = 			jwolflib
LIBFTLIB = 			libft.a
SRCDIR = 			srcs
OBJDIR = 			obj

SRC =				main.c \
					render/render_scene_pixel.c \
					render/render_scene_bmp.c \
					render/render_scene_pixel_sp.c \
					render/render_scene_pixel_pl.c \
					render/render_scene_pixel_tr.c \
					render/render_scene_pixel_sq.c \
					render/render_scene_pixel_cy.c \
					render/render_loop.c \
					render/render_scene.c \
					vector/vector_scale.c \
					vector/vector_dot.c \
					vector/vector_mag.c \
					vector/vector_add_vector.c \
					vector/vector_negate.c \
					vector/vector_cross.c \
					vector/vector_is_valid_norm.c \
					vector/vector_new.c \
					vector/vector_new_one.c \
					vector/vector_sub_vector.c \
					vector/vector_norm.c \
					vector/vector_reflect.c \
					object/lst_clear_l.c \
					object/lst_clear_c.c \
					object/object_free.c \
					object/object_is_planar.c \
					object/lst_add_back_l.c \
					object/lst_add_back_obj.c \
					object/lst_add_back_c.c \
					object/object_new.c \
					object/lst_clear_obj.c \
					object/object_loop.c \
					point/point_sub_point.c \
					point/point_new.c \
					point/point_new_one.c \
					point/point_dist.c \
					point/point_sub_vector.c \
					point/point_add_vector.c \
					hook/destroy_notify.c \
					hook/handle_key_hook_cam.c \
					hook/handle_key_hook_move.c \
					hook/handle_key_hook.c \
					hook/handle_key_hook_fov.c \
					matrix/matrix_alloc.c \
					matrix/matrix_get_trans.c \
					matrix/matrix_multiply.c \
					matrix/matrix_get_det.c \
					matrix/matrix_get_scale.c \
					matrix/matrix_get_sub.c \
					matrix/matrix_get_view.c \
					matrix/matrix_free.c \
					matrix/matrix_free_mult.c \
					matrix/matrix_inverse.c \
					matrix/matrix_get_id.c \
					matrix/matrix_get_rot.c \
					matrix/matrix_get_cof.c \
					matrix/matrix_get_cof_sign.c \
					matrix/matrix_eq.c \
					matrix/matrix_apply.c \
					matrix/matrix_transpose.c \
					utils/parse_utils.c \
					utils/mlx_set_pixel.c \
					utils/str_arr_len.c \
					utils/str_is_numeric.c \
					utils/str_arr_free.c \
					parser/parse_rt_au.c \
					parser/parse_rt.c \
					parser/parse_rt_l.c \
					parser/parse_rt_sq.c \
					parser/parse_rt_sp.c \
					parser/parse_rt_pl.c \
					parser/parse_rt_tr.c \
					parser/parse_rt_c.c \
					parser/parse_rt_ru.c \
					parser/parse_rt_cy.c \
					scene/scene_new.c \
					scene/scene_init.c \
					ray/ray_new.c \
					ray/ray_destroy.c \
					ray/ray_light.c \
					ray/ray_intersect_sp.c \
					ray/ray_intersect_pl.c \
					ray/ray_intersect_tr.c \
					ray/ray_intersect_sq.c \
					ray/ray_intersect_cy.c \
					ray/ray_at.c \
					ray/ray_transform.c \
					ray/ray_hit_new_default.c \
					ray/ray_hit_lst_add.c \
					color/rgb_blend.c \
					color/rgb_add.c \
					color/rgb_add_multiple.c \
					color/rgb_new.c \
					color/rgb_scale.c \
					color/rgb_sub.c \
					color/rgb_is_valid.c \
					error/exit_minirt.c \
					error/error_new.c		

OBJ = 				$(addprefix $(OBJDIR)/$(SRCDIR)/, $(SRC:.c=.o))
LIBS =				$(addprefix -l, $(subst lib,,$(subst .a,,$(LIBFTLIB))) mlx)

UNAME_S =			$(shell uname -s)

ifeq ($(UNAME_S), Darwin)
	P = 			\x1b[35m
	B = 			\x1b[34m
	Y = 			\x1b[33m
	G = 			\x1b[32m
	R = 			\x1b[31m
	W = 			\x1b[0m
	MLXDIR =		$(MLXDIRMAIN)/mlx-ios
	CLINKS =		$(CLINKSIOS)
	MLXLIB = 		libmlx.dylib
else ifeq ($(UNAME_S), Linux)
	# Notes for MLX on linux
	#	* Make sure Xming server is running
	#	* Make sure following dependencies are installed
	#	xorg libxext-dev zlib1g-dev resolvconf
	#	* Make sure DISPLAY is set
	#	export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0.0

	P = 			\033[35m
	B = 			\033[34m
	Y = 			\033[33m
	G = 			\033[32m
	R = 			\033[31m
	W = 			\033[0m
	MLXDIR =		$(MLXDIRMAIN)/mlx-linux
	CLINKS =		$(CLINKSLINUX)
	MLXLIB = 		libmlx.a
endif

ifdef BONUS
	CFLAGS += -D BONUS
endif

INCLUDES =			$(addprefix -I, includes $(LIBFTDIR)/includes $(MLXDIR))

define ASCII
                                                                $R,----, 
          $W____                                                $R,/   .`| 
        $W,'  , `.                              $G,-.----.      $R,`   .'  : 
     $W,-+-,.' _ |  $Y,--,                 $B,--,   $G\    /  \   $R;    ;     / 
  $W,-+-. ;   , ||$Y,--.'|         $P,---, $B,--.'|   $G;   :    \\$R.'___,/    ,'  
 $W,--.'|'   |  ;|$Y|  |,      $P,-+-. /  |$B|  |,    $G|   | .\ :$R|    :     |   
$W|   |  ,', |  ':$Y`--'_     $P,--.'|'   |$B`--'_    $G.   : |: |$R;    |.';  ;   
$W|   | /  | |  ||,$Y' ,'|   $P|   |  ,"' |$B,' ,'|   $G|   |  \ :$R`----'  |  |   
$W'   | :  | :  |,$Y'  | |   $P|   | /  | |$B'  | |   $G|   : .  /    $R'   :  ;   
$W;   . |  ; |--' $Y|  | :   $P|   | |  | |$B|  | :   $G;   | |  \    $R|   |  '   
$W|   : |  | ,    $Y'  : |__ $P|   | |  |/ $B'  : |__ $G|   | ;\  \   $R'   :  |   
$W|   : '  |/     $Y|  | '.'|$P|   | |--'  $B|  | '.'|$G:   ' | \.'   $R;   |.'    
$W;   | |`-'      $Y;  :    ;$P|   |/      $B;  :    ;$G:   : :-'     $R'---'      
$W|   ;/          $Y|  ,   / $P'---'       $B|  ,   / $G|   |.'                  
$W'---'            $Y---`-'               $B---`-'  $G`---'                    
                                                                       
$W
endef
export ASCII

all: ascii $(NAME)

ascii:
	@echo "$$ASCII"

$(NAME): $(OBJ) $(LIBFTLIB) $(MLXLIB)
	@echo "\n$(G)Building miniRT program$(W)"
	$(CC) $(INCLUDES) $(CFLAGS) $(OBJ) -L. $(LIBS) -o $(NAME) $(CLINKS)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)/$(SRCDIR)/color \
			  $(OBJDIR)/$(SRCDIR)/error \
			  $(OBJDIR)/$(SRCDIR)/hook \
			  $(OBJDIR)/$(SRCDIR)/matrix \
			  $(OBJDIR)/$(SRCDIR)/object \
			  $(OBJDIR)/$(SRCDIR)/parser \
			  $(OBJDIR)/$(SRCDIR)/point \
			  $(OBJDIR)/$(SRCDIR)/ray \
			  $(OBJDIR)/$(SRCDIR)/render \
			  $(OBJDIR)/$(SRCDIR)/scene \
			  $(OBJDIR)/$(SRCDIR)/utils \
			  $(OBJDIR)/$(SRCDIR)/vector
	@echo "$(Y)Creating $@ out of $<$(W)"
	@$(CC) -D $(UNAME_S) -c $(CFLAGS) $(INCLUDES) -o $@ $<

$(LIBFTLIB):
	@echo "\n$(G)Making $(LIBFTLIB) static lib$(W)"
	@make --directory=$(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTLIB) .

$(MLXLIB):
	@echo "\n$(G)Making $(MLXLIB) lib$(W)"
    ifeq ($(UNAME_S), Darwin)
		@make --directory=$(MLXDIR)
		@cp $(MLXDIR)/$(MLXLIB) .
    else ifeq ($(UNAME_S), Linux)
		@cd $(MLXDIR) ; ./configure ; cd -
		@cp $(MLXDIR)/$(MLXLIB) .
    endif

clean:
	@echo "$(R)cleaning up obj files$(W)"
	@rm -rf $(OBJDIR)
	@make --directory=$(MLXDIR) clean
	@make --directory=$(LIBFTDIR) clean

fclean: clean
	@echo "$(R)cleaning up executable files$(W)"
	@rm -f $(NAME) $(MLXLIB) $(LIBFTLIB)
	@make --directory=$(LIBFTDIR) fclean

re: fclean $(NAME)

bonus:
	@echo "\n$(G)Building miniRT program with bonus$(W)"
	@$(MAKE) BONUS=1 all 
