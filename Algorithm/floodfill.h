int get_min(uint8_t w, uint8_t x, uint8_t y, uint8_t z){
    if      ((w<=x)&&(w<=y)&&(w<=z)) {return w;}
    else if ((x<=w)&&(x<=y)&&(x<=z)) {return x;}
    else if ((y<=w)&&(y<=x)&&(y<=z)) {return y;}
    else if ((z<=w)&&(z<=x)&&(z<=y)) {return z;}
    else{return 0;}
}

void curr_cell_update(uint8_t Nrow, uint8_t Ncol){
    read_maze_data(Nrow,Ncol);
    currCell=tempDistance;
    if (tempN==0){
        read_distance_data(Nrow+1, Ncol); 
        Ncell=tempDistance;
    }
    else{
        Ncell=250;
    }
    if (tempE==0){
        read_distance_data(Nrow, Ncol+1); 
        Ecell=tempDistance;
    }
    else{
        Ecell=250;
    }
    if (tempS==0){
        read_distance_data(Nrow-1, Ncol); 
        Scell=tempDistance;
    }
    else{
        Scell=250;
    }
    if (tempW==0){
        read_distance_data(Nrow, Ncol-1); 
        Wcell=tempDistance;
    }
    else{
        Wcell=250;
    }
    md_plus_one=get_min(Ncell,Ecell,Scell,Wcell)+1;
    if (currCell==md_plus_one){
        updated = false;
    }
    else{
        currCell=md_plus_one;
        maze[Nrow][Ncol] = ((maze[Nrow][Ncol])&0x00FF)|((uint16_t)currCell<<8);
        updated = true;
    }
}

void update_cells(uint8_t Nrow, uint8_t Ncol){
    curr_cell_update(Nrow,Ncol);
    push_neighbours(Nrow,Ncol);
    is_stack_empty();
    while (stack_not_empty){
        stack_pop();
        curr_cell_update(poprow,popcol);
        if (updated){
            push_open_neighbours(poprow,popcol);
        }
        is_stack_empty();
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

void possible_moves_to_floodfill(){ //outputs a array of possible directions for movement
    read_maze_data(R,C);
    if (tempN==0){
        read_distance_data(R+1,C);
        Ncell=tempDistance;
    }
    else{
        Ncell=250;
    }
    if (tempE==0){
        read_distance_data(R,C+1);
        Ecell=tempDistance;
    }
    else{
        Ecell=250;
    }
    if (tempS==0){
        read_distance_data(R-1,C);
        Scell=tempDistance;
    }
    else{
        Scell=250;
    }
    if (tempW==0){
        read_distance_data(R,C-1);
        Wcell=tempDistance;
    }
    else{
        Wcell=250;
    }

    minCell=get_min(Ncell,Ecell,Scell,Wcell);
    if ((minCell==Ncell)&&(Ncell<250)){movdir[0]=1;}else{movdir[0]=0;}
    if ((minCell==Ecell)&&(Ecell<250)){movdir[1]=1;}else{movdir[1]=0;}
    if ((minCell==Scell)&&(Scell<250)){movdir[2]=1;}else{movdir[2]=0;}
    if ((minCell==Wcell)&&(Wcell<250)){movdir[3]=1;}else{movdir[3]=0;}   
}

void move_mouse(){     //updates R,C  -- only for simulation purposes
    if (face==0){
        if (movdir[0]==1){
            R++;
            face=0;
        }
        else if (movdir[1]==1){
            C++;
            face=1;
        }
        else if (movdir[3]==1){
            C--;
            face=3;
        }
        else{
            R--;
            face=2;
        }  
    }
    else if (face==1){
        if (movdir[1]==1){
            C++;
            face=1;
        }
        else if (movdir[0]==1){
            R++;
            face=0;
        }
        else if (movdir[2]==1){
            R--;
            face=2;
        }
        else{
            C--;
            face=3;
        }  
    }
    else if (face==2){
        if (movdir[2]==1){
            R--;
            face=2;
        }
        else if (movdir[1]==1){
            C++;
            face=1;
        }
        else if (movdir[3]==1){
            C--;
            face=3;
        }
        else{
            R++;
            face=0;
        }  
    }
    else{
        if (movdir[3]==1){
            C--;
            face=3;
        }
        else if (movdir[0]==1){
            R++;
            face=0;
        }
        else if (movdir[2]==1){
            R--;
            face=2;
        }
        else{
            C++;
            face=1;
        }  
    }
}

void get_wall_data(){
    wall_data=transposed_walls[R][C];
    N=(wall_data&0b0000000000000001);
    E=(wall_data&0b0000000000000010)>>1;
    S=(wall_data&0b0000000000000100)>>2;
    W=(wall_data&0b0000000000001000)>>3;
}

void floodfill(){
    R=0,C=0;
    while(true){
        get_wall_data();
        update_wall_data(R,C);
        update_cells(R,C);
        print_maze();
        possible_moves_to_floodfill();
        move_mouse();
        read_distance_data(R,C);
        if(tempDistance==0){
            break;
        }
    }

}