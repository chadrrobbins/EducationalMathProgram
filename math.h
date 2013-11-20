#ifndef MATH_H
#define MATH_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

typedef struct s_problem
{
	int terms;
	int numbers[4];
	char operators[4];
	char number_sign;	
	int solution;
	int remainder;
}S_Problem;

typedef struct s_profile
{
	char profile[50];
	int correct_answers;
	int incorrect_answers;
	double accuracy;
}S_Profile;

void display_home_menu (void);
char get_char_input (void);
void get_string_input (char in_string[]);
void get_int_input (int *in_integer);
int get_number (int number_of_numbers, int size_of_numbers);
void display_instructions (void);
void display_profile_prompt (void);
void display_difficulty_prompt (void);
void create_profile (char profile[]);
int validate_home_menu_selection (char home_menu_selection);
void evaluate_home_menu_selection (char home_menu_selection, char user_profile[50], int *session_difficulty, S_Problem *problem);
void run_game_loop (void);
void generate_equation (int max_terms, int max_digits, char available_operators[], char has_negatives, S_Problem *problem);
void get_problems (int level, S_Problem *problem);

#endif