#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include "monty.h"
/**
 * main - entry point
 * @argc: arg count
 * @argv: arg vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
        FILE *file = fopen(argv[1], "r");
        stack_t *stack = NULL;
        char *line = NULL;
        size_t len = 0;
        ssize_t read;
        unsigned int line_number = 0;
        char *opcode, *argument;
        if (argc != 2)
        {
                fprintf(stderr, "USAGE: monty file\n");
                exit(EXIT_FAILURE);
        }
        if (file == NULL)
        {
                fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
                exit(EXIT_FAILURE);
        }
        while ((read = getline(&line, &len, file)) != -1)
        {
                line_number++;
                opcode = strtok(line, " \t\n");
                if (opcode == NULL || opcode[0] == '#')
                        continue;
                if (strcmp(opcode, "push") == 0)
                {
                        argument = strtok(NULL, " \t\n");
                        if (argument == NULL)
                        {
                                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                                free(line);
                                fclose(file);
                                free_stack(stack);
                                exit(EXIT_FAILURE);
                        }
                        push(&stack, atoi(argument));
                }
                else
                        execute_opcode(&stack, opcode, line_number, line);
        }
        free(line);
        fclose(file);
        free_stack(stack);
        return (0);
}
