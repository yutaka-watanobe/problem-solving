#include <stdio.h>
#include <stdlib.h>


static int	Counting(int);
static int	Usage(void);


int
main( int	argc,
      char	*argv[] )
{

        int n, v;
	FILE *pdata; 


//	if (argc != 2) {
//		Usage();
//	        exit( 1 );
//	}

// 	pdata=fopen( argv[1], "rb" );
	
 	pdata=fopen( "chains.txt", "rb" );
	while (fscanf(pdata, "%d", &n)!=EOF){
//		printf("VAL %d --> ", n);
		v=Counting(n);
		printf ("%d\n", v); 
	}
	return 0;

}


/*Bording of the image*/
static int
Counting(int n)
{
	int mod, v;
	if (n==0) return 0; 
	if (n==1) return 1; 
	if (n==2) return 2; 

 	mod=n%2;	
	if (mod>0)
		v=Counting(n-1)*2+1;
	else v=Counting(n-1)+Counting(n-2)+1;
	return v;
}

static int
Usage( void )
{

   printf("------------------------------------------------------------\n\n" );
   printf("Program: chain \n" );
   printf("./chain.exe data.dat \n\n" );
   printf("------------------------------------------------------------\n\n" );

   return ( 0 ); 

}

