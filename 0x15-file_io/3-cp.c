#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>

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
 * main - Copy the content of a file to another file.
 * @ac: The number of arguments.
 * @av: An array of argument strings.
 * Return: 0 on success, or the corresponding error code.
 */
int main(int ac, char **av)
{
    int from_fd, to_fd, bytes_read, bytes_written;
    char buffer[1024];

    if (ac != 3)
        exit_with_message(97, "Usage: cp file_from file_to\n");

    from_fd = open(av[1], O_RDONLY);
    if (from_fd == -1)
        exit_with_message(98, "Error: Can't read from file %s\n", av[1]);

    to_fd = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (to_fd == -1)
        exit_with_message(99, "Error: Can't write to file %s\n", av[2]);

    while ((bytes_read = read(from_fd, buffer, sizeof(buffer))) > 0)
    {
        bytes_written = write(to_fd, buffer, bytes_read);
        if (bytes_written == -1)
            exit_with_message(99, "Error: Can't write to file %s\n", av[2]);
    }

    if (bytes_read == -1)
        exit_with_message(98, "Error: Can't read from file %s\n", av[1]);

    if (close(from_fd) == -1)
        exit_with_message(100, "Error: Can't close fd %d\n", from_fd);
    if (close(to_fd) == -1)
        exit_with_message(100, "Error: Can't close fd %d\n", to_fd);

    return (0);
}
