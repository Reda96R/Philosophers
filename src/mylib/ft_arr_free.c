/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:29:26 by rerayyad          #+#    #+#             */
/*   Updated: 2023/06/13 12:29:28 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/mylib.h"

void  ft_arr_free(char **arr)
{
  int i;

  i = 0;
  while (arr[i])
    free(arr[i++]);
  free(arr);
}