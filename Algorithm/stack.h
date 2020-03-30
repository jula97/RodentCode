using namespace std;

bool is_stack_empty(){
    if (pointer<0){
        stack_not_empty=false;
        return true;
    }
    else{
        stack_not_empty=true;
        return false;
    }
}

void stack_push(uint8_t Nrow,uint8_t Ncol){  
    if (pointer+1<size*size){
        stackval = 0;
        stackval|=((uint16_t)Nrow<<8|Ncol);
        pointer++;
        stack[pointer]=stackval;
    }
}

void stack_pop(){
    if (pointer>-1){
        stackval=stack[pointer];
        popcol=(uint8_t)(stackval&0x00FF);
        poprow=(uint8_t)((stackval&0xFF00)>>8);
        pointer--;
    }
    else{
        poprow=0, popcol=0;
    }
}

void push_neighbours(uint8_t Nrow, uint8_t Ncol){
    if (Nrow+1<size){
        if ((Nrow+2==size/2)&&(Ncol+1==size/2||Ncol==size/2)){}
        else{
            stack_push(Nrow+1,Ncol);
        }
    }
    if (Ncol+1<size){
        if ((Ncol+2==size/2)&&(Nrow+1==size/2||Nrow==size/2)){}
        else{
            stack_push(Nrow,Ncol+1);
        }
    }
    if (Nrow>0){
        if ((Nrow-1==size/2)&&(Ncol+1==size/2||Ncol==size/2)){}
        else{
            stack_push(Nrow-1,Ncol);
        }
    } 
    if (Ncol>0){
        if ((Ncol-1==size/2)&&(Nrow+1==size/2||Nrow==size/2)){}
        else{
            stack_push(Nrow,Ncol-1);
        }
    }
}

void push_open_neighbours(uint8_t Nrow, uint8_t Ncol){
    read_maze_data(Nrow,Ncol);
    if ((Nrow+1<size)&&(tempN==0)){
        if ((Nrow+2==size/2)&&(Ncol+1==size/2||Ncol==size/2)){}
        else{
            stack_push(Nrow+1,Ncol);
        }
    }
    if ((Ncol+1<size)&&(tempE==0)){
        if ((Ncol+2==size/2)&&(Nrow+1==size/2||Nrow==size/2)){}
        else{
            stack_push(Nrow,Ncol+1);
        }
    }
    if ((Nrow>0)&&(tempS==0)){
        if ((Nrow-1==size/2)&&(Ncol+1==size/2||Ncol==size/2)){}
        else{
            stack_push(Nrow-1,Ncol);
        }
    } 
    if ((Ncol>0)&&(tempW==0)){
        if ((Ncol-1==size/2)&&(Nrow+1==size/2||Nrow==size/2)){}
        else{
            stack_push(Nrow,Ncol-1);
        }
    }
}

void push_neighbours_explore(uint8_t Nrow, uint8_t Ncol){
    if (Nrow+1<size){
        read_distance_data(Nrow+1,Ncol);
        if (tempDistance==0){}
        else{
            stack_push(Nrow+1,Ncol);
        }
    }
    if (Ncol+1<size){
        read_distance_data(Nrow,Ncol+1);
        if (tempDistance==0){}
        else{
            stack_push(Nrow,Ncol+1);
        }
    }
    if (Nrow>0){
        read_distance_data(Nrow-1,Ncol);
        if (tempDistance==0){}
        else{
            stack_push(Nrow-1,Ncol);
        }
    } 
    if (Ncol>0){
        read_distance_data(Nrow,Ncol-1);
        if (tempDistance==0){}
        else{
            stack_push(Nrow,Ncol-1);
        }
    }
}

void push_open_neighbours_explore(uint8_t Nrow, uint8_t Ncol){
    read_maze_data(Nrow,Ncol);
    if (Nrow+1<size){      // pushing the north cell, checks whether distance=0 and whether N=0 at current cell
        read_distance_data(Nrow+1,Ncol);
        if (tempDistance==0){}
        else if (tempN==0) {
            stack_push(Nrow+1,Ncol);
        }
    }
    if (Ncol+1<size){
        read_distance_data(Nrow,Ncol+1);
        if (tempDistance==0){}
        else if (tempE==0) {
            stack_push(Nrow,Ncol+1);
        }
    }
    if (Nrow>0){
        read_distance_data(Nrow-1,Ncol);
        if (tempDistance==0){}
        else if (tempS==0) {
            stack_push(Nrow-1,Ncol);
        }
    } 
    if (Ncol>0){
        read_distance_data(Nrow,Ncol-1);
        if (tempDistance==0){}
        else if (tempW==0) {
            stack_push(Nrow,Ncol-1);
        }
    }
}




