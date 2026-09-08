/*+------------------------------+------------------------------------+
|       Intel Code             |      AT&T Code                     |
+------------------------------+------------------------------------+
| mov     eax,1                |  movl    $1,%eax                   |   
| mov     ebx,0ffh             |  movl    $0xff,%ebx                |   
| int     80h                  |  int     $0x80                     |   
| mov     ebx, eax             |  movl    %eax, %ebx                |
| mov     eax,[ecx]            |  movl    (%ecx),%eax               |
| mov     eax,[ebx+3]          |  movl    3(%ebx),%eax              | 
| mov     eax,[ebx+20h]        |  movl    0x20(%ebx),%eax           |
| add     eax,[ebx+ecx*2h]     |  addl    (%ebx,%ecx,0x2),%eax      |
| lea     eax,[ebx+ecx]        |  leal    (%ebx,%ecx),%eax          |
| sub     eax,[ebx+ecx*4h-20h] |  subl    -0x20(%ebx,%ecx,0x4),%eax |
+------------------------------+------------------------------------+*/
/*
!!! bibliografía:
 1. ensamblador:			https://lenguajesdeprogramacion.net/assembler/
 2. ensamblador en c:		https://reversebytes.wordpress.com/2012/12/13/como-hacer-inline-assembly-en-lenguaje-c-dev-c/
 3. ensamlador en c (feo):	http://arantxa.ii.uam.es/~gdrivera/labetcii/curso0001/udigxiii.htm#:~:text=La%20sentencia%20asm%20permite%20incluir,seg%C3%BAn%20la%20versi%C3%B3n%20del%20compilador.
*/

#include<bits/stdc++.h>
using namespace std;

/* // Originals (do not touch) ----------------------------------
int main() {
int res;
// move value to register %eax
// move value to register %ebx
// subtracting and storing result in res
__asm__ ( "movl $20, %%eax;"
          "movl $10, %%ebx;"
          "subl %%ebx, %%eax ":"=a"(res));
    cout<<res;
return 0;  
}*/

/* // -----------------------------------------------------------
int main() {
int res;
// source 5 is written first
// then destination register is written
// this will move 5 to register
	__asm__ ( "movl $5, %%eax;": "=a"(res));
	cout<<res;
	return 0;
  
}
*/

/* // -----------------------------------------------------------
int main() {
int res;
// move immediate value 50 to register eax
// move immediate value 20 to register ebx
// the added value is stored in res for output
__asm__ (
		"movl $50, %%eax;"
        "movl $20, %%ebx;"
        "addl %%ebx, %%eax ":"=a"(res)
		);
    cout<<res;
   return 0;
} */

/* // -----------------------------------------------------------
int main(){ // esto trae error
  // generates interrupt 5
  asm int 5;  
  
  return 0;
} */

/* // ----------------------------------------------------------
int main(){
	int val1,val2, add, sub, mul;
  
	val1=100;val2=20;
    asm( "addl %%ebx, %%eax;" : "=a" (add) : "a" (val1) , "b" (val2) );
    asm( "subl %%ebx, %%eax;" : "=a" (sub) : "a" (val1) , "b" (val2) );
    asm( "imull %%ebx, %%eax;" : "=a" (mul) : "a" (val1) , "b" (val2) );
 	
	printf( "%d + %d = %d\n", val1, val2, add );
    printf( "%d - %d = %d\n", val1,val2, sub );
    printf( "%d * %d = %d ", val1, val2, mul );
  
  return 0;
} */

// TEST ARENA: ============================================================================



int main() {
int res;
asm volatile(	"movl $20, %%eax;"	// move value to register %eax
    			"movl $1, %%ebx;"	// move value to register %ebx	
    			"subl %%ebx, %%eax ":"=a"(res)// subtracting and storing result in res
    		);
    cout<<res;
return 0;  
}

















