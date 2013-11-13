#ifndef MATH_H
#define MATH_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define MAX 100
#define MED 50
#define MIN 25

void display_home_menu (void);
void get_char_input (char *in_char);
void get_string_input (char *in_string[]);
void get_int_input (int *in_integer);
void display_instructions (void);
void display_profile_prompt (void);
void display_difficulty_prompt (void);

#endif