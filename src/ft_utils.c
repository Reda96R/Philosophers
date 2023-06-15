#include "includes/philo.h"

void  ft_errors_buster(int err_id)
{
  printf("/033[0;31m");
  if (err_id == 1)
    printf("Input error:\n\tusage: ./philo [nb_of_philos] [time_to_die] [time_to_eat]\
     [time_to_sleep] [nb_of_eats]*\n*optional\n");
  else if (err_id == 2)
    printf("Error: invalid number of philosophers.\n must be between 1 and 200");
  else if (err_id == 3)
      printf("Error: argument is less or equal to 0\n");
  exit (0);
}

void ft_args_checker(int ac, char *av[])
{
  int i;
  int n;

  i = 0;
  if (ac < 5 || ac > 6)
    ft_errors_buster(1);
  while (av[i])
  {
    // if(!ft_atoi(av[i]))
      //check if the number is between INT_MAX and INT_MIN
    if (n > 200 && i == 1)
      ft_errors_buster(2);
    if (n <= 0)
      ft_errors_buster(3);
  }
}
