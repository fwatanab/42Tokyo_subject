#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("返り値→ %d\n", ft_printf("自作: %%入力なし\t"));
	printf("返り値→ %d\n\n", printf("本家: %%入力なし\t"));
	printf("返り値→ %d\n", ft_printf("自作: %%c→ %c\t%c\t%c\t%%%c%%\t", 'a', '1', '\0', 'a'));
	printf("返り値→ %d\n\n", printf("本家: %%c→ %c\t%c\t%c\t%%%c%%\t", 'a', '1', '\0', 'a'));
	printf("返り値→ %d\n", ft_printf("自作: %%s→ %s\t%s\t%s\t%%%s%%\t", "1234", "abcd", NULL, "1234"));
	printf("返り値→ %d\n\n", printf("本家: %%s→ %s\t%s\t%s\t%%%s%%\t", "1234", "abcd", NULL, "1234"));
	printf("返り値→ %d\n", ft_printf("自作: %%p→ %p\t%p\t%p\t%%%p%%\t", "1234", "abcd", NULL, "1234"));
	printf("返り値→ %d\n\n", printf("本家: %%p→ %p\t%p\t%p\t%%%p%%\t", "1234", "abcd", NULL, "1234"));
	printf("返り値→ %d\n", ft_printf("自作: %%d→ %d\t%d\t%d\t%%%d%%\t", 1234, -5678, 0, 1234));
	printf("返り値→ %d\n\n", printf("本家: %%d→ %d\t%d\t%d\t%%%d%%\t", 1234, -5678, 0, 1234));
	printf("返り値→ %d\n", ft_printf("自作: %%i→ %i\t%i\t%i\t%%%i%%\t", 1234, -5678, 0, 1234));
	printf("返り値→ %d\n\n", printf("本家: %%i→ %i\t%i\t%i\t%%%i%%\t", 1234, -5678, 0, 1234));
	printf("返り値→ %d\n", ft_printf("自作: %%x→ %x\t%x\t%x\t%%%x%%\t", 1234, -5678, 0, 1234));
	printf("返り値→ %d\n\n", printf("本家: %%x→ %x\t%x\t%x\t%%%x%%\t", 1234, -5678, 0, 1234));
	printf("返り値→ %d\n", ft_printf("自作: %%X→ %X\t%X\t%X\t%%%X%%\t", 1234, -5678, 0, 1234));
	printf("返り値→ %d\n\n", printf("本家: %%X→ %X\t%X\t%X\t%%%X%%\t", 1234, -5678, 0, 1234));

	system("leaks -q a.out");
	return (0);
}

// #include <libc.h>
// #include "ft_printf.h"

// int main()
// {
//     int i = 0;
//     char *s = (char *)calloc(1, (size_t)INT_MAX-1);
//     memset(s, 'a', (size_t)INT_MAX-1);
//     i = ft_printf("%s", s);
//     printf("\n%d\n", i);
//     return (0);
// }