#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void CheckElf(unsigned char *e_ident);
void PrintMagic(unsigned char *e_ident);
void PrintClass(unsigned char *e_ident);
void PrintData(unsigned char *e_ident);
void PrintVersion(unsigned char *e_ident);
void PrintABI(unsigned char *e_ident);
void PrintOSABI(unsigned char *e_ident);
void PrintType(unsigned int e_type, unsigned char *e_ident);
void PrintEntry(unsigned long int e_entry, unsigned char *e_ident);
void CloseElf(int elf);
/**
 * CheckElf - Checks if a file is an ELF file.
 *
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 *
 */
void CheckElf(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
				e_ident[index] != 'E' &&
				e_ident[index] != 'L' &&
				e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * PrintMagic - Prints the magic numbers of an ELF header.
 *
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 *
 */
void PrintMagic(unsigned char *e_ident)
{
	int index;

	printf("  Magic:   ");
	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);
		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * PrintClass - Prints the class of an ELF header.
 *
 * @e_ident: A pointer to an array containing the ELF class.
 *
 */
void PrintClass(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * PrintData - Prints the data of an ELF header.
 *
 * @e_ident: A pointer to an array containing the ELF class.
 *
 */
void PrintData(unsigned char *e_ident)
{
