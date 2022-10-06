#include <stdio.h>
int julian(int d, int m, int y){
	int a, y1, m1, jdn;
	a = ((14-m)/12);
	y1 = y + 4800 - a;
	m1 = m + 12 * a-3;
	jdn = (d + ((153*m1+2)/5) + 365*y1 + (y1/4) - (y1/100) + (y1/400) - 32045);
	return jdn;
}

int main(){
	int birthDay, birthMounth, currentDay, currentMounth, currentYear, tempYear;
	scanf("%d %d %d %d %d", &birthDay, &birthMounth, &currentDay, &currentMounth, &currentYear);
	int a, restDays, answer;
	tempYear = currentYear;
	if ( (birthDay == 29) && (birthMounth == 2)){
		if ( currentMounth > 2) 
			tempYear++;
		while (! (((tempYear % 4 == 0) && (tempYear % 100 != 0)) || (tempYear %400 == 0) ) ) tempYear++;}
	restDays = julian(birthDay, birthMounth, tempYear);	
	answer = julian(currentDay, currentMounth, currentYear);
	if ( restDays - answer < 0 )
		restDays = julian(birthDay, birthMounth, currentYear + 1);

	printf("%d", restDays - answer);
	return 0;
}
