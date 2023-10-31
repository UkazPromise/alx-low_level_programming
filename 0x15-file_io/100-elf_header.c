#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <sys/types.h>

/**
 * exit_with_message - Print an error message and exit with a specific code.
 * @code: The exit code.
 * @format: The format string for the error message.
 * @...: Additional arguments for the error message.
 */
void exit_with_message(int code, const char *format, ...)
{
    va_list args;

    va_start(args, format);
    dprintf(2, format, args);
    va_end(args);
    exit(code);
}

/**
 * read_elf_header - Read and display the ELF header information.
 * @file_descriptor: The file descriptor of the ELF file.
 */
void read_elf_header(int file_descriptor)
{
    Elf64_Ehdr elf_header;
    ssize_t bytes_read;

    lseek(file_descriptor, 0, SEEK_SET);

    bytes_read = read(file_descriptor, &elf_header, sizeof(Elf64_Ehdr));

    if (bytes_read == -1 || bytes_read != sizeof(Elf64_Ehdr))
        exit_with_message(98, "Error: Can't read from file\n");

    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++)
        printf("%02x%s", elf_header.e_ident[i], (i < EI_NIDENT - 1) ? " " : "\n");
    printf("  Class:                             %s\n", (elf_header.e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "ELF64");
    printf("  Data:                              %s\n", (elf_header.e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" : "2's complement, big endian");
    printf("  Version:                           %d (current)\n", elf_header.e_ident[EI_VERSION]);
    printf("  OS/ABI:                            %s\n", (elf_header.e_ident[EI_OSABI] == ELFOSABI_SYSV) ? "UNIX - System V" : "UNIX - Other");
    printf("  ABI Version:                       %d\n", elf_header.e_ident[EI_ABIVERSION]);
    printf("  Type:                              %s\n", (elf_header.e_type == ET_EXEC) ? "EXEC (Executable file)" : "Other");
    printf("  Entry point address:               0x%lx\n", (unsigned long)elf_header.e_entry);
}

/**
 * main - Display ELF header information.
 * @ac: The number of arguments.
 * @av: An array of argument strings.
 * Return: 0 on success, or the corresponding error code.
 */
int main(int ac, char **av)
{
    int file_descriptor;

    if (ac != 2)
        exit_with_message(98, "Usage: elf_header elf_filename\n");

    file_descriptor = open(av[1], O_RDONLY);
    if (file_descriptor == -1)
        exit_with_message(98, "Error: Can't read from file %s\n", av[1]);

    read_elf_header(file_descriptor);

    if (close(file_descriptor) == -1)
        exit_with_message(98, "Error: Can't close fd %d\n", file_descriptor);

    return (0);
}
