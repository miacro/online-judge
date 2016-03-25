#include <cstdio>
int coinsTrue[12];
int coins[6][13];
int weigh[3];
int n;
int abs(int a) { return a > 0 ? a : -a; }
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 12; j++) coinsTrue[j] = 0;
    for (int j = 0; j < 3; j++) {
      coins[j * 2][0] = 0;
      coins[j * 2 + 1][0] = 0;
      char ch;
      while (getchar() != '\n')
        ;
      while (ch = getchar(), ch != ' ')
        coins[j * 2][++(coins[j * 2][0])] = ch - 'A';
      while (ch = getchar(), ch != ' ')
        coins[j * 2 + 1][++(coins[j * 2 + 1][0])] = ch - 'A';
      ch = getchar();
      if (ch == 'e')
        weigh[j] = 1;
      else if (ch == 'u')
        weigh[j] = 2;
      else
        weigh[j] = 0;
    }
    for (int j = 0; j < 3; j++) {
      if (weigh[j] == 1) {
        for (int k = 0; k < coins[2 * j][0]; k++)
          coinsTrue[coins[2 * j][k + 1]] = 100;
        for (int k = 0; k < coins[2 * j + 1][0]; k++)
          coinsTrue[coins[2 * j + 1][k + 1]] = 100;
      } else if (weigh[j] == 0) {
        for (int k = 0; k < coins[2 * j][0]; k++)
          if (coinsTrue[coins[2 * j][k + 1]] != 100)
            coinsTrue[coins[2 * j][k + 1]]++;
        for (int k = 0; k < coins[2 * j + 1][0]; k++)
          if (coinsTrue[coins[2 * j + 1][k + 1]] != 100)
            coinsTrue[coins[2 * j + 1][k + 1]]--;
      } else {
        for (int k = 0; k < coins[2 * j][0]; k++)
          if (coinsTrue[coins[2 * j][k + 1]] != 100)
            coinsTrue[coins[2 * j][k + 1]]--;
        for (int k = 0; k < coins[2 * j + 1][0]; k++)
          if (coinsTrue[coins[2 * j + 1][k + 1]] != 100)
            coinsTrue[coins[2 * j + 1][k + 1]]++;
      }
    }
    int counterfeitCoin = 0;
    int value = 0;
    for (int j = 0; j < 12; j++)
      if (coinsTrue[j] != 100) {
        if (abs(coinsTrue[j]) > abs(value)) {
          counterfeitCoin = j;
          value = coinsTrue[j];
        }
      }
    if (value > 0)
      printf("%c is the counterfeit coin and it is light.\n",
             counterfeitCoin + 'A');
    else
      printf("%c is the counterfeit coin and it is heavy.\n",
             counterfeitCoin + 'A');
  }

  return 0;
}
