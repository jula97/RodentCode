void print_stack(){
    for (int16_t stack_length=pointer; stack_length>-1; stack_length--){
        stack_pop();
        cout << (int)poprow << (int)popcol << endl;
    }
}

void add_wall_data_from_file(){
    transpose();
    for (int n=0; n<size; n++){
    for (int m=0; m<size; m++){
        maze[n][m]=(maze[n][m]&0xFF00)|transposed_walls[n][m];
    }
    }
}

void transpose() {  //to transpose greens wall data
    int i, j; 
    for (i = 0; i < size; i++){ 
    for (j = 0; j < size; j++){ 
            transposed_walls[i][j] = walls[j][i]; 
    }
    }
} 

void update_every_cell_center(){  //runs modified floodfill on every cell except center cells   
    for (R=0; R<size; R++){
    for (C=0; C<size; C++){
        if (((R==size/2)&(C==size/2))|
            ((R+1==size/2)&(C==size/2))|
            ((R==size/2)&(C+1==size/2))|
            ((R+1==size/2)&(C+1==size/2))
        ){}
        else{
        update_cells(R,C);
        }
    }
    }
}

void update_every_cell_start(){   //to run modified floodfill while exploring
    for (R=0; R<size; R++){
    for (C=0; C<size; C++){
        if((R==size-1)&(C==0)){}
        else{        
        update_cells_explore(R,C);
        print_maze();
        }
    }
    }
    
}

