#include<stdio.h>
int main()
{
	int i, j, m, n, flag=0, t;
	printf("Enter the size of the two arrays (max 50 each): ");
	scanf("%d%d", &m, &n);

	int a[100], b[100], _a=0, _b=0;

	printf("Enter the elements of array 1\n");
	for(i=0; i<m; i++)
	scanf("%d", &a[i]);

	printf("Enter the elements of array 2\n");
        for(i=0; i<n; i++)
        scanf("%d", &b[i]);

	int c[100], o = m+n;

	//Bubble sort A
	for (i=0; i<m-1;i++)
  	{
    		for (j=0; j<m-i-1; j++)
    		{
		      if (a[j] > a[j+1])
      			{
			        t      = a[j];
			        a[j]   = a[j+1];
			        a[j+1] = t;
		        }
    		}
	}

	//Bubble sort B
	for (i=0; i<n-1;i++)
        {
                for (j=0; j<n-i-1; j++)
                {
                      if (b[j] > b[j+1])
                        {
                                t      = b[j];
                                b[j]   = b[j+1];
                                b[j+1] = t;
                        }
                }
        }

	//Merge sort
	for(i=0; i<o; i++)
	{
		flag=0;
		if(a[_a] < b[_b])
		{
			c[i] = a[_a++];
			flag=1;
		}
		else
		{
			c[i] = b[_b++];
			flag=1;
		}

		if(_a == m)
		{
			for(j=((flag==1)?(i+1):i); j<o; j++)
				c[j] = b[_b++];
			break;
		}

		else if(_b == n)
                {
                        for(j=((flag==1)?(i+1):i); j<o; j++)
				c[j] = a[_a++];
                        break;
                }

	}

	printf("The new array is\n");
	for(i=0; i<o; i++)
		printf("%d ", c[i]);
}
