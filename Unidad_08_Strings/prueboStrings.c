#include <ctype.h>
#include <stdio.h>
#include <string.h>

int
main ()
{
  char cadena[20];
  printf ("\nIngrese una cadena: ");
  // scanf("%s", cadena);
  fgets (cadena, 20, stdin);
  int i = 0;
  while (cadena[i] != '\0')
    {
      if (cadena[i] == '\n')
        cadena[i] = '\0';
      else
        i++;
    }
  printf ("%s\n", cadena);
  puts (cadena);

  char nombre[8] = "Marcela";
  puts (nombre);

  return 0;
}
