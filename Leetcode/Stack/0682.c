// 682. Baseball Game

#define MAX_SIZE 1000
int calPoints(char** operations, int operationsSize) {
    int stack[MAX_SIZE] = {0}, curr_idx=-1;
    for(int i=0; i<operationsSize; i++){
        int score = atoi(operations[i]);
        if((score == 0 && operations[i][0] == '0') || score != 0){
            stack[++curr_idx] = score;
        }else{
            if(operations[i][0] == '+'){
                score = stack[curr_idx]+stack[curr_idx-1];
                stack[++curr_idx] = score;
            }else if(operations[i][0] == 'D'){
                score = stack[curr_idx]*2;
                stack[++curr_idx] = score;
            }else if(operations[i][0] == 'C'){
                curr_idx--;
            }
        }
    }
    int score = 0;
    while(curr_idx >= 0){
        score += stack[curr_idx--];
    }
    return score;
}