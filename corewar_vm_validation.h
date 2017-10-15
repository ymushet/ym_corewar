//
// Created by Yehor Mushet on 10/10/17.
//

#ifndef COREWAR_WM_VALIDATION
#define COREWAR_WM_VALIDATION
# include "./libft/libft.h"
# include "./libft/libftprintf.h"
# include "op.h"
# define HEX 16

typedef struct                  s_process
{
	unsigned int                regs[16];   //регистры
	int                         cary;       //кеэри
	int                         mem_addres; //адрес в памяти(индекс в массиве где стоит каретка)
	int                         number;     //номер процесса (номер игрока от которого создали процесс)
	void                        (*func)();  //указатель на функцию (указатель на команду, которая исполняется)
	int                         exec_cycle; //цикл исполнения (сколько циклов осталось ждать до исполнения команды
	int                         dell;       //флаг удаления процесса. Если 1 то Килл!
	struct s_process            *next;
}                               t_process;

typedef struct 		    	    s_player
{
	unsigned char		        magic[4];     //меджик намбер( любой .сor начинается с него
	unsigned char				*prog_name;   //имя программы
	unsigned char		        prog_size[4]; //размер программы в одном инте
	unsigned char				*comment;     //комментарий
	unsigned int                number;       //номер игрока
	int                         player_size;  //размер инструкции
	unsigned char               *instructions;
	struct s_player             *next;
}						        t_player;

int                             ft_error(int code);
t_player                        *ft_malloc_player(unsigned int n);
t_player                        *ft_read_from_core(int fd, unsigned int n);
int                             ft_validate_magic(unsigned char *magic);
int                             ft_read_program_name(int fd, t_player *player);
int                             ft_read_instructions(int fd, t_player *player);
int                             ft_read_magic(int fd, t_player *player);
int                             ft_read_comment(int fd, t_player *player);
int                             ft_read_program_size(int fd, t_player *player);
t_process                       *ft_malloc_process(t_player *player);
t_process                       *ft_create_proceses(t_player *player);
void                            ft_add2head_process(t_process **head, t_process *add);
void                            ft_kill_processes(t_process **head);
char                            **ft_create_map(t_player *player, int n);
void                            ft_copy_com(char **map, t_player *player, int i);
int                             ft_create_int(unsigned char *magic);
void                            ft_free_player(t_player **player);

#endif