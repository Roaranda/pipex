#include "./include/libft.h"

int main(int argc, char *argv[], char *envp[])
{
	char *var_name;
	char *var_value;
	
	if (argc < 2)
		printf("Se necesitan argumentos\n");
	var_name = argv[1];
	var_value = ft_getenv(envp, var_name);
	printf("La variable %s tiene el valor %s\n", var_name, var_value);
	return 1;
}