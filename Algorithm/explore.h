void generate_maze_to_cell(uint8_t Nrow, uint8_t Ncol){
    count = 0; q1=0;
    for (int n=Nrow; n>-1; n--){  //for 1st quadrant
    for (int m=Ncol; m>-1; m--){
        maze[n][m]=((maze[n][m]&0x00FF)|q1<<8);
        // maze[n][m]=q1;
        q1++;
    }
    count++; q1=0; q1+=count;
    }

    count=0; q2=1;
    for (int n=Nrow+1; n<size; n++){  //for 2nd quadrant
    for (int m=Ncol; m>-1; m--){
        maze[n][m]=((maze[n][m]&0x00FF)|q2<<8);
        // maze[n][m]=q2;
        q2++;
    }
    count++; q2=1; q2+=count;
    }

    count=0; q3=1;
    for (int n=Nrow; n>-1; n--){  //for 3rd quadrant
    for (int m=Ncol+1; m<size; m++){
        maze[n][m]=((maze[n][m]&0x00FF)|q3<<8);
        // maze[n][m]=q3;
        q3++;
    }
    count++; q3=1; q3+=count;
    }

    count=0; q4=2;
    for (int n=Nrow+1; n<size; n++){  //for 4th quadrant
    for (int m=Ncol+1; m<size; m++){
        maze[n][m]=((maze[n][m]&0x00FF)|q4<<8);
        // maze[n][m]=q4;
        q4++;
    }
    count++; q4=2; q4+=count;
    }
    R_explore=Nrow;
    C_explore=Ncol;
}

void floodfill_explore(){
    while(true){
        get_wall_data();
        update_wall_data(R,C);
        update_cells_explore(R,C);

        std::cout << "\n" << "Press enter to continue.........";
        print_maze();
        cin.get();
        cin.clear();

        possible_moves_to_floodfill();
        move_mouse();
        read_distance_data(R,C);
        if(tempDistance==0){
            break;
        }
    }

}

void update_cells_explore(uint8_t Nrow, uint8_t Ncol){
    curr_cell_update(Nrow,Ncol);
    push_neighbours_explore(Nrow,Ncol);
    is_stack_empty();
    while (stack_not_empty){
        stack_pop();
        curr_cell_update(poprow,popcol);
        if (updated){
            push_open_neighbours_explore(poprow,popcol);
        }
        is_stack_empty();
    }
}