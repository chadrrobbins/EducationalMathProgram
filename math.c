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

char get_char_input (void)
{
	char my_char = '\0';
	scanf("%c", &my_char);
	return my_char;
}

void get_string_input (char in_string[])
{
	scanf("%s", in_string);
}

void get_int_input (int *in_integer)
{
	scanf("%d", in_integer);
}

int get_number (int size_of_numbers)
{
	int i = 0;
	int number = 0;

	number = rand() % size_of_numbers;

}

void display_instructions (void)
{
	system("cls");
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
		/*default:
		printf("Please enter a valid menu selection.\n");
		valid_input = 0;
		break;*/
	}	

	return valid_input;
}

void evaluate_home_menu_selection (char home_menu_selection, char user_profile[50], int *session_difficulty, S_Problem *problem)
{
	int problem_count = 0;

	switch (home_menu_selection)
	{
	case 'a':
		display_instructions();
		system("pause");
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
		if (user_profile == "")
		{
			printf("Please enter a user profile first.\n");
			system("pause");
			break;
		}
		if (*session_difficulty == 0)
		{
			printf("Please enter a difficulty for this session.\n");
			system("pause");
			break;
		}
		while (problem_count < 10)
		{			
			get_problems(*session_difficulty, problem);
		}
		break;
	case 'e':
		exit(0);
		break;
	}	
}

void run_game_loop (void)
{
	int valid = 0;
	int problem_count = 0;
	int session_difficulty = 0;
	char home_menu_selection = '\0';
	char user_profile[50] = {'\0'};
	S_Problem problem = {{0}};	

	while (home_menu_selection != 'e')
	{
		system("cls");
		display_home_menu();
		home_menu_selection = get_char_input();
		valid = validate_home_menu_selection(home_menu_selection);
		evaluate_home_menu_selection(home_menu_selection, user_profile, &session_difficulty, &problem);		
	}
}

void generate_equation (int max_terms, int number_size, char available_operators[], char has_negatives, S_Problem *problem)
{
	int nums = 0;
	int ops = 0;
	int i = 0;
	int number_of_terms = 0;
	int numbers[4] = {0};
	char operators[4] = {'\0'};
	int number_of_operators = 0;
	int negative = 0;
	int terms = 0;

	number_of_terms = rand() % max_terms;
	number_of_operators = 4;

	while (number_of_terms < 2)
	{
		number_of_terms = rand() % max_terms + 1;
	}

	for (nums = 0; nums < number_of_terms; nums++)
	{
		negative = rand() %2;

		if (negative == 1)
		{
			problem ->numbers[nums] = (rand() % number_size + 1) * -1;
		}
		else
		{
			problem ->numbers[nums] = rand() % number_size + 1;
		}
		printf("numbers[%d]: %d\n", nums, problem ->numbers[nums]);
	}

	for (ops = 0; ops < number_of_terms - 1; ops++)
	{
		problem ->operators[ops] = available_operators[rand() % number_of_operators];
		printf("operators[%d]: %c\n", ops, problem ->operators[ops]);
	}

	terms = nums + ops;

	for (i = 0; i < terms; i++)
	{
		if (i % 2 == 0)
		{
			printf("%d", problem ->numbers[i/2]);
			printf(" ");
		}
		else
		{
			printf("%c", problem ->operators[i/2]);
			printf(" ");
		}		
	}	
	printf("=");
	putchar('\n');
}

void get_problems (int level, S_Problem *problem)
{
	char available_operators[4];

	switch (level)
	{
	case 1:
		strcpy(available_operators, "+-");
		generate_equation(3, 9, available_operators, 'n', problem);
		break;
	case 2:
		strcpy(available_operators, "x");
		generate_equation(2, 9, available_operators, 'n', problem);
		break;
	case 3:
		strcpy(available_operators, "/");
		generate_equation(2, 9, available_operators, 'n', problem);
		break;
	case 4:
		strcpy(available_operators, "+-x/");
		generate_equation(3, 9, available_operators, 'y', problem);
		break;
	case 5:
		strcpy(available_operators, "+-x/");
		generate_equation(4, 100, available_operators, 'y', problem);
		break;
	}
}

