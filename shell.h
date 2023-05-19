#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/*macros*/
#define INTERACTIVE 1
#define NON_INTERACTIVE 0
#define ERROR -1
extern char **environ;
/**
 * struct list_path - singly linked list
 * @path: string
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_path
{
	char *path;
	unsigned int len;
	struct list_path *next;
} list_path;

/**
 * struct built_in_t - Struct built_in_t
 *
 * @command: command string
 * @f: function
 */
typedef struct built_in_t
{
	char *command;
	void (*f)(char **v_line);
} built_in_t;

int _strcmp(char *s1, char *s2);
char *_getenv(const char *name);
int has_access(char *cmd);
void free_list(list_path *head);
int _strlen(char *s);
char *_strdup(char *str);
list_path *add_node(list_path **head, char *path);
list_path *set_all_paths_to_list();
size_t print_list(const list_path *p);
char **get_av_with_flags(char *line, int status);
unsigned int char_count(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

/*====================================================================================*/
void print_error(char *program_name , int counter,char *command);
void handle_comments(char *input);
//==
void handle_semicolons(char *line);
void execute_command_with_waitpid(char *path, char **av, char **env);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
//==
char *num_to_char(int num);
char *check_access(char *line_av_1, list_path *current);
void execute_command(char *path, char **av, char **env, int *status);
void print_env(char **line_vector);
char* get_process_id();
char* get_status(int n);
int is_built_in(char **line_vector);
void is_exit(char *line, char **line_vector, list_path *current);
char *get_command_from_file(char *file);
char *get_command_from_user(list_path *current);
int check_mode(int argc);
void check_file(char *file);
void free_vector(char **v);
#endif
