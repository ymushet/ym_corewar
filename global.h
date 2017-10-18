#ifndef GLOBAL
#define GLOBAL
#include "corewar.h"

typedef struct                  s_process
{
	unsigned int                regs[REG_NUMER];   //регистры
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
	unsigned char		        magic[4];     //меджик намбер(любой .сor начинается с него)
	unsigned char				*prog_name;   //имя программы
	unsigned char		        prog_size[4]; //размер программы в одном инте
	unsigned char				*comment;     //комментарий
	unsigned int                number;       //номер игрока
	int                         player_size;  //размер инструкции
	unsigned char               *instructions;//интсрукции
	int                         mem_addr;	  //адрес начала инструкции в памяти игры
	struct s_player             *next;
}						        t_player;

typedef struct                  s_data
{
	int 						dump;
	int 						aff;
	int 						visual;
	int 						count_players;
	int                         nbr_live;
	int                         max_checks;
	int                         cycle;
	int                         last_live;
	int                         cycle2die;
	unsigned char               **map;
	t_player                    *player_g;
	t_process                   *process_g;
}                               t_data;

t_data g_dt;
#endif