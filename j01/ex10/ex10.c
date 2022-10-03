#include <stdio.h>

#include <unistd.h>

#include <string.h>


double add(double a, double b) {
  return a + b;

}

double substract(double a, double b) {
  return a - b;
}

double multiply(double a, double b) {
  return a * b;
}

double divide(double a, double b) {
  return a / b;
}

void discard_junk() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void main() {

  double a, b;
  double result;
  int choice = 0;
  int i = 0;
  char * congrat = "Good Value :)";
  char * nope = "Please enter an integer hacker ~$ ";
  char * choice_list = "\n1) Add\n2) Substract\n3) Multiply\n4) Divide\nChoose an option : ";
  char * number_1 = "Choose number 1 ~$ ";
  char * number_2 = "Choose number 2 ~$ ";

  write(1, number_1, strlen(number_1));

  do {
    i = scanf("%lf", & a);
    if (i == 1) {
      write(1, congrat, strlen(congrat));
    } else {
      write(1, nope, strlen(nope));
      discard_junk();
    }

  } while (i != 1);

  write(1, "\n", strlen("\n"));

  write(1, number_2, strlen(number_2));
  do {
    i = scanf("%lf", & b);
    if (i == 1) {
      write(1, congrat, strlen(congrat));
    } else {
      write(1, nope, strlen(nope));
      discard_junk();
    }

  } while (i != 1);

  write(1, "\n", strlen("\n"));

  while (choice < 1 || choice > 5) {
    write(1, choice_list, strlen(choice_list));
    scanf("%d", & choice);
  }

  if (choice == 1)
    result = add(a, b);
  if (choice == 2)
    result = substract(a, b);
  if (choice == 3)
    result = multiply(a, b);
  if (choice == 4)
    result = divide(a, b);
  printf("Answer is : %lf\n", result);

}
