#include "ft_printf.h" 
#include <limits.h>

int main()
{
     char *pointer = "Memory adress";
     char u = 42;
     int i_str = ft_printf("%s\n", pointer);
     int i_chr = ft_printf("%c\n", 'C');
     int i_inti = ft_printf("%i\n", i_chr);
     int i_intd = ft_printf("%d\n", i_chr);
     int i_ptr = ft_printf("%p\n", pointer);
     int i_intu = ft_printf("%u\n", u);
     int i_udx = ft_printf("%x\n", pointer);
     int i_udxm = ft_printf("%X\n", pointer);
     int i_pct = ft_printf("%%\n", '%');

     ft_printf("String: %s Return value: %i\n\n", pointer, i_str);
     ft_printf("Char: %c Return value: %i\n\n", 'C', i_chr);
     ft_printf("Pointer %p Return value: %i\n\n", pointer, i_ptr);
     ft_printf("Integer D: %d Return value: %i\n\n", i_intd, i_intd);
     ft_printf("Integer I: %i Return value: %i\n\n", i_inti, i_inti);
     ft_printf("Unsigned: %u Return value: %i\n\n", u, i_intu);
     ft_printf("Hexadecimal: %x Return value: %i\n\n", pointer, i_udx);
     ft_printf("Hexadecimal Uppercase %X Return value: %i\n\n", pointer,i_udxm);
     ft_printf("%% Return value: %i\n\n", '%', i_pct);
}