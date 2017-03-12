#include <cstdio>
using namespace std;
int main() {
  long long factor[50];
  char res[130];
  long integer;
  int lo_dot;
  char s[6];
  int n;
  int i, j;
  while (scanf("%s %d", s, &n) != EOF) {
    for (i = 0; i < 5; i++)
      if (s[i] == '.') {
        lo_dot = i;
        for (j = i; j < 5; j++) s[j] = s[j + 1];
        s[j] = '\0';
        break;
      }
    sscanf(s, "%ld", &integer);
    for (i = 1; i < n; i++) factor[i] = 0;
    factor[0] = integer;
    for (i = 1; i < n; i++) {
      for (j = 0; j < n; j++) factor[j] = factor[j] * integer;
      for (j = 0; j < n; j++) {
        factor[j + 1] += factor[j] / (long long)100000;
        factor[j] = factor[j] % (long long)100000;
      }
    }
    for (i = 0; i < n; i++) sprintf(res + i * 5, "%.5lld", factor[n - 1 - i]);
    for (i = 0; i < n * lo_dot; i++)
      if (res[i] != '0') break;
    for (; i < n * lo_dot; i++) printf("%c", res[i]);
    for (j = n * 5 - 1; j >= n * lo_dot; j--)
      if (res[j] != '0') break;
    if (j > n * lo_dot) printf(".");
    for (; i <= j; i++) printf("%c", res[i]);
    printf("\n");
  }
  return 0;
}
