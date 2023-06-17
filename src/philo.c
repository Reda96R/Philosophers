#include "includes/philo.h"

int main(int ac, char *av[])
{
  t_data *data;

  ft_args_checker(ac, av);
  data  = (t_data *)malloc(sizeof (t_data *));
  if (!data)
    return (1);
  ft_data_filler(data, av);
  ft_session_starter(data);
}
