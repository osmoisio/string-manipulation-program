/***************************************************************************
 *   Copyright (C) 2022 by Ossi Moisio                                     *
 *                                                                         *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/*********************************************************************

  1. NAME
  string_manipulation_program.c

  2. DESCRIPTION
  Program which lets you manipulate a string of characters. Prints a menu and user may select the actions.

**********************************************************************/

/*-------------------------------------------------------------------*
 *    HEADER FILES                                                    *
 *--------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

/*-------------------------------------------------------------------*
 *    GLOBAL VARIABLES AND CONSTANTS                                  *
 *--------------------------------------------------------------------*/
/* Control flags */

/* Global constants */
#define STRING_LENGTH 20

/* Global variables */

/* Global structures */

/*-------------------------------------------------------------------*
 *    FUNCTION PROTOTYPES                                             *
 *--------------------------------------------------------------------*/
void display_menu(void);
char ask_command(void);
int count_vowels(char s[]);
int count_consonants(char s[]);
void to_upper(char s[]);
void to_lower(char s[]);
void print_string(char s[]);
void read_string(char s[]);
void read_file(char s[]);
void write_file(char s[]);

/*********************************************************************
 *    MAIN PROGRAM                                                      *
 **********************************************************************/

int main() {
  char string[STRING_LENGTH] = "Hello World!!";
  char cmd;
  int count;

  display_menu();

  while (cmd != 'X') {
    cmd = ask_command();

    switch (cmd) {
      
      case 'A':
      count = count_vowels(string);
      printf("String has %d vowels\n", count);
      printf("\n");
      break;

      case 'B':
      count = count_consonants(string);
      printf("String has %d consonants\n", count);
      printf("\n");
      break;

      case 'C':
      to_upper(string);
      printf("\n");
      break;

      case 'D':
      to_lower(string);
      printf("\n");
      break;

      case 'E':
      print_string(string);
      printf("\n");
      break;

      case 'F':
      read_string(string);
      printf("\n");
      break;

      case 'G':
      read_file(string);
      printf("\n");
      break;

      case 'H':
      write_file(string);
      printf("\n");
      break;

      case 'M':
      display_menu();
      break;
    }
  }
} /* end of main */

/*********************************************************************
 *    FUNCTIONS                                                       *
 **********************************************************************/

/*********************************************************************
  F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
  NAME: display_menu
  DESCRIPTION: Prints a menu of the actions.
  Input:
  Output:
  Used global variables:
  REMARKS when using this function:
*********************************************************************/

void display_menu(void) {
  printf("A) Count the number of vowels in the string\nB) Count the number of consonants in the string\nC) Convert the string to uppercase\nD) Convert the string to lowercase\nE) Display the current string\nF) Enter another string\nG) Read string from file\nH) Write string to file\n\nM) Display this menu\nX) Exit program\n\n");
}

/*********************************************************************
  F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
  NAME: ask_command
  DESCRIPTION: Asks a command from the user.
  Input:  Character
  Output: Character in uppercase
  Used global variables:
  REMARKS when using this function: Changes lowercase into uppercase, and prints error if command is not in correct range.
*********************************************************************/

char ask_command(void) {
  char cmd[STRING_LENGTH];
  printf("Enter command: ");
  fgets(cmd, STRING_LENGTH, stdin);

  if (cmd[0] >= 'a' && cmd[0] <= 'z') {
    cmd[0] = cmd[0] - 32;
  }

  if (cmd[0] >= 'A' && cmd[0] <= 'H' || cmd[0] == 'M' || cmd[0] == 'X') {
    return cmd[0];
  }

  else {
    printf("Invalid command\n\n");
  }
}

/*********************************************************************
  F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
  NAME: count_vowels
  DESCRIPTION: Counts vowels in the string.
  Input: String
  Output: Number of vowels in string
  Used global variables:
  REMARKS when using this function:
*********************************************************************/

int count_vowels(char s[]) {
  int count = 0, i;
  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] == 'a' || s[i] == 'A' || s[i] == 'u' || s[i] == 'U' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O') {
      count++;
    }
  }
    return count;
}

/*********************************************************************
  F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
  NAME: count_consonants
  DESCRIPTION: Counts consonants in the string
  Input:  String
  Output: Number of consonants in string
  Used global variables:
  REMARKS when using this function:
*********************************************************************/

int count_consonants(char s[]) {
  int count = 0, i;
  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] == 'a' || s[i] == 'A' || s[i] == 'u' || s[i] == 'U' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O') {
    } else if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z') {
      count++;
    }
  }
  return count;
}

/*********************************************************************
  F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
  NAME: to_upper
  DESCRIPTION: Converts the string to uppercase
  Input:  String
  Output:
  Used global variables:
  REMARKS when using this function:
*********************************************************************/

void to_upper(char s[]) {
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      s[i] = s[i] - 32;
    }
  }
}

/*********************************************************************
  F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
  NAME: to_lower
  DESCRIPTION: Converts the string to lowercase
  Input:  String
  Output:
  Used global variables:
  REMARKS when using this function:
*********************************************************************/

void to_lower(char s[]) {
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] >= 'A' && s[i] <= 'Z') {
      s[i] = s[i] + 32;
    }
  }
}

/*********************************************************************
  F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
  NAME: print_string
  DESCRIPTION: Display the current string
  Input:  String
  Output:
  Used global variables:
  REMARKS when using this function:
*********************************************************************/

void print_string(char s[]) {
  printf("%s\n", s);
}

/*********************************************************************
  F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
  NAME: read_string
  DESCRIPTION: Enter another string
  Input:  String
  Output:
  Used global variables:
  REMARKS when using this function: Removes newline from the end of the string.
*********************************************************************/

void read_string(char s[]) {
  printf("Give string: ");
  fgets(s, STRING_LENGTH, stdin);
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] == '\n') {
      s[i] = '\0';
    }
  }
}

/*********************************************************************
  F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
  NAME: read_file
  DESCRIPTION: Read string from file
    Input: String
    Output:
  Used global variables:
  REMARKS when using this function:
*********************************************************************/

void read_file(char s[]) {
  FILE *fPointer;
  fPointer = fopen("string.txt", "r");
  fscanf(fPointer, "%[^\n]", s);
  fclose(fPointer);
}

/*********************************************************************
  F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
  NAME: write_file
  DESCRIPTION: Write string to file
  Input: String
  Output:
  Used global variables:
  REMARKS when using this function:
*********************************************************************/

void write_file(char s[]) {
  FILE *fPointer;
  fPointer = fopen("string.txt", "w");
  fprintf(fPointer, "%s", s);
  fclose(fPointer);
}
