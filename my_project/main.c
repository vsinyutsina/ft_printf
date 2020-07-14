#include "ft_printf.h"

int     ft_printf(const char *format, ...)
{
    int len;
    char    result_string;


    result_string = ft_sprintf(format);
    len = ft_strlen(result_string);
    ft_putstr(resultstring);

    return(len);
}