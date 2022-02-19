/**
 * Figure 3.33.c converted to C++
 * Modified by Kishan Mistry CS3502 Section 3
 * Run with g++ -g –Wall –std=c++14 –o fig3-33 fig3-33.cpp
 */

#include <iostream>
#include <cstring>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int const MAXLINE = 80;

int main(void)
{
	char *args[MAXLINE/2 + 1];
	char *prog = NULL;
	char **argsPTR = NULL;

	int should_run = 1;
	while(should_run) {

		/* Read user command from keyboard */
		//std::string command;
		char command[50];
		std::cout << "mySH: ";
		std::cin >> command;
		std::cin.getline(command, 80);
		//std::string filePath = "/bin/" + command;
	
		/* Exit loop and terminate program */
		if(command == "exit") {
			should_run = 0;
			break;
		}
		
		prog = std::strtok(command, " ");

		pid_t pid;
		/* fork a child process */
		pid = fork();

		if (pid < 0) { /* error occurred */ 
			fprintf(stderr, "Fork Failed"); 
			return 1;
		}
		else if (pid == 0) { /* child process */
			/* c_str() converts string to char array */
			execlp(filePath.c_str(), command.c_str(), NULL);
			//printf("LINE J");
		}
		else { /* parent process */
			/* parent will wait for the child to complete */
			wait(NULL);
			//printf("Child Complete");
		}
	}
	return 0;
}