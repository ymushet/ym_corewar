#ifndef COREWAR_H
#define COREWAR_H
# include "./libft/libft.h"
# include "op.h"
# include "global.h"
//# include "./visualization/visualization.h"
# define HEX 16

void			ft_init_global(void);
void			ft_parse_args(int argc, char **argv);
void			ft_error(char *str);
unsigned char	**ft_create_map(t_player *player, int n);
t_process		*ft_create_proceses(t_player *player);
void			ft_kill_processes(t_process **head);
void			ft_free_player(t_player **player);
t_player		*ft_read_from_core(int fd, unsigned int n);
int				ft_read_instructions(int fd, t_player *player);
int 			ft_read_comment(int fd, t_player *player);
int 			ft_read_magic(int fd, t_player *player);
int 			ft_read_program_name(int fd, t_player *player);
int 			ft_read_program_size(int fd, t_player *player);
int 			ft_read_instructions(int fd, t_player *player);

#endif