// 42. Trapping Rain Water

int trap(int* height, int heightSize) {
    int maxEleLeft[heightSize], maxEleRight[heightSize];
    maxEleRight[heightSize-1] = height[heightSize-1]; 
    maxEleLeft[0] = height[0];
    for(int i=1; i<heightSize; i++){
        maxEleLeft[i] = fmax(maxEleLeft[i-1], height[i]);
    }
    for(int i=heightSize-2; i>-1; i--){
        maxEleRight[i] = fmax(maxEleRight[i+1], height[i]);
    }

    int ans=0;
    for(int i=0; i<heightSize; i++){
        int curr = fmin(maxEleLeft[i], maxEleRight[i]);
        ans += (curr > height[i]?curr-height[i]:0);
    }
    return ans;
}