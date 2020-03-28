#include <iostream>
#include "global_space.h"
#include "function_list.h"
#include "Algorithm/floodfill.h" 
#include "Algorithm/maze.h"
#include "Algorithm/stack.h"
#include "Algorithm/testing_functions.h"



int main()
{
    int v;

    cout << "                  --------------------------" << endl;
    cout << "\n";
    cout << "                          Rodent 2.0        " << endl;
    cout << "\n";
    cout << "                  --------------------------" << endl;

    generate_maze_to_center();
    add_wall_data_from_file();  
    update_every_cell_center();
    print_maze();
    generate_maze_to_cell(0,0);
    print_maze();
    


    cin >> v;

    return 0;
}  
