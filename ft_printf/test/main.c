/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:31:55 by ciclo             #+#    #+#             */
/*   Updated: 2022/10/14 13:38:01 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"

void	test_porcent(void)
{
	int	as = printf("\n{%%}");
	int	sd = ft_printf("{%%}\n");

	if (as == sd)
	{
		ft_printf("\nOK\n");
		//ft_printf("\n{--%s},{%s}\n", as, sd);
	}
	else
		printf("KO\n");
}

void	test_c(void)
{
	printf("\ntest_c\n\n");
	int z = ft_printf("\nft_printf => {%c}, {%c},{%c},{%c},{%c},{%c}\n", 'z', 'a', 'b', 'c', 'd', 'e');
	int x = printf("\nprintf::: => {%c}, {%c},{%c},{%c},{%c},{%c}\n", 'z', 'a', 'b', 'c', 'd', 'e');

	if (z == x)
	{
		printf("\nOK\n");
		printf("\n{%d} {%d}", z, x);
	}
	else
	{
		printf("\nKO");
		printf("\n{%d} {%d}", z, x);
	}
}

void	test_s(void)
{
	int	str = printf("printf   => {%s},{%s},{%s},{%s},{%s},{%s} \n", "hola", "adiofdsfdsfdss", "holdfa", "adios", "hfdsfdsfola", "afdsfsddios");
	int	rts = ft_printf("ft_printf:=>{%s},{%s},{%s},{%s},{%s},{%s} \n", "hola", "adiofdsfdsfdss", "holdfa", "adios", "hfdsfdsfola", "afdsfsddios");

	if (str == rts)
	{
		printf("\n\nOK\n\n");
		printf("%d %d", str, rts);
	}
	else
	{
		printf("\nKO\n");
		printf("\n%d %d", str, rts);
	}
}

void	test_d_i(void)
{
	printf("\ntest_d_i\n\n");
	printf("d\n");
	int a = ft_printf("{%d}, {%d}, {%d}, {%d}, {%d}\n\n",INT_MAX, INT_MIN, 0, 42, -42);
	int b = printf("{%d}, {%d}, {%d}, {%d}, {%d}\n\n",INT_MAX, INT_MIN, 0, 42, -42);
	printf("\ni\n");
	int c = ft_printf("{%i}, {%i}, {%i}, {%i}, {%i}, {%i}\n",INT_MIN, 343, INT_MAX, 0, -42, 42);
	int d = printf("{%i}, {%i}, {%i}, {%i}, {%i}, {%i}\n",INT_MIN, 343, INT_MAX, 0, -42, 42);

// // int maximum = 2147483647;
	//printf("\nft_printf: d => %d Y   i => %i test del minimo ye lmaximo de un int\n");
	if (a == b)
	{
		ft_printf("\nft_printf: => {%d} printf => {%d} \n", a, b);
		printf("\nOK\n");
	}
	else
	{
		ft_printf("\nft_printf: => {%d} printf => {%d} \n", a, b);
		printf("\nKO\n");
	}
// int minimum = -2147483648;
	if (c == d)
	{
		ft_printf("\nft_printf: => {%d} printf => {%d} \n", c, d);
		printf("\nOK\n");
	}
	else
	{
		ft_printf("\nft_printf: => {%d} printf => {%d} \n", c, d);
		ft_printf("\nKO\n");
	}
}

/// @brief
/// @param
/// @return
int main(void)
{
	char *num = "-97";
	// test para decimal base 10 y entero base 10
	//test_porcent();
	ft_printf("\n----------------------------------------------\n");
	ft_printf("\n");
	//test_c();
	ft_printf("\n");
	//test_d_i();
	//test_s();
	ft_printf("{%x}, {%x}\n", num, -97);// hexadecimal solo es con numeros  xd
	//printf("{%x}, {%x}\n", num, -97);
	printf("\n--------------------------\n");
/*	printf(">%d<", ft_printf("%X\n", num));
	printf("\n--------------------------\n");
	printf("{%d}", printf("%X\n", num));
	printf("\n------------------------\n");
	printf("result: %d\n", ft_printf("{%p}\n", num));
	printf("result: %d\n", printf("{%p}\n", num));
 ft_printf("ft_printf:=>{%s},{%s},{%s},{%s},{%s},{%s} \n", "hola", "adiofdsfdsfdss", "holdfa", "adios", "hfdsfdsfola", "afdsfsddios");

	return (0);
*/
	//int 32 = printf("--------------------%p\n", num);
	if (printf("--------------------{%p}\n", num) == ft_printf("--------------------{%p}\n", num))
	{
		printf("\n----->OK<-----\n");
	}
	else
	{
		printf("\nKO");
		printf("\n{%d} {%d}", 33, 33);
	}
	ft_printf("--------------------%p\n", num);

}
 // si no son iguales retornamos el numero de caracteres que se han impreso en la salida estandar y el numero de caracteres que se han impreso en la salida estandar de la funcion original
