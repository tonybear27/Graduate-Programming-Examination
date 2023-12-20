#include <stdio.h>
#include <string.h>

int map[10001];

int main()
{
    int a;
    int cnt=0;

    while(scanf("%d", &a) && a)
    {
        memset(map, 0, sizeof(map));
    	cnt = 0;
        while(1)
        {
            map[a]++;  
            if(map[a] > 1)
                break;                
            a *= a;
            a /= 100;
            a %= 10000;
            cnt++;
    	}
        printf("%d\n",cnt);           
    }
    
	return 0;
}
