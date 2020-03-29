#include <iostream>
#include <conio.h>
#include "global_space.h"
#include "function_list.h"
#include "Algorithm/floodfill.h" 
#include "Algorithm/maze.h"
#include "Algorithm/stack.h"
#include "Algorithm/explore.h"
#include "Algorithm/testing_functions.h"



int main()
{

    cout << "                  --------------------------" << endl;
    cout << "\n";
    cout << "                          Rodent 2.0        " << endl;
    cout << "\n";
    cout << "                  --------------------------" << endl;
    cout << "\n";
    cout << "\n" << "Press any key to continue.........";
    
    getch();

    generate_maze_to_center();
    print_maze();
    transpose();
    floodfill();

    


    getch();
    return 0;
}  
