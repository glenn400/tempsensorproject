#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>

int size = 8;
void delay_us(int desired_delay_us)
{
	struct timeval tv_start;
	struct timeval tv_now;
	int elapsed_time_us;

	gettimeofday(&tv_start,NULL);
	elapsed_time_us = 0;

	while (elapsed_time_us < desired_delay_us )
	{
		gettimeofday(&tv_now,NULL);
		if (tv_now.tv_usec >= tv_start.tv_usec)
			{
				elapsed_time_us = tv_now.tv_usec - tv_start.tv_usec;

			}
		else
			{
				elapsed_time_us = (1000000 - tv_start.tv_usec )+ tv_now.tv_usec;
			}
	}
	return;
}

void filehandle(FILE *file, int p)
{
	
	if (file)
	{
		
		fseek(file, 0 , SEEK_SET);
		
		fprintf(file, "%d\n" , p);
		
		fflush(file);
		
		
		return;
	}
	else
	{
		printf("Failure of file \n ");
		return;
	}
	
	

}

void set8Binary(int *val )			// function to set value on display 
{
	// printf ("%d " , val);
	int a = val[0];
	int b = val[1];
	int c = val[2];
	int d = val[3];
	int e = val[4];
	int f = val[5];
	int g = val[6];
	int h = val[7];
	

	printf(" most sig %d , %d, %d, %d, %d, %d, %d, %d least sig \n ",  h,g,f,e,d,c,b,a);

	FILE *ofp_gpio5_value;
	FILE *ofp_gpio4_value;
	FILE *ofp_gpio2_value;
	
	FILE *clock;
	clock = fopen("/sys/class/gpio/gpio2/value" 	, "w");
	FILE *serial;
	serial = fopen("/sys/class/gpio/gpio4/value" 	, "w");
	FILE *latch;
	latch = fopen("/sys/class/gpio/gpio5/value" 	, "w");	

	filehandle(clock,1);
	filehandle(latch,1);
	filehandle(serial,1);

	filehandle(latch,0);		// set latch to zero 
	
	filehandle(clock,0);
	filehandle(clock,1);
	filehandle(serial,a);		// middle bar 
	

	filehandle(clock,0);
	filehandle(clock,1);
	filehandle(serial,b);		// upper left 

	filehandle(clock,0);
	filehandle(clock,1);
	filehandle(serial,c);		// bottom left
	
	filehandle(clock,0);
	filehandle(clock,1);
	filehandle(serial,d);		// bottom 

	filehandle(clock,0);
	filehandle(clock,1);
	filehandle(serial,e);		// bottom right 
	
	filehandle(clock,0);
	filehandle(clock,1);
	filehandle(serial,f);		// top right

	filehandle(clock,0);
	filehandle(clock,1);
	filehandle(serial,g);		// top
	
	filehandle(clock,0);
	filehandle(clock,1);
	filehandle(serial,h);		// dot

	filehandle(latch,1);		// set latch to zero 

	fclose(clock);
	fclose(latch);
	fclose(serial);
	
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	e = 0;
	f = 0;
	g = 0;
	h = 0;

	return;
}

int checkInput(FILE *f, int v)
{
	if (f)
	{
		fseek(f, 0 , SEEK_SET);
		fscanf(f, "%d\n", &v);
		fclose(f);
	return v;
	}
	else
		return -1;
	
}

