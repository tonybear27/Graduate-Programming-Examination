//DP
//Variation of the Knapsack Problem
//Very Easy 
#include <stdio.h>
bool dp[1000005]; //Declar in global scope, absolutely
//dp[i] indicates there are i stone(s)
int main() 
{
    int n, m;
    int s[1000];
    
	while(scanf("%d %d", &n, &m)!=EOF) 
	{
        for(int i = 0; i < m; i++)
            scanf("%d", &s[i]);
       
	    dp[0] = false;
        for(int i = 1; i <= n; i++) 
		{
            dp[i] = 0;
            for(int j = 0; j < m; j++) 
			{
                if(i-s[j] >= 0) // If your backpack can fit stones
				{
                    if(dp[i-s[j]] == 0) //If stones is not avaliable
					{
                        dp[i] = true; //Someone wins the game..... 
                        break;
                    }
                }
            }
        }
        
        if(dp[n])
            puts("Stan wins");
        else
            puts("Ollie wins");
            
    }
    return 0;
}
