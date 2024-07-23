#include "./ex00/ft_iterative_factorial.c"
#include "./ex01/ft_recursive_factorial.c"
#include "./ex02/ft_iterative_power.c"
#include "./ex03/ft_recursive_power.c"
#include "./ex04/ft_fibonacci.c"
#include "./ex05/ft_sqrt.c"
#include "./ex06/ft_is_prime.c"
#include "./ex07/ft_find_next_prime.c"
#include "./ex08/ft_ten_queens_puzzle.c"
#include <stdio.h>

int main(){
	{
		printf("----ex00----\n");
		printf("5! : %d\n", ft_iterative_factorial(5));
		printf("1! : %d\n", ft_iterative_factorial(1));
		printf("0! : %d\n", ft_iterative_factorial(0));
		printf("7! : %d\n", ft_iterative_factorial(7));
		printf("-1! : %d\n", ft_iterative_factorial(-1));
		printf("10000! : %d\n", ft_iterative_factorial(10000));
	}
	printf("\n");

	{
		printf("----ex01----\n");
		printf("5! : %d\n", ft_recursive_factorial(5));
		printf("1! : %d\n", ft_recursive_factorial(1));
		printf("0! : %d\n", ft_recursive_factorial(0));
		printf("7! : %d\n", ft_recursive_factorial(7));
		printf("-1! : %d\n", ft_recursive_factorial(-1));
		printf("10000! : %d\n", ft_recursive_factorial(10000));
	}
	printf("\n");


	{
		printf("----ex02----\n");
		printf("2^4 : %d\n", ft_iterative_power(2, 4));
		printf("1^0 : %d\n", ft_iterative_power(1, 0));
		printf("0^2 : %d\n", ft_iterative_power(0, 2));
		printf("-2^1 : %d\n", ft_iterative_power(-2, 1));
		printf("-4^2 : %d\n", ft_iterative_power(-4, 2));
		printf("5^-1 : %d\n", ft_iterative_power(5, -1));
	}
	printf("\n");


	{
		printf("----ex03----\n");
		printf("2^4 : %d\n", ft_recursive_power(2, 4));
		printf("1^0 : %d\n", ft_recursive_power(1, 0));
		printf("0^2 : %d\n", ft_recursive_power(0, 2));
		printf("-2^1 : %d\n", ft_recursive_power(-2, 1));
		printf("-4^2 : %d\n", ft_recursive_power(-4, 2));
		printf("5^-1 : %d\n", ft_recursive_power(5, -1));
	}
	printf("\n");


	{
		printf("----ex04----\n");
		printf("0 : %d\n", ft_fibonacci(0));
		printf("-1 : %d\n", ft_fibonacci(-4));
		printf("1 : %d\n", ft_fibonacci(1));
		printf("1 : %d\n", ft_fibonacci(2));
		printf("2 : %d\n", ft_fibonacci(3));
		printf("8 : %d\n", ft_fibonacci(6));
	}	
	printf("\n");


	{
		printf("----ex05----\n");
		printf("6 : %d\n", ft_sqrt(36));
		printf("0 : %d\n", ft_sqrt(0));
		printf("9 : %d\n", ft_sqrt(81));
		printf("0 : %d\n", ft_sqrt(-1));
		printf("0 : %d\n", ft_sqrt(99));
		printf("1 : %d\n", ft_sqrt(1));
		printf("0 : %d\n", ft_sqrt(2147483647));
		printf("46340 : %d\n", ft_sqrt(2147395600));
	}
	printf("\n");


	{
		printf("----ex06----\n");
		printf("0 : %d\n", ft_is_prime(36));
		printf("0 : %d\n", ft_is_prime(0));
		printf("0 : %d\n", ft_is_prime(1));
		printf("0 : %d\n", ft_is_prime(-1));
		printf("1 : %d\n", ft_is_prime(29));
		printf("1 : %d\n", ft_is_prime(2147483647));
	}	
	printf("\n");


	{
		printf("----ex07----\n");
		printf("2 : %d\n", ft_find_next_prime(-123));
		printf("7 : %d\n", ft_find_next_prime(6));
		printf("11 : %d\n", ft_find_next_prime(11));
		printf("2 : %d\n", ft_find_next_prime(0));
		printf("31 : %d\n", ft_find_next_prime(30));
		printf("97 : %d\n", ft_find_next_prime(90));
	}
	printf("\n");

	
	{
		printf("----ex08----\n");
		int answer = ft_ten_queens_puzzle();
		printf("724 : %d\n",answer);
	}
}
