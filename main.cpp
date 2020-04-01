#include <iostream>
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
    cout << "\n" << "Press enter to continue........." <<endl;
    
    cin.get();
    cin.clear();
 
    floodfill_setup();
    transpose();    // to convert greens wall array
    add_wall_data_from_file();
    print_maze();

    cout << "Maze to be travesed" << endl; 
    cout << "\n" << "Generatrd the distance values" << endl;
    cout << "\n" << "Destination set to the center" << endl;
    cout << "\n" << "Press enter to continue........." << endl;
          
    cin.get();
    cin.clear();

    floodfill_setup();
    generate_maze_to_center();
    print_maze();
    floodfill();
    print_maze();
    
    cout << "\n" << "Please set the destination to explore" << endl;
    cout << "\n" << "Row:";
    cin >> R_explore;
    cout << "\n" << "Column:";
    cin >> C_explore;

    cout << "\n" << "Generating distance values to cell (" << R_explore << "," << C_explore<<")";
    cin.get();
    cin.clear();

    generate_maze_to_cell(R_explore,C_explore);  //update every cell after this
    print_maze();
    update_every_cell_explore();
    print_maze();
    floodfill_explore();
    print_maze();
    
    cin.get();
    cin.clear();



    int v;
    cin >> v;

    return 0;
}  
