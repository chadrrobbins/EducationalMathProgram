#include "math.h"

void display_home_menu (void)
{
	//Display openning page with available user options
	printf("Welcome to Zippy's Educational Math Program!\n\n");
	printf("Please select from the following menu:\n");
	printf("a. Learn about how to use the program.\n");
	printf("b. Enter your user profile:\n");
	printf("c. Select difficulty.\n");
	printf("d. Start a new sequence of problems.\n");
	printf("e. Save and quit.\n");
}

void get_char_input (char *in_char)
{
	scanf("%c", in_char);
}

void get_string_input (char *in_string[])
{
	scanf("%s", in_string);
}

void get_int_input (int *in_integer)
{
	scanf("%d", in_integer);
}

void display_instructions (void)
{
	printf("Zippy's Educational Math Program is designed for elementary school children.\n");
	printf("There are five levels of difficulty:\n\n");
	printf("Level 1 - Easy: Includes addition and subtraction problems, with positive\n");
	printf("                single digit operands and up to three terms only.\n");
	printf("Level 2 - Fair: Includes multiplication problems, with positive single digit\n");
	printf("                operands and up to two terms only.\n");
	printf("Level 3 - Intermediate: Includes division problems, with positive single\n");
	printf("                digit operands and up to two terms only.\n");
	printf("Level 4 - Hard: Includes a mix of addition, subtraction, multiplication, and\n");
	printf("                division problems, with positive and negative single digit\n");
	printf("                operands and up to three terms only.\n");
	printf("Level 5 - Impossible: Includes a mix of addition, subtraction, multiplication,\n");
	printf("                and division problems, with positive and negative two and\n");
	printf("                three digit opperands and up to four terms only.\n\n");

	printf("As you progress through the program the problems you are given will get harder\n");
	printf("and harder the more correct answers you get.  Each level of difficulty will have");
	printf("10 problems.  At the end of the 10 problems your progress will be saved.\n");
}

void display_profile_prompt (void)
{
	printf("Please enter your user profile:\n");
}

void display_difficulty_prompt (void)
{
	printf("Please select your difficulty.\n");
}

int validate_home_menu_selection (char home_menu_selection)
{
	int valid_input = 0;

	switch (home_menu_selection)
	{
	case 'a':
		valid_input = 1;
		break;
	case 'b':
		valid_input = 1;
		break;
	case 'c':
		valid_input = 1;
		break;
	case 'd':
		valid_input = 1;
		break;
	case 'e':
		valid_input = 1;
		break;
	default:
		valid_input = 0;
		break;
	}			

	return valid_input;
}

void evaluate_home_menu_selection (char home_menu_selection, char *user_profile[], int *session_difficulty)
{
	while (home_menu_selection != 'e')
	{
		switch (home_menu_selection)
		{
			case 'a':
				display_instructions();
				break;
			case 'b':
				display_profile_prompt();
				get_string_input(user_profile);
				break;
			case 'c':
				display_difficulty_prompt();
				get_int_input(session_difficulty);
				break;
			case 'd':
				break;
		}
	}

	if (home_menu_selection == 'e')
	{
		exit(0);
	}
}

void run_game_loop (char home_menu_selection, char *user_profile[], int session_difficulty)
{
	int valid = 0;

	valid = validate_home_menu_selection(home_menu_selection);

	while (valid != 0)
	{
		display_home_menu();
		get_char_input(&home_menu_selection);
		//printf("User selection: %c\n", home_menu_selection);

		display_instructions();

		display_profile_prompt();
		get_string_input(user_profile);
		//printf("Your user profile is: %s\n", user_profile);

		display_difficulty_prompt();
		get_int_input(&session_difficulty);
		//printf("Your session difficulty is: %d\n", session_difficulty);
	}
}

Struct_Problem generate_math_problem (int level)
{
	Struct_Problem problem = {{0}};
	int i = 0;	

	switch (level)
	{
		case 1:
			for (i = 0; i <= 3; i++)
			{
				problem.numbers[i] = rand() % 10; 
			}
			problem.operators[0] = '+';
			problem.operators[1] = '-';
			problem.number_sign = '+';
			problem.problem = problem.numbers[0], problem.operators[rand() % 2], problem.numbers[1], problem.operators[rand() % 2], problem.numbers[2];
			break;
		case 2:
			for (i = 0; i <= 2; i++)
			{
				problem.numbers[i] = rand() % 10; 
			}
			problem.operators[0] = 'x';
			break;
		case 3:
			for (i = 0; i <= 2; i++)
			{
				problem.numbers[i] = rand() % 10; 
			}
			problem.operators[0] = '/';
			break;
		case 4:
			for (i = 0; i <= 3; i++)
			{
				problem.numbers[i] = rand() % 10; 
			}
			problem.operators[0] = '+';
			problem.operators[1] = '-';
			problem.operators[2] = 'x';
			problem.operators[3] = '/';
			break;
		case 5:
			for (i = 0; i <= 4; i++)
			{
				problem.numbers[i] = rand() % 101; 
			}
			problem.operators[0] = '+';
			problem.operators[1] = '-';
			problem.operators[2] = 'x';
			problem.operators[3] = '/';
			break;
	}
}

