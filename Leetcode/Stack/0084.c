// 84. Largest Rectangle in Histogram
int largestRectangleArea(int* heights, int heightsSize) {
    int nll[heightsSize];
    int nlr[heightsSize];
    int stack[heightsSize+1], idx=-1;
    for(int i=0; i<heightsSize; i++){
        while(idx > -1 && heights[stack[idx]] >= heights[i]) idx--;
        if(idx > -1) nll[i] = stack[idx];
        else nll[i] = -1;
        stack[++idx] = i;
    }
    idx=-1;
    for(int i=heightsSize-1; i >-1; i--){
        while(idx > -1 && heights[stack[idx]] >= heights[i]) idx--;
        if(idx > -1) nlr[i] = stack[idx];
        else nlr[i] = heightsSize;
        stack[++idx] = i;
    }

    int ans=0;
    for(int i=0; i<heightsSize; i++){
        ans = fmax(ans, heights[i]*(nlr[i]-nll[i]-1));
    }
    return ans;
}
