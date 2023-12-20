#include <stdio.h>
#include <string.h>
using namespace std;
char A[105][150], B[105][150];
int n, m;

int AC() 
{
    if(n != m)  
		return 0;

    for(int i = 0; i < m; i++)
        if(strcmp(A[i], B[i]))
            return 0;
    
	return 1;
}

int PE() 
{
    int idxA = 0, idxB = 0;
    char bufA[10000], bufB[10000];
    
	for(int i = 0; i < n; i++) 
	{
        for(int j = 0; A[i][j]; j++) 
		{
            if(A[i][j] >= '0' && A[i][j] <= '9')
                bufA[idxA++] = A[i][j];
        }
    }
    
    for(int i = 0; i < m; i++) 
	{
        for(int j = 0; B[i][j]; j++) 
		{
            if(B[i][j] >= '0' && B[i][j] <= '9')
                bufB[idxB++] = B[i][j];
        }
    }
    
	bufA[idxA] = '\0';
    bufB[idxB] = '\0';
    
	
	return !strcmp(bufA, bufB);
}

int judge() 
{
    if(AC())    
		return 1;
		
    if(PE())   
		return 2;
    
	return 3;
}

int main() 
{
    int cases = 0;
    while(scanf("%d", &n) && n) 
	{
        scanf(" ");
        int i;
        for(i = 0; i < n; i++)
            gets(A[i]);
        scanf("%d", &m);
        
        scanf(" ");
        
		for(i = 0; i < m; i++)
            gets(B[i]);
        
		int flag = judge();
        
		printf("Run #%d: ", ++cases);
        
		if(flag == 1)
            puts("Accepted");
        else if(flag == 2)
            puts("Presentation Error");
        else
            puts("Wrong Answer");
    
	}
    
	return 0;
}
