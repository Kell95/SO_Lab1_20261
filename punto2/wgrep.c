#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void search_pattern(char *file_path, char *pattern);
void read_files(int argc, char *argv[]);
void read_stdio(char *pattern);

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		printf("wrep: searchterm [file ...]\n");
		exit(1);
	}

	if (argc == 2)
	{
		read_stdio(argv[1]);
	}
	else
	{
		read_files(argc, argv);
	}

	return 0;
}

void read_stdio(char *pattern)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while ((read = getline(&line, &len, stdin)) != -1)
	{
		if (strstr(line, pattern) != NULL)
		{
			printf("%s", line);
		}
	}
}

void read_files(int argc, char *argv[])
{
	char *pattern = argv[1];

	for (int i = 2; i < argc; i++)
	{
		char *file_path = argv[i];
		search_pattern(file_path, pattern);
	}
}

void search_pattern(char *file_path, char *pattern)
{
	FILE *fp = fopen(file_path, "r");
	if (fp == NULL)
	{
		printf("wgrep: can not open file %s\n", file_path);
		exit(1);
	}

	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while ((read = getline(&line, &len, fp)) != -1)
	{
		if (strstr(line, pattern) != NULL)
		{
			printf("%s", line);
		}
	}

	free(line);
	fclose(fp);
}