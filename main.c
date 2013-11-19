#include "math.h"

int main (void)
{
	int session_difficulty = 0;
	char home_menu_selection = '\0';
	char *user_profile[MAX] = {'\0'};
	char equation[20] = {'\0'};
	char operators[] = {'+', '-', 'x', '/'};
	S_Problem problem = {{0}};

	int random_number = 0;

	srand((unsigned int) time (NULL));	

	generate_equation(3, 100, operators, 'y', &problem);

	//printf("%s\n", equation);

	//display_home_menu();
	//get_char_input(&home_menu_selection);
	//printf("User selection: %c\n", home_menu_selection);

	//display_instructions();

	//display_profile_prompt();
	//get_string_input(user_profile);
	////printf("Your user profile is: %s\n", user_profile);

	//display_difficulty_prompt();
	//get_int_input(&session_difficulty);
	////printf("Your session difficulty is: %d\n", session_difficulty);

	return 0;
}