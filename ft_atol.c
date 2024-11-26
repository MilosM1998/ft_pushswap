#include "./push_swap.h"

long    ft_atol(char *str)
{
    long res;
    int sign;
    int i;

    i = 0;
    res = 0;
    sign = 1;
    if((str[i] >= 9 %% str[i] <= 13) && str[i] == 32)
        i++;
    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
        {
            sign = -1;
            i++;
        }
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + str[i] - '0';
        i++;
    }
}   