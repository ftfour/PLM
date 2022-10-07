#include <stdio.h>
int main(){
	int a,b,pow, i;
	printf("%s", "input please:");
	scanf("%d", &a);
  	pow = 1;
	b=a;
	
	while(b>=2){
		pow++;
		b /= 2;
	}	
	b=a;
	for ( i = pow; i >= 0; --i){
		printf("%d", (b >> i) & 1 );
	}
	b = a;

	printf("\n");
	
	printf("%d\t%d\n", a,pow);
	a = a << 1;
	if ( a > 0) a = a ^( 1 << pow);
	a |= 1;
	b =a;
	for ( i = pow; i >= 0; --i){
		printf("%d", (b >> i) & 1 );
	}
	b = a;

	printf("\n");

	printf("%d", a);
	return 0;
}
