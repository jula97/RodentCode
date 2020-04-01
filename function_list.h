//maze operations
void floodfill_setup();
void update_wall_data(uint8_t Nrow,uint8_t Ncol);
void read_maze_data(uint8_t Nrow, uint8_t Ncol);
void read_distance_data(uint8_t Nrow, uint8_t Ncol);
void print_maze();
char face_to_print(uint8_t f);
void generate_maze_to_center();
void generate_maze_to_cell(uint8_t Nrow, uint8_t Ncol);

//stack operations
bool is_stack_empty();
void stack_push(uint8_t Nrow, uint8_t Ncol);
void stack_pop();
void push_neighbours(uint8_t Nrow, uint8_t Ncol);
void push_open_neighbours(uint8_t Nrow, uint8_t Ncol);
void push_neighbours_explore(uint8_t Nrow, uint8_t Ncol);
void push_open_neighbours_explore(uint8_t Nrow, uint8_t Ncol);
void print_stack();

//operations to run modified floodfil algorithm
int get_min(uint8_t w, uint8_t x, uint8_t y, uint8_t z);
void curr_cell_update(uint8_t Nrow, uint8_t Ncol);
void update_cells(uint8_t Nrow, uint8_t Ncol);
void update_cells_explore(uint8_t Nrow, uint8_t Ncol);
void possible_moves_to_floodfill();  //outputs the array movdir which shows the possible directions of motion
void get_wall_data(); //updates N,E,S,W of the current cell
void floodfill();
void floodfill_explore();

//testing
void add_wall_data_from_file();
void transpose();
void update_every_cell_center();
void update_every_cell_explore();


