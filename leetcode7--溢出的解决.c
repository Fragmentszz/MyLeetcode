//溢出的相关操作

int reverse(int x) {
    if(x==0 || x==-2147483648)
        return 0;
    else{
        int flag;
        if (x > 0)
            flag = 1;
        else if (x < 0)
            flag = -1;
        else
            flag = 0;
        char sz2[11] = { 0 };
        int temp = abs(x), i = 0,result=0;
        while (temp > 0) {
            *(sz2 + i) = temp % 10 + '0';
            i++, temp /= 10;
        }
        if (strlen(sz2) == 10 && strcmp(sz2, "2147483648") >= 0)
            return 0;
        else
        {
            i = 0;
            while (*(sz2 + i))
            {
                result = result * 10  -'0' + *(sz2 + i);
                i++;
            }
            return flag * result;
        }
    }
}
