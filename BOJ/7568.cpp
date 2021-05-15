#include <stdio.h>

struct Body {
  int weight;
  int height;
};

Body person[50];
int numOfPersonWhoHasBigBody[50];

void initializeArrayFillZero (int numberOfPerson) {
  for (int index = 0; index < numberOfPerson; index++) {
    numOfPersonWhoHasBigBody[index] = 0;
  }
}

void setPersonBody (int index, Body volume) {
  person[index] = volume;
}

int comparePersonBody (Body x, Body y) {
  return   x.weight > y.weight ? (x.height > y.height ? -1 : 0)
         : x.weight < y.weight ? (x.height < y.height ?  1 : 0) : 0;
}

int main() {
  int numberOfPerson;
  scanf("%d", &numberOfPerson);

  for (int index = 0; index < numberOfPerson; index++) {
    Body body;
    scanf("%d %d", &body.weight, &body.height);
    setPersonBody(index, body);
  }

  initializeArrayFillZero(numberOfPerson);

  for (int index = 0; index < numberOfPerson - 1; index++) {
    for (int subIndex = index + 1; subIndex < numberOfPerson; subIndex++) {

      Body x = person[index];
      Body y = person[subIndex];

      if (comparePersonBody(x, y) == -1) {
        numOfPersonWhoHasBigBody[subIndex]++;
      } else if (comparePersonBody(x, y) == 1) {
        numOfPersonWhoHasBigBody[index]++;
      }

    }
  }

  for (int index = 0; index < numberOfPerson; index++) {
    printf("%d ", numOfPersonWhoHasBigBody[index] + 1);
  }

  return 0;
}