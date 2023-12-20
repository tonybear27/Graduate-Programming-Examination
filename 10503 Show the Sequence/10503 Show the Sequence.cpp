#include <stdio.h> 
#include <string.h>
#include <ctype.h>
long long a[128];

void parsing(char s[]) 
{
    int sign = 1, m=0; 
    char pos;
    int i;
    for(i = 1; s[i]; i++) 
	{
        if(s[i] == '-')	
			sign = -1;
        else if(isdigit(s[i])) 
            m = m * 10 + s[i] - '0';
        else 
		{
            pos = s[i];
            break;
        }
    }
    
    m *= sign;
    if(pos == '+') 
	{
        parsing(s + i + 1);
        long long d = a[0];
        a[0] = m;
        for(int k = 1; k < 50; k++) 
		{
            long long t = a[k];
            a[k] = a[k - 1] + d, 
			d = t;
        }
    }
	 
	else if(pos == '*') 
	{
        parsing(s + i + 1);
        a[0] *= m;
        for(int i = 1; i < 50; i++)
            a[i] *= a[i-1];
    } 
	else 
	{
        for(int i = 0; i < 50; i++)
            a[i] = m;
    }
}

int main() 
{
    char s[1024];
    int n;
    while(scanf("%s %d", s, &n)!=EOF) 
	{
        memset(a, 0, sizeof(a));
        parsing(s);
        for(int i = 0; i < n; i++)
            printf("%lld ", a[i]);
        printf("\n");
    }
    return 0;
}
