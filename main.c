#include "math.h"

int main (void)
{
	/*int session_difficulty = 0;
	char home_menu_selection = '\0';
	char user_profile[50] = {'\0'};
	char equation[20] = {'\0'};
	char operators[] = {'+', '-', 'x', '/'};
	S_Problem problem = {{0}};	*/

	srand((unsigned int) time (NULL));	

	run_game_loop();
	
	return 0;
}