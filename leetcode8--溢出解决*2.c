int myAtoi(char* s) {
    int result = 0,flag = 1;
    int i=0;
    while (*(s + i) == ' ')    i++;
    if (*(s + i) == '-')   flag = 0,i++;
    else if (*(s + i) == '+')
        flag = 1, i++;
    while (*(s + i) == '0')    i++;
    if(flag)
    {
        while (*(s + i) <= '9' && *(s+i) >= '0')
        {
            if ((result - 214748364) >0 || result == 214748364 && 7 - *(s + i)+'0'  <= 0)
                return 2147483647 ;
            else
            {
                result = result * 10  -'0'+ *(s + i) ;
                i++;
            }
        }
        return result;
    }
    else
       {
        while (*(s + i) <= '9' && *(s + i) >= '0')
        {
            if ((result - 214748364) > 0 || result == 214748364 && 8 - *(s + i) + '0' <= 0)
                return  -2147483648;
            else
            {
                result = result * 10 - '0' + *(s + i);
                i++;
            }
        }
        return -1 * result;
       }
    return result * (flag?1:-1);
}
