#include <stdio.h>
#include <string.h>

void print_pos(char* pre, char* em) {
  if (em[0] == '\0') {
    return;
  }

  char root = pre[0];

  int i;
  for (i = 0; em[i] != root; i++);

  em[i] = '\0';

  print_pos(pre+1, em);
  print_pos(pre+i+1,em+i+1);

  printf("%c", root);
}

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; t++) {
    int N;
    scanf("%d", &N);

    char pre[100];
    char em[100];

    scanf(" %s %s", pre, em);

    print_pos(pre, em);
    printf("\n");
  }

  return 0;
}