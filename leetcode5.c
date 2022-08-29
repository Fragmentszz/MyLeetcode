char* longestPalindrome(char* s) {
    char* ptr1, *ptr2;
    char result[] = "";
    int length = strlen(s);
    for (int len = length; len > 0; len--)
    {
        for (ptr1 = s, ptr2 = s + len - 1; ptr2 < s + length; )
        {
            char* ptr = ptr1;
            while (ptr1 < ptr2 && *ptr1 == *ptr2)  ptr1++, ptr2--;
            if (ptr1 >= ptr2) { *(ptr + len) = '\0'; return ptr; }
            ptr1 = ptr+1;
            ptr2 = ptr1+len-1;
        }
    
}
return result;
}
