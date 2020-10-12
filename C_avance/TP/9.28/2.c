#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countWordsInString(char *string) {
  if (*string == '\0') return 0;
  int result = 1;
  while (*string)
    if (*string++ != ' ' && *string == ' ')
      result++;
  return result;
}

int countWords(char **wordArray) {
  int result;
  for (result = 0; *wordArray; wordArray++, result++);
  return result;
}

void destroyWordArray(char **wordArray) {
  while (*wordArray)
    free(*wordArray++);
  free(wordArray);
}

char **splitString(char *string) {
  int size;
  if (!(size = countWordsInString(string)))
    return NULL;
  char **wordArray = (char **)malloc((size + 1) * sizeof(char *));

  char *tempEnd = string;
  for (int i = 0; i < size; i++) {
    while ((*tempEnd) && (*tempEnd != ' ')) tempEnd++;
    int wordSize = tempEnd - string;
    wordArray[i] = (char *)malloc((wordSize + 1) * sizeof(char));
    memcpy(wordArray[i], string, wordSize);
    *(wordArray[i] + wordSize) = '\0';
    string = ++tempEnd;
  }
  wordArray[size] = NULL;
  return wordArray;
}

void printWordArray(char **wordArray) {
  if (wordArray)
    for (int i = 0; wordArray[i]; i++)
      printf("%s\n", wordArray[i]);
}

int main(void) {
  char *stuff = "Hello World! Haha yesn't";
  /* char *stuff = ""; */
  printf("Number of words in \"%s\": %d\n", stuff, countWordsInString(stuff));

  char *moreStuff[] = {"Hi", "there", "get", "fucked", "by", "SIGSEGV", NULL};
  printf("Number of words in the moreStuff array: %d\n", countWords(moreStuff));

  printWordArray(moreStuff);

  char **splitStuff = splitString(stuff);
  printWordArray(splitStuff);

  return 0;
}
