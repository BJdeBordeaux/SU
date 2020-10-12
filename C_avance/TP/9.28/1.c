#include <stdio.h>

int minMaxSum(int numbers[], int length, int *min, int *max) {
  if (*numbers < *min)
    *min = *numbers;
  else if (*numbers > *max)
    *max = *numbers;

  if (!--length)
    return *numbers;
  return *numbers + minMaxSum(numbers+1, length, min, max);
}

float minMaxAvg(int numbers[], int length, int *min, int *max) {
  /* int sum = 0; */
  /* for (int i = 0; i < length; i++) { */
  /*   if (numbers[i] < *min) */
  /*     *min = numbers[i]; */
  /*   else if (numbers[i] > *max) */
  /*     *max = numbers[i]; */
  /*   sum += numbers[i]; */
  /* } */
  return (float)minMaxSum(numbers, length, min, max)/length;
}

int main(void) {
  int numbers[100];
  for (long unsigned int i = 0; i < (sizeof(numbers) / sizeof(*(numbers))); i++)
    numbers[i] = 1;
  for (int i = 0; i < 100; i++) {
    int min = numbers[i], max = min;
    numbers[i] = i+1;
    float average = minMaxAvg(numbers, i+1, &min, &max);
    printf("Minimum: %d, Maximum: %d, Average: %f\n", min, max, average);
  }
  return 0;
}
