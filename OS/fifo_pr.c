#include<stdio.h>

void main()
{
	int nof, pf = 0, rs[20], frame[10], n ,count = 0,i ,j , k;

	printf("Enter the length of reference string\n");
	scanf("%d",&n);

	printf("Enter the reference string\n");
	for(i = 0;i<n;i++) 
		scanf("%d",&rs[i]);

	printf("Enter the no of frames\n");
	scanf("%d",&nof);

	for(i=0;i<nof;i++) frame[i] = -1;
	
	for(i=0;i<n;i++) 
	{
		for(k=0;k<nof;k++)
			if(frame[k]==rs[i])
				break;
			
		if(k==nof) 
		{
			frame[count++] = rs[i];
			pf++;
		}
	
		for(j=0;j<nof;j++) printf("%d\t",frame[j]);
		if(k==nof) printf(" Page fault\n");
		else printf("\n");
		if(count==nof) count = 0;
	}
	printf("No of page faults using FIFO: %d\n",pf);
}