char* convert(char* s, int numRows) {
    if (numRows > 1)
    {
        int length = strlen(s);
        int per = 2 * numRows - 2;
        int cols = length / per;
        int left = length % per;
        char* ptr;
        char* head = ptr = (char*)malloc(length + 1);
        for (int y = 0; y < numRows; y++)
        {
                for (int x = 0; x <= cols; x++)
                {
                    if (x * per + y < length && *(s + x * per + y))
                    {
                        *ptr = *(s + x * per + y);
                        *(s + x * per + y) = 0;
                        ptr++;
                    }
                    if (x * per + per - y < length && *(s + x * per + per- y))
                    {
                        *ptr = *(s + x * per + per - y);
                        *(s + x * per + per- y) = 0;
                        ptr++;
                    }
                }
        }
        *ptr = '\0';
        return head;
    }
    else
        return s;
}
