#include <stdio.h>
  
int main()
{
  long long a, b;
  FILE *fin, *fout;
  fin = fopen("aplusbb.in", "r");
  fout = fopen("aplusbb.out", "w");
  scanf(fin, "%d%d", &a, &b);
  printf(fout, "%d", a + b * b);
  fclose(fin);
  fclose(fout);
  
  return 0;

}