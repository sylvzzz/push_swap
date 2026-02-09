#include "ft_printf.h" 
#include <limits.h>

int main()
{
     char *pointer = "Memory adress";
     char u = 42;
     int i_str = printf("%s\n", pointer);
     int i_chr = printf("%c\n", 'C');
     int i_inti = printf("%i\n", i_chr);
     int i_intd = printf("%d\n", i_chr);
     int i_ptr = printf("%p\n", pointer);
     int i_intu = printf("%u\n", u);
     int i_udx = printf("%x\n", pointer);
     int i_udxm = printf("%X\n", pointer);
     int i_pct = printf("%%\n", '%');

     printf("String: %s Return value: %i\n\n", pointer, i_str);
     printf("Char: %c Return value: %i\n\n", 'C', i_chr);
     printf("Pointer %p Return value: %i\n\n", pointer, i_ptr);
     printf("Integer D: %d Return value: %i\n\n", i_intd, i_intd);
     printf("Integer I: %i Return value: %i\n\n", i_inti, i_inti);
     printf("Unsigned: %u Return value: %i\n\n", u, i_intu);
     printf("Hexadecimal: %x Return value: %i\n\n", pointer, i_udx);
     printf("Hexadecimal Uppercase %X Return value: %i\n\n", pointer,i_udxm);
     printf("%% Return value: %i\n\n", '%', i_pct);
     printf("abc%\n");
}