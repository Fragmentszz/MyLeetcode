/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getBiggestThree(int** grid, int gridSize, int* gridColSize, int* returnSize) {
    int x=0,y=0;
    int rows = gridSize ;
    int cols = *gridColSize;
    int* result =(int *) malloc(sizeof(int) * 3);
    *returnSize = 0;
    result[0] = result[1] = result[2] = 0;
    while (y!=rows)
    {

        int i = 0;
        while ((x + i) < cols && (x - i) >= 0 && (y - i) >= 0 && (y + i) < rows)
        {
            int j = 2, temp=0;
            if(i)
            {
                int flag1=0,flag2=0;
                int dx=0,dy=i;
                while(1)
                {
                    temp+=grid[y+dy][x+dx];
                    dx+= flag1?1:-1;
                    dy+= flag2?1:-1;
                    if(dy==i)    break;
                    if(dy== -i) flag2=!flag2;
                    if(dx==i || dx==-i) flag1=!flag1;
                }
            }
            else
                temp=grid[y][x];
            while (j>=0 && temp > *(result + j))    j--;
            if (j==-1 || j<2 && temp != *(result+j))
            {
                
                int a =2;
                for (; a > j +1; a--) *(result + a) = *(result + a - 1);
                *(result + a) = temp;
            }
            i++;
        }           
            x= (x+1) % cols;
            if(x==0) y++;
    }
    for(int i =0;i<3 && *(result+i)!=0   ;i++)    {
        *returnSize = *returnSize+1;
       }
    return result;
}
