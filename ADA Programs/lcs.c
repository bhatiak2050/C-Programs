#include<stdio.h>
#include<math.h>
#include<string.h>

void lcs(char a[], char b[]){
	int i, j, la = strlen(a), lb = strlen(b);
	int t[la+1][lb+1];
	char c;

	for(i=0; i<=la; i++)
	for(j=0, c='\0'; j<=lb; j++)

	if(i==0 || j==0)
		t[i][j] = 0;
	else if(a[i-1] == b[j-1]){
		t[i][j] = 1+t[i-1][j-1];

		if(b[j-1] != c) {
			printf("%c", a[i-1]);
			c = a[i-1];
		}
	}
	else t[i][j] = fmax(t[i][j-1], t[i-1][j]);

	//printf("\n");
	//for(i=0; i<=la; i++) {
	//for(j=0; j<=lb; j++)
	//	printf("%d ", t[i][j]);
	//printf("\n");
	//}
}

int main(){
	char a[20], x, b[20];
	printf("Enter the two strings\n");
	scanf("%s%c%s", a, &x, b);

	printf("The longest subsequence is ");
	(strlen(a) < strlen(b))?lcs(a, b):lcs(b, a);
	printf("\n");
	return 0;
}
