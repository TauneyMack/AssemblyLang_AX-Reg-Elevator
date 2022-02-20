#include<iostream>
#include<time.h>
using namespace std;

short i, r, b, temp, c;
/*  Function to display Base 2
unsigned short y=n, t, c=l<<15;
for(int i=1;i<=16;++i)
{
	t=y&c;
	if(t=0) cout<<0;
	else if (i%4==0) cout<<" ";
	y=y<<1;
}
*/

void print()
{
	cout << i << " ";
}
void randomNum()
{
	r = (rand() % 15) + 2; //elevator floor 2-16
}
void printBinary()
{
	cout << c;
}
void addSpace()
{
	cout << " ";
}
int main()
{
	srand(time(0));
	cout << "AX= ";
	_asm
	{
		mov i, 0;
		mov b, 0;
	forloop:
		cmp i, 10;
		jge done;			//if i>=10, jmp to done
		call randomNum;
		mov ax, 1;			//ax=1
		sub r, 1;			//r=r-l
		mov cx, r; 
		shl ax, cl;			 //shift ax to the left by r
		or b, ax;			//b=b|r   0 or 1
		inc i;
		jmp forloop;
	done:
		mov ax, b;
		mov temp, ax;
		mov i, -1;
	forloop2:
		inc i;
		cmp i, 16;
		jge finish;
		mov ax, temp;
		and ax, 1000000000000000b;
		shr ax, 15;
		mov c, ax;
		//spacing for 16 bit 
		mov ax, i;
		mov bx, 4;
		cwd;
		idiv bx;			//ax=i/4 dx=i%4
		cmp dx, 0;
		jne noSpace;
		call addSpace;
	noSpace:
		call printBinary; 
		shl temp, 1;
		jmp forloop2;
	finish:
	}
	cout << endl;
	cout << "Elevator will stop at the following floors: ";
	_asm
	{
		mov ax, b;
		mov temp, ax;
		mov i, 0;
	forloop3:
		inc i;
		cmp i, 16;
		jg done2;
		mov ax, temp;
		and ax, 0x0001;
		cmp ax, 0x00001;
		jne passed;
		call print;
	passed:
		shr temp, 1;
		jmp forloop3;
	done2:
	}
	cout << endl;
	system("pause");
}
/*
AX=  1101 0000 0010 1100
Elevator will stop at the following floors: 3 4 6 13 15 16
Press any key to continue . . .
*/