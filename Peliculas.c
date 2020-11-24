#include "Peliculas.h"

int main(int argc, char *argv[])
{
  if(argc == 2 && (strcmp(argv[1],"-new"))==0)
  {  
    vista_Menu(1);
  }

  else
  {
    vista_Menu(0);
  }

  return 0;
}
