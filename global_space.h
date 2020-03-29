#ifndef GLOBAL_SPACE_H 
#define GLOBAL_SPACE_H

//maze parameters
const int size = 16;
const int Nbitval=0,Ebitval=1,Sbitval=2,Wbitval=3; 
uint16_t tempMazedata;
uint8_t tempDistance=0, tempN=0, tempE=0, tempS=0, tempW=0;
uint8_t N=0,E=0,S=0,W=0,R=0,C=0; //wall details and position of current cell

//maze_generation
uint16_t maze[size][size] {0};
int corner = ((size/2)-1)*2;   
uint16_t q1 = 0, q2 = 1, q3 = 1, q4 = 2, count = 0; //quadrant starting values
uint16_t walls[size][size]
                            {{14,10,8,10,10,10,10,10,10,10,10,10,10,10,10,9},
                            {12,10,2,10,10,10,10,10,10,10,10,10,10,10,9,5},
                            {5,12,10,9,12,10,10,10,9,12,10,10,10,9,5,5},
                            {5,5,13,5,5,12,9,12,3,5,12,8,11,5,5,5},
                            {5,5,5,5,5,5,6,3,13,6,3,6,9,5,5,5},
                            {5,5,5,6,3,6,8,10,2,10,10,10,3,5,5,5},
                            {5,6,2,10,10,9,6,10,10,10,10,9,12,1,5,5},
                            {5,12,10,10,10,3,13,12,9,13,12,3,5,5,5,5},
                            {5,5,13,13,12,10,1,7,5,4,3,12,3,7,5,5},
                            {5,5,5,4,3,12,3,12,3,5,12,2,11,13,5,5},
                            {5,5,4,3,12,3,12,1,12,3,6,10,9,4,1,5},
                            {5,6,3,12,3,12,3,7,5,12,9,13,6,1,5,5},
                            {5,13,12,3,12,0,10,9,5,5,5,4,9,5,5,5},
                            {5,4,3,12,3,5,14,1,6,3,5,5,5,5,5,5},
                            {5,6,10,2,10,2,10,2,10,11,6,3,6,3,5,5},
                            {6,10,10,10,10,10,10,10,10,10,10,10,10,10,2,3}};

 uint16_t transposed_walls[size][size]{0};


//maze details for floodfill operations
bool updated;
uint8_t currCell=0, Ncell=0, Ecell=0, Scell=0, Wcell=0, md_plus_one=0;

//floodfill implementation
uint8_t minCell=0;
uint8_t movdir[4] {0,0,0,0} ; 
uint8_t face=0;      //N=0, E=1, S=2, W=3 ---mouse is starting facing the north direction

//stack 
uint16_t stack[size*size];
uint16_t stackval = 0;
int16_t pointer = -1;
bool stack_not_empty ;
uint8_t poprow =0, popcol=0;

//testing
uint16_t wall_data = 0;
char print_face[5]={'^','>','v','<','\0'};



#endif