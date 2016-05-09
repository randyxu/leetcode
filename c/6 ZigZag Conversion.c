char* convert(char* s, int numRows) {
    int length = strlen(s);
    char* ret = 0;
    int i = 0, j = 0;
    int base = 0;
    
    ret = malloc(length + 1);
  
    if (numRows == 1)
        return s;

    for (i = 0; i < numRows; i++) {
        for (base = i; base < length; base = base + 2*(numRows-1)) {
            if (i == 0 || i == numRows - 1) { //first line or last line
                ret[j++] = s[base];
            }
            else if (i > 0 && i < numRows - 1) { //middle lines
                ret[j++] = s[base];
                if (base + 2*(numRows-i-1) < length)
                    ret[j++] = s[base + 2*(numRows-i-1)];
            }
            else   //should not happen
                break;

        }
    }


    ret[j] = '\0';
    return ret;
}

