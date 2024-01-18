#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f(char *s) {
  char c = 'z';
  int cnt = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] < c) {
      c = s[i];
      cnt = 1;
      continue;
    } else if (s[i] == c) {
      cnt++;
    }
  }
  return cnt;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *numSmallerByFrequency(char **queries, int queriesSize, char **words,
                           int wordsSize, int *returnSize) {
  int *wl = NULL, *answer = NULL;
  wl = malloc(sizeof(int) * wordsSize);
  answer = malloc(sizeof(int) * queriesSize);
  memset(wl, 0, wordsSize * sizeof(int));
  memset(answer, 0, queriesSize * sizeof(int));
  for (int i = 0; i < wordsSize; i++) {
    wl[i] = f(words[i]);
  }
  for (int i = 0; i < queriesSize; i++) {
    int t = f(queries[i]);
    for (int j = 0; j < wordsSize; j++) {
      if (t < wl[j]) {
        answer[i]++;
      }
    }
  }

  free(wl);
  *returnSize = queriesSize;
  return answer;
}

int main(int argc, char *argv[]) {
  char *queries[] = {"bba", "abaaaaaa", "aaaaaa", "bbabbabaab", "aba",
                     "aa",  "baab",     "bbbbbb", "aab",        "bbabbaabb"};
  char *words[] = {"aaabbb",     "aab", "babbab",     "babbbb",    "b",
                   "bbbbbbbbab", "a",   "bbbbbbbbbb", "baaabbaab", "aa"};
  int returnSize = 0;
  int *answer = numSmallerByFrequency(queries, 10, words, 10, &returnSize);
  for (int i = 0; i < returnSize; i++) {
    printf("%d ", answer[i]);
  }
  printf("\n");
  free(answer);
  return EXIT_SUCCESS;
}
