#include "math.h"

int main (void)
{
	int int_selection = 0;
	char char_selection = '\0';
	char *user_profile[MAX] = {'\0'};

	display_home_menu();
	get_char_input(&char_selection);
	printf("User selection: %c\n", char_selection);

	display_instructions();
	display_profile_prompt();
	get_string_input(user_profile);
	printf("Your user profile is: %s\n", user_profile);

	return 0;
}