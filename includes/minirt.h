#ifndef MINIRT_H

# define MINIRT_H

# define SPHERE "sp"
# define PLANE "pl"
# define SQUARE "sq"
# define CYLINDER "cy"
# define TRIANGLE "tr"
# define EPSILON 1e-6
# define DIFFUSE 0.9
# define SPECULAR 0.9
# define SHININESS 150.
# define CAMERA_STEP_SIZE 0.83
# define BMP_FILE_HEADER_SIZE 14
# define BMP_INFO_HEADER_SIZE 40

# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include "../jwolflib/includes/libft.h"
# include "../jwolflib/includes/printf.h"
# include "../jwolflib/includes/get_next_line.h"

# ifdef BONUS
#  include <pthread.h>
# endif

# ifdef Linux
#  define ESC 65307
#  include "../mlx/mlx-linux/mlx.h"

typedef enum 	e_key
{
	MOVE_UP = 32,
	FOV_LEFT = 97,
	FOV_RIGHT = 100,
	CAM_NEXT,
	CAM_PREV = 113,
	FOV_DOWN = 115,
	FOV_UP = 119,
	MOVE_LEFT = 65361,
	MOVE_FORWARD,
	MOVE_RIGHT,
	MOVE_BACK,
	LMOVE_DOWN = 65505,
	RMOVE_DOWN,
}				t_key;

# elif Darwin
#  define ESC 53
#  include "../mlx/mlx-ios/mlx.h"

typedef enum 	e_key
{
	FOV_LEFT = 0,
	FOV_RIGHT,
	FOV_DOWN,
	CAM_PREV = 12,
	FOV_UP,
	CAM_NEXT,
	MOVE_UP = 49,
	MOVE_LEFT = 123,
	MOVE_RIGHT,
	MOVE_BACK,
	MOVE_FORWARD,
	LMOVE_DOWN = 257,
	RMOVE_DOWN,
}				t_key;

# endif

typedef struct		s_data
{
	void			*img;
	char			*addr;
	int				bpp;
	int				ll;
	int				endian;
	float			img_ratio;
	float			fov_scale;
}					t_data;

/*
** {ERRORS}
*/

typedef struct		s_error
{
	const char 		*msg;
	int 			no;
}					t_error;

/*
** {COLORS}
*/

typedef struct		s_rgb
{
	float			r;
	float			g;
	float			b;
}					t_rgb;

/*
** {VECTOR}
*/

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
	double			w;			// default 0
}					t_vector;

/*
** {POINT}
*/

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
	double			w;		// default 1
}					t_point;

/*
** {MATRIX}
*/

typedef struct		s_matrix
{
	double			**m;
	int				size;
}					t_matrix;

/*
** {OBJECTS}
*/

typedef struct		s_light
{
	t_point			origin;
	double			ratio;
	t_rgb			color;
	struct s_light	*next;
}					t_light;

typedef struct		s_camera
{
	t_point			origin;
	t_vector		orient;
	int				fov;
	struct s_camera	*prev;
	struct s_camera *next;
}					t_camera;

typedef struct		s_sphere
{
	t_point			origin;
	double			dia;
	t_rgb			color;
	t_matrix		transform;
}					t_sphere;

typedef struct		s_plane
{
	t_point			origin;
	t_vector		orient;
	t_rgb			color;
}					t_plane;

typedef struct		s_cylinder
{
	t_point			origin;
	t_vector		orient;
	double			dia;
	double			height;
	t_rgb			color;
	t_matrix		transform;
}					t_cylinder;

typedef struct		s_triangle
{
	t_vector		v1;
	t_vector		v2;
	t_vector		v3;
	t_rgb			color;
}					t_triangle;

typedef struct		s_square
{
	t_point			origin;
	t_vector		orient;
	double			side;
	t_rgb			color;
	t_triangle		tr[2];
}					t_square;

typedef union		u_elem
{
	t_sphere		sp;
	t_plane			pl;
	t_square		sq;
	t_cylinder		cy;
	t_triangle		tr;
}					t_elem;

typedef	struct		s_object
{
	const char 		*type;
	t_elem			elem;
	struct s_object	*next;
}					t_object;

/*
** {RAYS}
*/

