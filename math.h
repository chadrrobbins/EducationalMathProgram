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

typedef struct struct_problem
{
	int terms;
	int numbers[4];
	char operators[4];
	char number_sign;
	char problem[20];
	int solution;
	int remainder;
}Struct_Problem;

void display_home_menu (void);
void get_char_input (char *in_char);
void get_string_input (char *in_string[]);
void get_int_input (int *in_integer);
int get_number (int number_of_numbers, int size_of_numbers);
void display_instructions (void);
void display_profile_prompt (void);
void display_difficulty_prompt (void);
int validate_home_menu_selection (char home_menu_selection);
void evaluate_home_menu_selection (char home_menu_selection, char *user_profile, int *session_difficulty);
void run_game_loop (char home_menu_selection, char *user_profile[], int session_difficulty);
char generate_equation (int max_terms, int max_digits, char available_operators[], char has_negatives, char equation[]);
Struct_Problem generate_math_problem (int level);

#endif