// 946. Validate Stack Sequences

#define MAX_LEN 1000
bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize) {
    int stack[MAX_LEN] = {0}, pop_idx=0, idx=-1;
    for(int i=0; i<pushedSize; i++){
        while(idx > -1 && popped[pop_idx] == stack[idx]){
            pop_idx++;
            idx--;
        }
        stack[++idx] = pushed[i];
    }
    while(idx > -1){
        if(popped[pop_idx] != stack[idx]) return false;
        pop_idx++;
        idx--;
    }
    return true;
}