typedef struct 		s_hit
{
	double 			t[2];
	t_point			p;
	t_point			ptrans;
	t_vector		normal;
	t_vector		reflect;
	const char		*type;
	t_object		*obj;
	struct s_hit	*next;
}					t_hit;

typedef struct		s_ray
{
	t_vector		dir;
	t_vector		dirtrans;
	t_point			origin;
	t_rgb			color;
	t_hit			*hits;
}					t_ray;

/*
** {SCENE}
*/

typedef	struct		s_scene
{
	int				rt_file_fd;
	void			*mlx;
	void			*mlx_window;
	t_data 			mlx_image;
	t_data 			mlx_image_buf;
	int				height;
	int				width;
	float			a_ratio;
	t_rgb			a_color;
	t_light			*lights;
	t_camera 		*current_cam;
	t_camera		*cams;
	t_object		*objects;
}					t_scene;

#ifdef BONUS

typedef struct		s_thread_data
{
	t_scene			*scene;
	t_data			*img;
	int				ymin;
	int				ymax;
}					t_thread_data;

#endif

/*
** {Function pointers}
*/

typedef struct		s_tracer
{
	char 			*type;
	int 			(*func)(t_scene *sc, t_object *obj, t_ray *ray);
}					t_tracer;

typedef struct		s_handle_key
{
	int 			key;
	int 			(*func)(t_scene* scene, t_key key);
}					t_handle_key;

typedef struct		s_parser
{
	char			*type;
	t_error 		(*func)(t_scene *scene, const char **line);
}					t_parser;

t_error				error_new(const char *msg, int no);
void				exit_minirt(t_error err, t_scene *scene);

t_rgb				rgb_new(float r, float g, float b);
t_rgb				rgb_add(t_rgb *c1, t_rgb *c2);
t_rgb				rgb_add_multiple(t_rgb *rgb, int size);
t_rgb				rgb_sub(t_rgb *v1, t_rgb *v2);
t_rgb				rgb_scale(t_rgb c, double n);
t_rgb				rgb_blend(t_rgb *c1, t_rgb *c2);
bool				rgb_is_valid(t_rgb rgb);

t_vector			vector_new(double x, double y, double z);
t_vector			vector_new_one(double xyz);
t_vector			vector_add_vector(t_vector *v1, t_vector *v2);
t_vector			vector_sub_vector(t_vector *v1, t_vector *v2);
t_vector			vector_negate(t_vector v);
t_vector			vector_scale(t_vector v, double n);
double				vector_mag(t_vector v);
t_vector			vector_norm(t_vector v);
double				vector_dot(t_vector *v1, t_vector *v2);
t_vector			vector_cross(t_vector *v1, t_vector *v2);
bool				vector_is_valid_norm(t_vector *v);
t_vector			vector_reflect(t_vector *in, t_vector *normal);

t_point				point_new(double x, double y, double z);
t_point				point_new_one(double xyz);
double				point_dist(t_point *p1, t_point *p2);
t_point				point_add_vector(t_point *p, t_vector *v);
t_vector			point_sub_point(t_point *p1, t_point *p2);
t_point				point_sub_vector(t_point *p, t_vector *v);

t_ray				ray_new(t_point origin, t_vector dir, t_hit *next);
void				ray_destroy(t_ray *ray);
t_rgb				ray_light(t_ray *ray, t_light *light);
t_point				ray_at(t_ray *r, double t);
bool				ray_intersect_sp(t_ray *r, t_sphere sp, t_hit *hit);
bool				ray_intersect_pl(t_ray *r, t_plane pl, t_hit *hit);
bool				ray_intersect_tr(t_ray *r, t_triangle tr, t_hit *hit);
bool				ray_intersect_sq(t_ray *r, t_square sq, t_hit *hit);
bool				ray_intersect_cy(t_ray *r, t_cylinder cy, t_hit *hit);
t_hit				*ray_hit_new_default(void);
t_ray				ray_transform(t_ray *ray, t_matrix m);
void				ray_hit_lst_add(t_ray *ray, t_hit *hit);

