#include<stdio.h>

#include<unistd.h>

#include<stdlib.h>

struct process{

	char process_id[20];

	int arrival_time;

	int burst_time;
	
	int completion_time;

	int remain_burst;

}a[100], b[100], c[100];



int n, x=0, y=0, z=0;                                                            //global variables

int time_quant;


void INPUT(){

	int p,  i, t;

	printf("NUMBER OF QUERIES ? : "); scanf("%d", &n);

	if(n==0) { printf("\n NO QUERY\n"); }

	else{

		printf("\nENTER TIME QUANTUM FOR EACH (in minutes): "); scanf("%d", &time_quant);

		printf("\nVALUES:\n1: FACULTY\n2: STUDENT\n");

		for(i=0; i<n; i++){

			printf("\nENTER VALUE FOR PROCESS: "); scanf("%d", &p);

			if(p==1){

				printf("QUERY NAME: "); scanf("%s", &a[x].process_id);

				printf("ARRIVAL TIME(in 24 hour format): "); scanf("%d", &t);

				if(t<1000 || t>1200){

					printf("\nSORRY SUDESH SHARMA IS BUSY AT THIS TIME\n");

					return 0;

				}

				else{a[x].arrival_time= t-1000;}

				printf("RESOLVING TIME(in minutes): ");
				
				scanf("%d", &a[x].burst_time);
				
				a[x].remain_burst= a[x].burst_time; 

				x++;

			} else{

				printf("QUERY NAME: "); scanf("%s", &b[y].process_id);

				printf("ARRIVAL TIME(in 24 hour format): "); scanf("%d", &t); 

				if(t<1000 || t>1200){

					printf("\nSORRY SUDESH SHARMA IS BUSY AT THIS TIME\n");

					return 0;

				}

				else {b[y].arrival_time= t-1000; }

				printf("RESOLVING TIME(in minutes): ");
				
				scanf("%d", &b[y].burst_time);
				
				b[y].remain_burst= b[y].burst_time;

				y++;

			}

		}

	}

}


void RR(){;

	int time= c[0].arrival_time;
	
	int mark=0, count=0, i, rc;

	while(time!=120 && count!=z){                                                    //timeout after 2 hours = 120 minutes

		for(i=0; i<=mark;i++){

			if(c[i].remain_burst > time_quant){

				time += time_quant;

				c[i].remain_burst -= time_quant;

			}

			else if(c[i].remain_burst <=time_quant && c[i].remain_burst !=0){

				time += c[i].remain_burst;

				c[i].remain_burst =0;

				c[i].completion_time = time;

				count++;

			}

			else;

		}

		int start = mark+1;

		for(rc= start; rc<z; rc++){

			if(c[rc].arrival_time <= time){

				mark++;

			}

		}

	}	

}



void JOIN(){

	int m=0, n= 0, min, flag;                                          //counter variables

	if( x!=0  && y!=0){                                                //priorities are decided

		while(m<y && n<x){

			if(a[n].arrival_time == b[m].arrival_time){

				c[z] = a[n];

				z++;

				n++;

				c[z]= b[m];

				z++;

				m++;

			}

			else if(a[n].arrival_time < b[m].arrival_time){

				c[z]= a[n];

				z++;

				n++;

			}

			else if(a[n].arrival_time > b[m].arrival_time){

				c[z]= b[m];

				z++;

				m++;

			}

			else;

		}

		if(z != (x+y)){

			if(x!=n){

				while(n!=x){

					c[z]= a[n];

					z++;

					n++;

				}

			}

			else if(y!=m){

				while(m!=y){

					c[z]= b[m];

					z++;

					m++;

				}

			}

		}

	}

	else if(x==0){

		while(m!=y){

			c[z]= b[m];

			z++;

			m++;

		}

	}

	else if(y==0){

		while(n!=x){

			c[z]= a[n];

			z++;

			n++;

		}

	}

	else {

		printf("\n NO VALID PROCESSES AVAILABLE\n");

	}

}


void OUTPUT(){

	int i=0, total=0, sum=0; 

	float avg;

	printf("\nEXECUTION TABLE(in 24 hour format)\n");

	printf("\nQUERY NAME\tARRIVAL TIME\tRESOLVING TIME\tCOMPLETION TIME\tTURN-AROUND TIME\tWAITING TIME");

	for(i; i<z; i++){

		printf("\n%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d",

		c[i].process_id, (c[i].arrival_time+1000), c[i].burst_time, (c[i].completion_time+1000), (c[i].completion_time-c[i].arrival_time), ((c[i].completion_time-c[i].arrival_time)- c[i].burst_time));

		total= c[i].completion_time;

		sum+= (c[i].completion_time-c[i].arrival_time);

	}

	avg = sum/z;

	printf("\n\nTOTAL TIME SPENT: %d", total);

	printf("\nAVG QUERY TIME: %f", avg);

	printf("\nFINISHED");

}


void FINAL(){

			printf("Sudesh Sharma is a Linux expert who wants to have an online system where he can handle student queries. Since there can be multiple"

			" requests at any time he wishes to dedicate a fixed amount of time to every request so that everyone gets a fair share of his time."

			" He will log into the system from 10am to 12am only.  He wants to have separate requests queues for students and faculty."

			" Implement a strategy for the same. The summary at the end of the session should include the total time he spent on handling queries"

			" and average query time.\n"
			
		    );
		    
	        printf("\nASSUMPTIONS:\n"

			"\n>>>>ENTER ARRIVAL TIME AS IN 24 HOUR FORMAT\n"

			"\n>>>>ENTER YOUR QUERIES IN AN ASCENDING ORDER\n"

			"\n>>>>TIME UNIT : MINUTES\n"
			
			"\n>>>>ENTER TIME ONLY BETWEEN 10AM TO 12AM i.e. 1000 TO 1200\n"
			
			);
			
			printf("\nSOLUTION IS AS FOLLOWS :==> \n\n");

}


main(){

 	FINAL();

	INPUT();

	JOIN();

	RR();

	OUTPUT();

}
