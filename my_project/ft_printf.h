#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct      s_specificators
{
    int flag_hash;
    int flag_minus;
    int flag_plus;
    int flag_space;
    int flag_zero;
    int width;
    int precision;
}