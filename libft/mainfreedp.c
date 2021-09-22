#include "./include/libft.h"

int main()
{
	char **splited;
	char **splited2;
	const char *tosplit = "Esta cadena es para splitear";
	const char *tosplit2 = "Esta otra cadena también es para splitear";
	int i = 0;

	splited 	= ft_split(tosplit, ' ');
	splited2	= ft_split(tosplit2, ' ');
	printf("Las cadenas spliteadas son:\n");
	for (i = 0; splited[i] != NULL; i++)
	{
		printf("%s\n", splited[i]);
	}
	printf("\n");
	for (i = 0; splited2[i] != NULL; i++)
	{
		printf("%s\n", splited2[i]);
	}
	ft_freedp(2, &splited, &splited2);
	if (splited != NULL)
	{
		printf("Splited no es nulo\n");
		prnitf("Que vale splited[0]? : %s\n", splited[0]);
	}
	printf("\nYa he hecho free\n");
}