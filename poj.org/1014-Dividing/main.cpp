#include <cstdio>
int main() {
  int marbles[7];
  int collectionInd = 0;
  while (scanf("%d %d %d %d %d %d", marbles + 1, marbles + 2, marbles + 3,
               marbles + 4, marbles + 5, marbles + 6),
         collectionInd++,
         marbles[1] != 0 || marbles[2] != 0 || marbles[3] != 0 ||
             marbles[4] != 0 || marbles[5] != 0) {
    int sum = 0;
    bool flag = false;
    for (int i = 1; i < 7; i++) {
      if (marbles[i] > 6) {
        if (marbles[i] % 2)
          marbles[i] = 5;
        else
          marbles[i] = 6;
      }
      sum += i * marbles[i];
    }
    if (sum % 2 == 0) {
      int avg = sum / 2;
      bool exist[64] = {false};
      exist[0] = true;
      for (int i = 1; i < 7; i++) {
        int used[64] = {0};
        for (int j = i; j <= avg; j++)
          if ((!exist[j]) && exist[j - i] && used[j - i] + 1 <= marbles[i])
            exist[j] = true, used[j] = used[j - i] + 1;
      }
      flag = exist[avg];
    }
    printf("Collection #%d:\n", collectionInd);
    if (flag)
      printf("Can be divided.\n\n");
    else
      printf("Can't be divided.\n\n");
  }
  return 0;
}
