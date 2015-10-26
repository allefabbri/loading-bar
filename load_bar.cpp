// Copyright 2015, Alessandro Fabbri
// for any question, please mail rommacc@yahoo.it

/************************************************************************
* This program is free software: you can redistribute it and/or modify  *
* it under the terms of the GNU General Public License as published by  *
* the Free Software Foundation, either version 3 of the License, or     *
* (at your option) any later version.                                   *
*                                                                       *
* This program is distributed in the hope that it will be useful,       *
* but WITHOUT ANY WARRANTY; without even the implied warranty of        *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
* GNU General Public License for more details.                          *
*                                                                       *
* You should have received a copy of the GNU General Public License     *
* along with this program.  If not, see <http://www.gnu.org/licenses/>. *
************************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>            // due to lo10

#ifdef WIN32
#include <windows.h>        // due to Sleep
#else
#include <unistd.h>
#endif

#define NUMBER_OF_TASKS 		 250
#define BAR_LENGTH 				   30
#define IDLE_TIME_MS			   10 

int main() {

	int percentage;
	std::string bar;
	int filled;
	int width = (int) log10(NUMBER_OF_TASKS)+1;

	for (int i = 1; i <= NUMBER_OF_TASKS; i++){
		percentage = (int) (100* i/ ( (double) NUMBER_OF_TASKS) );
		filled = BAR_LENGTH*i/NUMBER_OF_TASKS;
		bar="[";
		for (int j = 1; j <= BAR_LENGTH; ++j) bar += (j<=filled?"=":" ");
		bar += "]";
		std::cout << "Task " << std::setw(width) << i << "/" << NUMBER_OF_TASKS << 
                     " - Progress " << std::setw(3) << percentage << 
                     "%  - " << bar << (i==NUMBER_OF_TASKS?'\n':'\r') << std::flush;
#ifdef WIN32
		Sleep(IDLE_TIME_MS);
#else
		usleep(IDLE_TIME_MS*1000);
#endif
	}
	std::cout << "Job completed!" << std::endl;

	return 0;
}
