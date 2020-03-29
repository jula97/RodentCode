using namespace std;

void floodfill_setup(){  //updating walls of edges and corners 
    for (int n = 0; n < size; n++){
    for (int m = 0; m < size; m++){
        maze[n][m]=(maze[n][m]<<8);    // 0000 0000 0000 1111 --> 0000 1111 0000 0000
    }
    }
    E=0; W=0;
    for (C=1 ; C<size-1 ; C++){      //updating for north and south edges
        R=size-1; 
        N=1; S=0; update_wall_data(R,C);
        R=0; 
        N=0; S=1; update_wall_data(R,C);
    }
    N=0; S=0;
    for (R=1; R<size-1 ; R++){      //updating for east and west edges
        C=size-1;
        E=1; W=0; update_wall_data(R,C);
        C=0;
        E=0; W=1; update_wall_data(R,C);
    }
    N=1;E=1;S=0;W=0; update_wall_data(size-1,size-1);    //uodating for corners
    N=1;E=0;S=0;W=1; update_wall_data(size-1,0);
    N=0;E=1;S=1;W=0; update_wall_data(0,size-1);
    N=0;E=0;S=1;W=1; update_wall_data(0,0);
}

void update_wall_data(uint8_t Nrow, uint8_t Ncol){     //updating wall data in the maze array
    maze[Nrow][Ncol]|=(N<<Nbitval|E<<Ebitval|S<<Sbitval|W<<Wbitval);
    if ((Nrow<size-1)&&(N==1)){
        maze[Nrow+1][Ncol]|=(1<<Sbitval);
    }
    if ((Nrow>0)&&(S==1)){
        maze[Nrow-1][Ncol]|=(1<<Nbitval);
    }
    if ((Ncol<size-1)&&(E==1)){
        maze[Nrow][Ncol+1]|=(1<<Wbitval);
    }
    if ((Ncol>0)&&(W==1)){
        maze[Nrow][Ncol-1]|=(1<<Ebitval);
    }
}

void read_maze_data(uint8_t Nrow, uint8_t Ncol){      //tempN,E,S,W and tempDistance gets updated
    tempMazedata=maze[Nrow][Ncol];
    tempDistance=(uint8_t) ((tempMazedata&0xFF00)>>8);
    tempN=(uint8_t)(tempMazedata&0x0001);
    tempE=(uint8_t)((tempMazedata&0x0002)>>Ebitval);
    tempS=(uint8_t)((tempMazedata&0x0004)>>Sbitval);
    tempW=(uint8_t)((tempMazedata&0x0008)>>Wbitval);
}

void read_distance_data(uint8_t Nrow, uint8_t Ncol){   //tempDistance gets updated
    tempMazedata=maze[Nrow][Ncol];
    tempDistance=(uint8_t) ((tempMazedata&0xFF00)>>8);
}

void print_maze(){
    for (int row = size-1; row >-1; row--){
        cout << "\n";  cout << "+"; //replace with println when uploading
        for (int i=0; i<2; i++){
            if (i==1){cout << '\n'; cout << "|";}
            for (int column=0; column<size; column++){
                read_maze_data(row,column);
                int distance = tempDistance;
                if (i==0){
                    if (tempN==1){cout << "---+";}
                    else{cout << "   +";}
                }
                if ((R==row)&(C==column)){
                    if (i==1){
                        if(tempE==1){
                            if (distance<10){cout << " "<< face_to_print(face) << " " << "|";}
                            else if (distance<100){cout << " " << face_to_print(face) << " " << "|";}
                            else{cout << face_to_print(face) << "|";}
                        } 
                        else{
                            if (distance<10){cout << " "<< face_to_print(face) << " " << " ";}
                            else if (distance<100){cout << " " << face_to_print(face) << " " << " ";}
                            else{cout << face_to_print(face) << " ";}
                        }  
                    }
                }
                else{
                    if (i==1){
                        if(tempE==1){
                            if (distance<10){cout << " "<< distance << " " << "|";}
                            else if (distance<100){cout << " " << distance << "|";}
                            else{cout << distance << "|";}
                        } 
                        else{
                            if (distance<10){cout << " "<< distance << " " << " ";}
                            else if (distance<100){cout << " " << distance << " ";}
                            else{cout << distance << " ";}
                        }  
                    }
                }
            }    
        } 
    }
    cout << "\n"; cout << "+"; //replace with println when uploading    
    for (uint8_t i = 0; i < size; i++) {
        cout << "---+";
    }
    cout << "\n";
}

void generate_maze_to_center(){
    int corner = ((size/2)-1)*2;
    for (int n = 0; n < size/2; n++){
    for (int m = 0; m < size/2; m++){
        maze[n][m]=corner-m;
        maze[n][size-1-m]=corner-m;
        maze[size-1-n][m]=corner-m;
        maze[size-1-n][size-1-m]=corner-m;
    }
    corner--;
    }
    floodfill_setup();
}


