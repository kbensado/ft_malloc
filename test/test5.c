#include "../includes/ft_malloc.h"
// #include <stdio.h>
// #include <stdlib.h>

// void	show_alloc_mem();

int main()
{
	malloc(1024);
	malloc(1024 * 32);
	malloc(1024 * 1024);
	malloc(1024 * 1024 * 16);
	malloc(1024 * 1024 * 128);
	show_alloc_mem();
	return (0);
}