int main(void)
{
	

	int z = 0;						// cycle through arrays	

//	Zero is serial 	1 0111-1111
	int zero[] = {0 ,1 ,1 ,1 ,1 ,1 ,1 ,1};
	int zerod[] = {0 ,1 ,1 ,1 ,1 ,1 ,1 ,0};				// d at end of variable name indicates no dot 
	printf(" %d zero " , zero);
	
//	One is 		1 0000-1101
	int one[] = {0, 0, 0, 0, 1, 1, 0, 1};
	int oned[] = {0, 0, 0, 0, 1, 1, 0, 0};
	
	
//	two is 		1 1011-0111
	int two[] = {1, 0 , 1 , 1 , 0 , 1 , 1 , 1};
	int twod[] = {1, 0 , 1 , 1 , 0 , 1 , 1 , 0};

	
//	three is	1 1001-1111
	
	int three[] = {1 , 0 , 0 , 1 , 1 , 1 , 1 , 1};
	int threed[] = {1 , 0 , 0 , 1 , 1 , 1 , 1 , 0};

	
// 	four is 	1 1100-1101
	int four[] = {1 , 1, 0, 0 , 1 , 1 , 0 ,1};
	int fourd[] = {1 , 1, 0, 0 , 1 , 1 , 0 ,0};
	
	
//	five is		1 1101-1011
	
	int five[] = {1 , 1 , 0 , 1 , 1 , 0 , 1 , 1};
	int fived[] = {1 , 1 , 0 , 1 , 1 , 0 , 1 , 0};
	
//	six is		1 1111-1011
	
	int six[] = {1 , 1 , 1 , 1 , 1 , 0 , 1 , 1};
	int sixd[] = {1 , 1 , 1 , 1 , 1 , 0 , 1 , 0};
	
	
//	seven is 	1 0000-1111
	
	int seven[] = {0 , 0 , 0 , 0 , 1 , 1 , 1 , 1};
	int sevend[] = {0 , 0 , 0 , 0 , 1 , 1 , 1 , 0};
	
	
//	eight is	1 1111-1111
	
	int eight[] = {1 , 1 , 1 , 1 , 1 , 1 , 1 , 1};
	int eightd[] = {1 , 1 , 1 , 1 , 1 , 1 , 1 , 0};
	
	
//	nine is		1 1101-1111	
	
	int nine[] = {1 , 1 , 0 , 1 , 1 , 1 , 1, 1};
	int nined[] = {1 , 1 , 0 , 1 , 1 , 1 , 1, 1};
	
	double vi = 1800000;			// intial voltage supplied by p9_32
	double R2 = 10000;				// other resistor at 10 kOhms
	double R;				// R is resistor of temp sensor that we are aqcuiring
	
	// voltage divider to aquire the Temp sensor R value
	// R2 * vout / vi - vout
	
	// 1/t = t0 + t1*ln(R1)    temp equation
	// R1 = Rs/R2
	double R1;
	double r5;					// temp value to hold value of natural log
	
	double tf = 25 + 273.15;			
	double t0 = 1 / tf;				// intial temp 1/T0
	
	
	double t1 = 1 / 4038;				// 4038 is beta constant 
	double r3;					// temP variable to hold t1 * ln(R1)
	double r4;					// temP variable to hold t0 + r3
	double t;					// variable to hold inverse of temp (1/t)
	double temp;					// variable to hold temp 
	

	
	while (true) {
		int val = 0;
		int v = 0;
		// ain5
		FILE *a_file;
		a_file = fopen("/sys/devices/ocp.3/bacon_adc_helper.15/AIN5" 	, "r");

		val = checkInput(a_file, v);			// val is in microvolts (vout)
		printf("%d\n microVolts\n",val);
		
		int r1 = R2 * val;
		int r2 = vi - val;
		R = r1/r2;					// get value of Unknown resistor
		R1 = R/R2;					// divide R by R2 
		r5 = log(R1);					// take ln of R1
		r3 = t1 * r5;					// log(R) * 1/4038
		r4 = t0 + r3;					// 1/T0 + (1/4038 * log(R)
		t = 1/r4;
		temp = t - 273.15;				// get temp in degrees celcius
		
		printf(" temp is %f in k , temp is %f in C  " , t , temp);


		int zz = (int)temp % 10;				// get value in least sig bit
		printf(" temp is %d least sig  " , zz);
		int yy = ((int)temp / 10) % 10;				// get value in next place to the left
		printf(" temp is %d next sig  " , yy);
		int xx = ((int)temp / 100) % 10;			// value in next place 
		printf(" temp is %d bigg sig  " , xx);

		if (xx > 0 || (zz == 0 && yy == 0) )
		{
			set8Binary(zerod);
			set8Binary(zero);
			
			
			
		}
		else
		{
			
				if ( yy == 0 )
				{
					if ( zz == 0)
					{
						set8Binary(zerod);
						set8Binary(zero);
					}
					else if ( zz == 1)
					{
						set8Binary(oned);
						set8Binary(zero);
					}
					else if ( z == 2)
					{
						set8Binary(twod);
						set8Binary(zero);
					}
					else if ( zz == 3)
					{
						set8Binary(threed);
						set8Binary(zero);
					}
					else if ( zz == 4)
					{
						set8Binary(fourd);
						set8Binary(zero);
					}
					else if ( zz == 5)
					{
						set8Binary(fived);
						set8Binary(zero);
					}
					else if ( zz == 6)
					{
						set8Binary(sixd);
						set8Binary(zero);
					}
					else if ( zz == 7)
					{
						set8Binary(sevend);
						set8Binary(zero);
					}
					else if ( zz == 8)
					{
						set8Binary(eightd);
						set8Binary(zero);
					}
					else
					{
						set8Binary(nined);
						set8Binary(zero);	
					}
						
				}
				else if ( yy == 1)
				{
					if ( zz == 0)
					{
						set8Binary(zerod);
						set8Binary(one);
					}
					else if ( zz == 1)
					{
						set8Binary(oned);
						set8Binary(one);
					}
					else if ( z == 2)
					{
						set8Binary(twod);
						set8Binary(one);
					}
					else if ( zz == 3)
					{
						set8Binary(threed);
						set8Binary(one);
					}
					else if ( zz == 4)
					{
						set8Binary(fourd);
						set8Binary(one);
					}
					else if ( zz == 5)
					{
						set8Binary(fived);
						set8Binary(one);
					}
					else if ( zz == 6)
					{
						set8Binary(sixd);
						set8Binary(one);
					}
					else if ( zz == 7)
					{
						set8Binary(sevend);
						set8Binary(one);
					}
					else if ( zz == 8)
					{
						set8Binary(eightd);
						set8Binary(one);
					}
					else
					{
						set8Binary(nined);
						set8Binary(one);	
					}
					
				}
				else if ( yy == 2)
				{
					if ( zz == 0)
					{
						set8Binary(zerod);
						set8Binary(two);
					}
					else if ( zz == 1)
					{
						set8Binary(oned);
						set8Binary(two);
					}
					else if ( z == 2)
					{
						set8Binary(twod);
						set8Binary(two);
					}
					else if ( zz == 3)
					{
						set8Binary(threed);
						set8Binary(two);
					}
					else if ( zz == 4)
					{
						set8Binary(fourd);
						set8Binary(two);
					}
					else if ( zz == 5)
					{
						set8Binary(fived);
						set8Binary(two);
					}
					else if ( zz == 6)
					{
						set8Binary(sixd);
						set8Binary(two);
					}
					else if ( zz == 7)
					{
						set8Binary(sevend);
						set8Binary(two);
					}
					else if ( zz == 8)
					{
						set8Binary(eightd);
						set8Binary(two);
					}
					else
					{
						set8Binary(nined);
						set8Binary(two);	
					}
					
				}
				else if ( yy == 3)
				{
					if ( zz == 0)
					{
						set8Binary(zerod);
						set8Binary(three);
					}
					else if ( zz == 1)
					{
						set8Binary(oned);
						set8Binary(three);
					}
					else if ( z == 2)
					{
						set8Binary(twod);
						set8Binary(three);
					}
					else if ( zz == 3)
					{
						set8Binary(threed);
						set8Binary(three);
					}
					else if ( zz == 4)
					{
						set8Binary(fourd);
						set8Binary(three);
					}
					else if ( zz == 5)
					{
						set8Binary(fived);
						set8Binary(three);
					}
					else if ( zz == 6)
					{
						set8Binary(sixd);
						set8Binary(three);
					}
					else if ( zz == 7)
					{
						set8Binary(sevend);
						set8Binary(three);
					}
					else if ( zz == 8)
					{
						set8Binary(eightd);
						set8Binary(three);
					}
					else
					{
						set8Binary(nined);
						set8Binary(three);	
					}
					
				}
				else if ( yy == 4)
				{
					if ( zz == 0)
					{
						set8Binary(zerod);
						set8Binary(four);
					}
					else if ( zz == 1)
					{
						set8Binary(oned);
						set8Binary(four);
					}
					else if ( z == 2)
					{
						set8Binary(twod);
						set8Binary(four);
					}
					else if ( zz == 3)
					{
						set8Binary(threed);
						set8Binary(four);
					}
					else if ( zz == 4)
					{
						set8Binary(fourd);
						set8Binary(four);
					}
					else if ( zz == 5)
					{
						set8Binary(fived);
						set8Binary(four);
					}
					else if ( zz == 6)
					{
						set8Binary(sixd);
						set8Binary(four);
					}
					else if ( zz == 7)
					{
						set8Binary(sevend);
						set8Binary(four);
					}
					else if ( zz == 8)
					{
						set8Binary(eightd);
						set8Binary(four);
					}
					else
					{
						set8Binary(nined);
						set8Binary(four);	
					}
					
				}
				else if ( yy == 5)
				{
					if ( zz == 0)
					{
						set8Binary(zerod);
						set8Binary(five);
					}
					else if ( zz == 1)
					{
						set8Binary(oned);
						set8Binary(five);
					}
					else if ( z == 2)
					{
						set8Binary(twod);
						set8Binary(five);
					}
					else if ( zz == 3)
					{
						set8Binary(threed);
						set8Binary(five);
					}
					else if ( zz == 4)
					{
						set8Binary(fourd);
						set8Binary(five);
					}
					else if ( zz == 5)
					{
						set8Binary(fived);
						set8Binary(five);
					}
					else if ( zz == 6)
					{
						set8Binary(sixd);
						set8Binary(five);
					}
					else if ( zz == 7)
					{
						set8Binary(sevend);
						set8Binary(five);
					}
					else if ( zz == 8)
					{
						set8Binary(eightd);
						set8Binary(five);
					}
					else
					{
						set8Binary(nined);
						set8Binary(five);	
					}
					
				}
				else if ( yy == 6)
				{
					if ( zz == 0)
					{
						set8Binary(zerod);
						set8Binary(six);
					}
					else if ( zz == 1)
					{
						set8Binary(oned);
						set8Binary(six);
					}
					else if ( z == 2)
					{
						set8Binary(twod);
						set8Binary(six);
					}
					else if ( zz == 3)
					{
						set8Binary(threed);
						set8Binary(six);
					}
					else if ( zz == 4)
					{
						set8Binary(fourd);
						set8Binary(six);
					}
					else if ( zz == 5)
					{
						set8Binary(fived);
						set8Binary(six);
					}
					else if ( zz == 6)
					{
						set8Binary(sixd);
						set8Binary(six);
					}
					else if ( zz == 7)
					{
						set8Binary(sevend);
						set8Binary(six);
					}
					else if ( zz == 8)
					{
						set8Binary(eightd);
						set8Binary(six);
					}
					else
					{
						set8Binary(nined);
						set8Binary(six);	
					}
					
				}
				else if ( yy == 7)
				{
					if ( zz == 0)
					{
						set8Binary(zerod);
						set8Binary(seven);
					}
					else if ( zz == 1)
					{
						set8Binary(oned);
						set8Binary(seven);
					}
					else if ( z == 2)
					{
						set8Binary(twod);
						set8Binary(seven);
					}
					else if ( zz == 3)
					{
						set8Binary(threed);
						set8Binary(seven);
					}
					else if ( zz == 4)
					{
						set8Binary(fourd);
						set8Binary(seven);
					}
					else if ( zz == 5)
					{
						set8Binary(fived);
						set8Binary(seven);
					}
					else if ( zz == 6)
					{
						set8Binary(sixd);
						set8Binary(seven);
					}
					else if ( zz == 7)
					{
						set8Binary(sevend);
						set8Binary(seven);
					}
					else if ( zz == 8)
					{
						set8Binary(eightd);
						set8Binary(seven);
					}
					else
					{
						set8Binary(nined);
						set8Binary(seven);	
					}
					
				}
				else if ( yy == 8)
				{
					if ( zz == 0)
					{
						set8Binary(zerod);
						set8Binary(eight);
					}
					else if ( zz == 1)
					{
						set8Binary(oned);
						set8Binary(eight);
					}
					else if ( z == 2)
					{
						set8Binary(twod);
						set8Binary(eight);
					}
					else if ( zz == 3)
					{
						set8Binary(threed);
						set8Binary(eight);
					}
					else if ( zz == 4)
					{
						set8Binary(fourd);
						set8Binary(eight);
					}
					else if ( zz == 5)
					{
						set8Binary(fived);
						set8Binary(eight);
					}
					else if ( zz == 6)
					{
						set8Binary(sixd);
						set8Binary(eight);
					}
					else if ( zz == 7)
					{
						set8Binary(sevend);
						set8Binary(eight);
					}
					else if ( zz == 8)
					{
						set8Binary(eightd);
						set8Binary(eight);
					}
					else
					{
						set8Binary(nined);
						set8Binary(eight);	
					}
					
				}
				else
				{
					if ( zz == 0)
					{
						set8Binary(zerod);
						set8Binary(nine);
					}
					else if ( zz == 1)
					{
						set8Binary(oned);
						set8Binary(nine);
					}
					else if ( z == 2)
					{
						set8Binary(twod);
						set8Binary(nine);
					}
					else if ( zz == 3)
					{
						set8Binary(threed);
						set8Binary(nine);
					}
					else if ( zz == 4)
					{
						set8Binary(fourd);
						set8Binary(nine);
					}
					else if ( zz == 5)
					{
						set8Binary(fived);
						set8Binary(nine);
					}
					else if ( zz == 6)
					{
						set8Binary(sixd);
						set8Binary(nine);
					}
					else if ( zz == 7)
					{
						set8Binary(sevend);
						set8Binary(nine);
					}
					else if ( zz == 8)
					{
						set8Binary(eightd);
						set8Binary(nine);
					}
					else
					{
						set8Binary(nined);
						set8Binary(nine);	
					}
				
						
				}
			}
			delay_us(100000);
		
		
	}
	
	
	
	





	return 0;
}

	