t_matrix			matrix_free(t_matrix m);
void				matrix_free_mult(t_matrix *m, int amount);
t_matrix			matrix_alloc(int size);
t_matrix			matrix_transpose(t_matrix m);
t_matrix			matrix_inverse(t_matrix m);
t_matrix			matrix_get_sub(t_matrix m, int row, int col);
double				matrix_get_cof(t_matrix m, int row, int col, t_error *err);
double				matrix_get_cof_sign(int row, int col);
double				matrix_get_det(t_matrix m, t_error *err);
bool				matrix_eq(t_matrix m1, t_matrix m2);
t_matrix			matrix_multiply(t_matrix m1, t_matrix m2);
t_point				matrix_apply_p(t_matrix m, t_point *p);
t_vector			matrix_apply_v(t_matrix m, t_vector *v);
t_matrix			matrix_get_id(void);
t_matrix 			matrix_get_trans(t_point p);
t_matrix			matrix_get_rot(t_point a, t_point b, t_point c);
t_matrix			matrix_get_rot_x(double rad);
t_matrix			matrix_get_rot_y(double rad);
t_matrix			matrix_get_rot_z(double rad);
t_matrix 			matrix_get_scale(t_vector scale);
t_matrix			matrix_get_view(t_point from, t_point to);

t_error				object_free(t_error err, t_object *obj);
t_object			*object_new(const char *type);
bool				object_loop(t_scene *scene, t_ray *ray, bool stop_early);
bool				object_is_planar(const char *type);
void 				lst_add_back_obj(t_scene *scene, t_object *new);
void				lst_add_back_c(t_scene *scene, t_camera *new);
void				lst_add_back_l(t_scene *scene, t_light *new);
void 				lst_clear_obj(t_object *start);
void 				lst_clear_c(t_camera **start);
void 				lst_clear_l(t_light **start);

t_scene 			*scene_init(const char *file);
t_scene 			*scene_new(void);

t_vector			parse_util_vector(const char *str, t_error *err, bool norm);
t_point				parse_util_point(const char *str, t_error *err, bool norm);
t_rgb				parse_util_color(const char *str, t_error *err);
bool				str_is_numeric(const char *str, bool isdecimal);
int 				str_arr_len(const char **arr);
void				str_arr_free(const char **str);
void 				mlx_set_pixel(t_data *data, int x, int y, t_rgb color);

void				parse_rt(t_scene *scene, char *line);
t_error 			parse_rt_ru(t_scene *scene, const char **line);
t_error 			parse_rt_au(t_scene *scene, const char **line);
t_error 			parse_rt_c(t_scene *scene, const char **line);
t_error 			parse_rt_l(t_scene *scene, const char **line);
t_error				parse_rt_sp(t_scene *scene, const char **line);
t_error				parse_rt_pl(t_scene *scene, const char **line);
t_error				parse_rt_sq(t_scene *scene, const char **line);
t_error				parse_rt_cy(t_scene *scene, const char **line);
t_error				parse_rt_tr(t_scene *scene, const char **line);

void 				render_loop(t_scene *scene, bool save);
void				render_scene(t_scene *scene, t_data *img);
void				render_scene_bmp(t_scene *scene);
t_rgb				render_scene_pixel(t_scene *scene, t_data *img, int x, int y);
int 				render_scene_pixel_sp(t_scene *sc, t_object *obj, t_ray *ray);
int 				render_scene_pixel_pl(t_scene *sc, t_object *obj, t_ray *ray);
int 				render_scene_pixel_tr(t_scene *sc, t_object *obj, t_ray *ray);
int 				render_scene_pixel_sq(t_scene *sc, t_object *obj, t_ray *ray);
int 				render_scene_pixel_cy(t_scene *sc, t_object *obj, t_ray *ray);

/*
** KEYS
** 0			a				change orientation left
** 13			w				change orientation up
** 2			d				change orientation right
** 1			s				change orientation down
** 53			ESC				destroy_notify
** 12			Q				previous camera
** 14			E				next camera
** 49			Space			move up				(y + 1)
** 257 | 258	Shift			move down			(y - 1)
** 123			left arrow		move left			(x - 1)
** 124			top arrow		move forward		(z + 1)
** 125			right arrow		move right			(x + 1)
** 126			down arrow		move back			(z - 1)
**
*/

int 				handle_key_hook_move(t_scene *scene, t_key key);
int 				handle_key_hook_fov(t_scene *scene, t_key key);
int 				handle_key_hook_cam(t_scene *scene, t_key key);
int 				handle_key_hook(int keycode, t_scene *scene);
int 				destroy_notify(t_scene *scene);

#endif
