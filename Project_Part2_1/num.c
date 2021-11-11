#include<stdio.h>
#include <string.h>
#include<assert.h>
#include<ctype.h>
#include <stdlib.h>

int main() {

  char str1[100], str2[10][50], temp, tem[50];
 // printf("First string\n");
  gets(str1);
  assert(strlen(str1) < 100);

  int j = 0;
  for (int i = 0; str1[i]; ++i) {
    if ((str1[i] >= 'A' && str1[i] <= 'Z')||(str1[i] >= 'a' && str1[i] <= 'z')) {
      str1[j] = str1[i];
      j++;
    }
  }
  str1[j] = '\0';

  puts(str1);
  fputc('\n', stdout);
//  printf("Words to sort\n");

	for(int i=0; i<10; ++i){
      scanf("%s[^\n]", str2[i]);
      for(int j = 0; j<strlen(str2[i]); ++j){
		assert(strlen(str1) < 100);
        if(!(isalpha(str2[i][j]))|| str2[i][j] == '\n'){
        return 0;
        }
      }
    }

  for (int i = 0; i < 9; ++i) {
    for (int j = i + 1; j < 10; ++j){
      if (strcmp(str2[i], str2[j]) > 0) {
        strcpy(tem, str2[i]);
        strcpy(str2[i], str2[j]);
        strcpy(str2[j], tem);
      }
    }
  }

  fputc('\n', stdout);
 // printf("Sorted:\n");
  for (int i = 0; i < 10; ++i) {
    puts(str2[i]);
  }
  return 0;
}
