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

void get_char_input (char *char_selection)
{
	scanf("%c", char_selection);
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

void get_string_input (char *in_string[])
{
	scanf("%s", in_string);
}