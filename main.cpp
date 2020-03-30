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
    cout << "                          APEC 2012         " << endl;
    cout << "\n";
    cout << "                  --------------------------" << endl;
    cout << "\n";
    cout << "\n" << "Press any key to continue.........";
    
    int v;

    getch();

    generate_maze_to_center();
    transpose();
    floodfill();
    generate_maze_to_cell(size-1,size-1);
    floodfill_explore();
    print_maze();

    

    


    getch();
    cin >> v;
    return 0;
}  
