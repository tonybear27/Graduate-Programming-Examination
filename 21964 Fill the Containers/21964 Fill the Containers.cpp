//Greedy
#include<stdio.h>
int N, M; // N:Number of milk bottles  M:Number of containers
int n[1000001];   // Volume of each milk bottle

int main()
{
    while (scanf("%d%d",&N, &M)!=EOF)
	{
        int left=0, right=0;
        for (int i=0; i<N; i++) 
		{
            scanf("%d", &n[i]);
            if (n[i]>left) 
				left = n[i];
            right += n[i];
        }

        while (left < right) //Use binary search to find the minimal container whose amount==M
		{ 
            int mid = (left+right)/2;
            int sum=0;    //Accumulate each volume of milk
            int amount=0; // Count the used container
            for (int i=0; i<N; i++)
			{
                sum += n[i];
                if (sum > mid) 
				{
                    amount++;
                    sum = n[i];
                }
                else if (sum == mid)
				{
                    amount++;
                    sum = 0;
                }
            }
            if (sum>0) 
				amount++;
            if (amount > M) 
				left = mid+1;  //If there are too many container
            else 
				right = mid;
        }
        
        printf("%d\n", left);
    }
    return 0;
}
