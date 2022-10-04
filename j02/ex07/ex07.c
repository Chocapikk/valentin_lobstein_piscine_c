#include <unistd.h>


void o_print_string(char * str) {
  int i;
  i = 0;
  while (str && str[i] != '\0') {
    write(1, & str[i], 1);
    i++;
  }

}

char o_strcpy(char * string1,
  const char * string2) {
  size_t i = 0;
  while (string2[i] != '\0') {
    string1[i] = string2[i];
    i++;
  }

  string1[i] = '\0';
  return *string1;
}

const int o_strlen(const char * str) {

  int length = 0;
  while (str[length] != '\0') {

    length++;
  }

  return length;
}

int o_strcmp(const char * str1,
  const char * str2) {

  int i = 0;
  unsigned char * str_cp1 = (unsigned char * ) str1;
  unsigned char * str_cp2 = (unsigned char * ) str2;

  while (str_cp1[i] != '\0' && str_cp2[i] != '\0') {
    if (str_cp1[i] == str_cp2[i])
      i++;
    else
      break;

  }

  return (str_cp1[i] - str_cp2[i]);
}

/*void o_reverse_str_table(char * arr, char size) {
  char * temp;
  int j = size - 1;
  for (int i = 0; i < j; i++) {
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    j--;
  }

}
*/

void sort(int argc, char ** argv) {
  int i, j;
  int count;
  char * str[25][25];
  char temp[25];

  for (i = 0; i < argc; i++) {
    o_strcpy(str[i], argv[i]);
  }

  if (o_strcmp(argv[1], "desc") != 0 && o_strcmp(argv[1], "asc") != 0) {
    o_print_string("Please provide a correct second argument ('asc' or 'desc')\n");

  } else {
    count = argc;
    for (i = 2; i <= count; i++) {
      for (j = i + 1; j <= count; j++) {
        if (o_strcmp(str[i], str[j]) > 0) {
          o_strcpy(temp, str[i]);
          o_strcpy(str[i], str[j]);
          o_strcpy(str[j], temp);
        }
      }
    }

    if (o_strcmp(argv[1], "desc") == 0) {
      for (i = argc; i >= 2; i--) {
        o_print_string(str[i]);
        o_print_string("\n");

      }
    } else {
      for (i = 2; i <= argc; i++) {
        o_print_string(str[i]);
        o_print_string("\n");
      }
    }
  }

}

void main(int argc, char ** argv) {

  if (argc >= 3) {
    sort(argc, argv);

  }

}
