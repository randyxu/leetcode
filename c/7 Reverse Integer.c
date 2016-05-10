int reverse(int x) {
    long result = 0;
    int tmp = x;
    int max = 0x7fffffff, min = 0x80000000;
    
    if (tmp < 0)
        tmp = -tmp;
        
    while (tmp > 0) {
        result = 10*result + tmp%10;
        if (result > max || result < min)
            return 0;
        tmp /= 10;
    }
    
    return (int)(x<0 ? -result : result);
}