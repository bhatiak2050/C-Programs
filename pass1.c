#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
	FILE *f1, *f2, *f3, *f4;
	int locctr, start_address, l, operand, o, len;
	char opcode[20], label[20], op[20], otp[20];

	f1 = fopen("input.txt", "r");
	f3 = fopen("symtab.txt", "w");

	fscanf(f1, "%s%s%d", label, opcode, &start_address);
	if(strcmp(opcode, "START")==0)
	{
		start_address = operand;
		locctr = start_address;
		printf("\t%s\t%s\t%d\n", label, opcode, start_address);
	}
	else
		locctr = 0;
	fscanf(f1, "%s%s", label, opcode);
	
	while(!feof(f1))
	{
		fscanf(f1, "%s", op);
		printf("\n%d\t%s\t%s\t%s\n", locctr, label, opcode, op);
		if(strcmp(label, "-")!=0)
		{
			fprintf(f3, "%d\t%s\n", locctr, label);
		}
		f2 = fopen("optab.txt", "r");
		fscanf(f2, "%s%d", otp, &o);
		while(!feof(f2))
		{
			if(strcmp(opcode, otp)==0)
			{
				locctr = locctr+3;
				break;
			}
			fscanf(f2, "%s%d", otp, &o);
		}
		fclose(f2);
		if(strcmp(opcode, "WORD")==0)
		{
			locctr  = locctr+3;
		}
		else if(strcmp(opcode, "RESW")==0)
		{
			operand = atoi(op);
			locctr = locctr+(3*operand);
		}
		else if(strcmp(opcode, "BYTE")==0)
		{
			if(op[0]=='X')
				locctr+=1;
			else
			{
				len = strlen(op)-2;
				locctr+=len;
			}
		}
		else if(strcmp(opcode, "RESB")==0)
		{
			operand = atoi(op);
			locctr+=operand;
		}
		fscanf(f1, "%s%s",label,opcode);
	}
	if(strcmp(opcode,"END")==0)
	{
		printf("Program length = %d\n", locctr-start_address);
	}
	fclose(f1);
	fclose(f2);
}