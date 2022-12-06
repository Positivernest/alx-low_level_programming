#include <elf.h>
#include "main.h"
#define REV(n) ((n << 24) | (((n >> 16) << 24) >> 16) | \
(((n << 16) >> 24) << 16) | (n >> 24))
/**
 * verify- verify the file to check if is a ELF
 * @e_ident: the ELF struct
 * return: no return is a void func.
 */

void verify(unsigned char *e_ident)
{
if (*(e_ident) == 0x7f && *(e_ident + 1) == 'E' &&
*(e_ident + 2) == 'L' && *(e_ident + 3) == 'F')
{
printf("ELF Header:\n");
}
else
{
dprintf(STDERR_FILENO, "Error: this file not is a valid ELF\n");
exit(98);
}
}

/**
 * magic - print magic number
 * @e_ident: the ELF struct
 * return: no return is a void func.
 */

void magic(unsigned char *e_ident)
{
int i; /* the index to count the magic bytes */
int limit;

limit = EI_NIDENT - 1;
printf("  Magic:   ");
for (i = 0; i < limit; i++)
printf("%02x ", *(e_ident + i));
printf("%02x\n", *(e_ident + i));
}

/**
 * class - print the class of the ELF
 * @e_ident: the ELF struct
 * return: no return is a void func.
 */

void class(unsigned char *e_ident)
{
printf("  Class:                             ");
if (e_ident[EI_CLASS] == ELFCLASSNONE)
printf("This class is invalid\n");
else if (e_ident[EI_CLASS] == ELFCLASS32)
printf("ELF32\n");
else if (e_ident[EI_CLASS] == ELFCLASS64)
printf("ELF64\n");
else
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}

/**
 * data - print mthe type of data
 * @e_ident: the ELF struct
 * return: no return is a void func.
 */

void data(unsigned char *e_ident)
{
printf("  Data:                              ");
if (e_ident[EI_DATA] == ELFDATANONE)
printf("Unknown data format\n");
else if (e_ident[EI_DATA] == ELFDATA2LSB)
printf("2's complement, little endian\n");
else if (e_ident[EI_DATA] == ELFDATA2MSB)
printf("2's complement, big endian\n");
else
printf("<unknown: %x>\n", e_ident[EI_DATA]);

