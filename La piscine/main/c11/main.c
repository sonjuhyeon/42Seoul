#include <stdio.h>
#include <stdlib.h>
#include "./ex00/ft_foreach.c"
#include "./ex01/ft_map.c"
#include "./ex02/ft_any.c"
#include "./ex03/ft_count_if.c"
#include "./ex04/ft_is_sort.c"
#include "./ex06/ft_sort_string_tab.c"
#include "./ex07/ft_advanced_sort_string_tab.c"

// ex00
void print_int(int a)
{
	printf("%d ",a);
}

// ex01
int	plus_3(int a)
{
	return (a + 3);
}

// ex02, ex03
int	only_digit(char *str)
{
	while (*str)
	{
		if (!('0' <= *str && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

// ex04
int return_min(int a, int b)
{
	return (a - b);
}

int decending_cmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			break;
		str1++;
		str2++;
	}
	return (*str2 - *str1);
}

int main()
{
	{
		printf("--ex00--\n");
		int arr[10] = {1, 2, 9, 8, 3, 4, 6, 5, 0, 0};
		for(int i=0;i<10;i++)
			printf("%d ", arr[i]);
		printf(": ");
		ft_foreach(arr, 10, &print_int);
		printf("\n");
	}
	{
		printf("\n--ex01--\n");
		int arr[10] = {1, 2, 9, 8, 3, 4, 6, 5, 0, 4};
		for(int i=0;i<10;i++)
			printf("%d ", arr[i]);
		printf(": ");
		int *return_arr = ft_map(arr, 10, &plus_3);
		for(int i=0;i<10;i++)
			printf("%d ", return_arr[i]);
		free(return_arr);
		printf("\n");
	}
	{
		printf("\n--ex02--\n");
		char *strs[5];
		strs[0] = " 01823948\t";
		strs[1] = "abeemkdAS";
		strs[2] = "102984";
		strs[3] = "123asf";
		strs[4] = 0;
		printf("1 : %d\n", ft_any(strs, &only_digit));
		strs[2] = "[]po[]";
		printf("0 : %d\n", ft_any(strs, &only_digit));
	}
	{
		printf("\n--ex03--\n");
		char *strs[5];
		strs[0] = " 01823948\t";
		strs[1] = "abeemkdAS";
		strs[2] = "102984";
		strs[3] = "123";
		strs[4] = "12annbkm12";
		printf("2 : %d\n", ft_count_if(strs, 5,  &only_digit));
		strs[2] = "[]po[]";
		printf("1 : %d\n", ft_count_if(strs, 5, &only_digit));
	}
	{
		printf("\n--ex04--\n");
		int arr1[10] = {1, 2, 9, 8, 3, 4, 6, 5, 10, 11};
		for(int i=0;i<10;i++)
			printf("%d ", arr1[i]);
		printf(": %d\n", ft_is_sort(arr1, 10, &return_min));
		int arr2[10] = {-10, 2, 3, 4, 5, 6, 7, 8, 10, 112};
		for(int i=0;i<10;i++)
			printf("%d ", arr2[i]);
		printf(": %d\n", ft_is_sort(arr2, 10, &return_min));
		int arr3[10] = {11, 9, 6, 3, 1, 0, -1, -13, -14, -15};
		for(int i=0;i<10;i++)
			printf("%d ", arr3[i]);
		printf(": %d\n", ft_is_sort(arr3, 10, &return_min));
		int arr4[10] = {11, 9, 6, 8, 1, 0, -1, -13, -14, -15};
		for(int i=0;i<10;i++)
			printf("%d ", arr4[i]);
		printf(": %d\n", ft_is_sort(arr4, 10, &return_min));
	}
	{
		printf("\n--ex06--\n");
		char *strs[8];
		strs[0] = "3s!!ZSDFAA~~mlkjs11";
		strs[1] = "ASss";
		strs[2] = "~9~~mlkjsyou";
		strs[3] = "!!09~~mlkjsyou";
		strs[4] = "mlAABkjs";
		strs[5] = "";
		strs[6] = "A z ~ ~";
		strs[7] = 0;
		printf("\nBefore sort\n");
		for(int i=0;i<7;i++)
			printf("%s\n",strs[i]);
		ft_sort_string_tab(strs);
		printf("\nAfter sort\n");
		for(int i=0;i<7;i++)
			printf("%s\n",strs[i]);
	}
	{
		printf("\n--ex07--\n");
		char *strs[8];
		strs[0] = "3bhhiu92809~~mlkjs";
		strs[1] = "ASss";
		strs[2] = "~9~~mlkjsyou";
		strs[3] = "!!09~~mlkjsyou";
		strs[4] = "mlAABkjs";
		strs[5] = "";
		strs[6] = "  zz~~";
		strs[7] = 0;
		printf("\nBefore decending sort\n");
		for(int i=0;i<7;i++)
			printf("%s\n",strs[i]);
		ft_advanced_sort_string_tab(strs, &decending_cmp);
		printf("\nAfter decending sort\n");
		for(int i=0;i<7;i++)
			printf("%s\n",strs[i]);
	}
}
