#include "Peliculas.h"
#include <math.h>

int main(int argc, char *argv[])
{
  srand(time(NULL));
  
  if(argc == 2 && (strcmp(argv[1],"-new"))==0)
  {  
    vista_Menu(1);
  }

  else if(argc == 1)
  {
    vista_Menu(0);
  }

  return 0;
}
