#include<unistd.h>
#include<stdio.h>



struct process

{

	char name;

	int at,bt,wt,tt,rt;

	int completed;

	float ntt;

}p[10], p1[10];







int n,n1;

int q[10],q1[10];  //queue

int front=-1,rear=-1, front1=-1,rear1=-1;





void enqueue(int i)

{

	if(rear==10)

		printf("overflow");

	rear++;

	q[rear]=i;

	if(front==-1)

		front=0;

}



int dequeue()

{

	if(front==-1)

		printf("underflow");

	int temp=q[front];

	if(front==rear)

		front=rear=-1;

	else

		front++;

	return temp;

}



int isInQueue(int i)

{

	int k;

	for(k=front;k<=rear;k++)

	{

		if(q[k]==i)

			return 1;

	}

	return 0;

}





void enqueue1(int i)

{

	if(rear1==10)

		printf("overflow");

	rear1++;

	q1[rear1]=i;

	if(front1==-1)

		front1=0;

}



int dequeue1()

{

	if(front1==-1)

		printf("underflow");

	int temp1=q1[front1];

	if(front1==rear1)

		front1=rear1=-1;

	else

		front1++;

	return temp1;

}

void enqueue(int i)

{

	if(rear==10)

		printf("overflow");

	rear++;

	q[rear]=i;

	if(front==-1)

		front=0;

}



int dequeue()

{

	if(front==-1)

		printf("underflow");

	int temp=q[front];

	if(front==rear)

		front=rear=-1;

	else

		front++;

	return temp;

}



int isInQueue(int i)

{

	int k;

	for(k=front;k<=rear;k++)

	{

		if(q[k]==i)

			return 1;

	}

	return 0;

}





void enqueue1(int i)

{

	if(rear1==10)

		printf("overflow");

	rear1++;

	q1[rear1]=i;

	if(front1==-1)

		front1=0;

}



int dequeue1()

{

	if(front1==-1)

		printf("underflow");

	int temp1=q1[front1];

	if(front1==rear1)

		front1=rear1=-1;

	else

		front1++;

	return temp1;

}



int isInQueue1(int i)

{

	int k;

	for(k=front1;k<=rear1;k++)

	{

		if(q1[k]==i)

			return 1;

	}

	return 0;











void main()

{

	int i,j,time=0,sum_bt=0,tq,time1=0,sum_bt1=0;

	char c,d;

	float avgwt=0, avgtt=0, avgwt1=0, avgtt1=0;

	printf("Enter no of processes in student:");

	scanf("%d",&n);



	for(i=0,c='A';i<n;i++,c++)

	{

		p[i].name=c;

		printf("Enter the arrival time and burst time of process %c: ",p[i].name);

		scanf("%d%d",&p[i].at,&p[i].bt);

		p[i].rt=p[i].bt;

		p[i].completed=0;

		sum_bt+=p[i].bt;



	}



	printf("Enter no of processes in faculty:");

	scanf("%d",&n1);



	for(i=0,d='a';i<n1;i++,d++)

	{

		p1[i].name=d;

		printf("Enter the arrival time and burst time of process %c: ",p1[i].name);

		scanf("%d%d",&p1[i].at,&p1[i].bt);

		p1[i].rt=p1[i].bt;

		p1[i].completed=0;

		sum_bt+=p1[i].bt;



	}



int tqqq;

	printf("\nEnter the time quantum:");

	scanf("%d",&tq);



	printf("Enter time quatum for queues: ");

	scanf("%d", &tqqq);



	sortByArrival();

	sortByArrival1();

	enqueue(0);          // enqueue the first process

	enqueue1(0);

	struct process *q11 = p;

	int time_qq = 0;

	int cur_pp = 0;

	int num = n;

	printf("Process execution order: ");

	for(time=q11[0].at;time<sum_bt;)       // run until the total burst time reached

	{

		int el;

		if(time_qq >= tqqq || rear == front || rear1 == front1)

		{

			if(cur_pp == 0)

			{

				cur_pp = 1;

				q11 = p1;

				num = n1;

			}

			else

			{

				cur_pp = 0;

				q11 = p;

				num = n;

			}



			time_qq = 0;

		}

		if(cur_pp == 0)

		i=dequeue();

		else

		i = dequeue1();



		el = q11[i].rt;

		if(q11[i].completed == 1){

			if(cur_pp == 0){

			q11 = p1;

			cur_pp = 1;

			num = n1;

			}

			else{

			q11 = p;

			cur_pp = 0;

			num = n;

			}

			time_qq = 0;

			continue;

		}

		if(q11[i].rt<=tq && tqqq - time_qq >= el)

		{ /* for processes having remaining time with less than or  equal  to time quantum  */

			time+=q11[i].rt;

			q11[i].rt=0;

			q11[i].completed=1;

			printf(" %c ",q11[i].name);

			q11[i].wt=time-q11[i].at-q11[i].bt;

			q11[i].tt=time-q11[i].at;

			q11[i].ntt=((float)q11[i].tt/q11[i].bt);

			for(j=0;j<num;j++)                /*enqueue the processes which have come  while scheduling */

			{

				if(q11[j].at<=time && q11[j].completed!=1)

				{

					if(cur_pp == 0) {

					if(isInQueue(j) != 1)

					enqueue(j);

					}

					else {

					if(isInQueue1(j) != 1)

					enqueue1(j);

					}

				}

			}

		}

		else               // more than time quantum

		{

			if(tqqq - time_qq < el)

			el = tqqq - time_qq;

			else

			el = tq;

			time+= el;

			q11[i].rt-=el;

			printf(" %c ",q11[i].name);

			if(q11[i].rt == 0)

				q11[i].completed = 1;



			for(j=0;j<num;j++)    /*first enqueue the processes which have come while scheduling */

			{

				if(q11[j].at<=time && q11[j].completed!=1&&i!=j)

				{

					if(cur_pp == 0) {

					if(isInQueue(j) != 1)

					enqueue(j);

					}

					else{

					if(isInQueue1(j) != 1)

					enqueue1(j);

					}

				}

			}

			if(q11[i].rt != 0){

			if(cur_pp == 0)

			enqueue(i);   // then enqueue the uncompleted process

			else

			enqueue1(i);

			}

		}



		time_qq += el;

	}





	printf("\nName\tArrival Time\tBurst Time\tWaiting Time\tTurnAround Time");

	for(i=0;i<n;i++)

	{

		avgwt+=q11[i].wt;

		avgtt+=q11[i].tt;

		printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d",q11[i].name,q11[i].at,q11[i].bt,q11[i].wt,q11[i].tt);

	}







	//printf("\nName\tArrival Time\tBurst Time\tWaiting Time\tTurnAround Time);

	for(i=0;i<n1;i++)

	{

		avgwt+=p1[i].wt;

		avgtt+=p1[i].tt;

		printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d",p1[i].name,p1[i].at,p1[i].bt,p1[i].wt,p1[i].tt);

	}



	printf("\nAverage waiting time:%f\n",avgwt/(n + n1));

	printf("Average turnaround time:%f\n",avgtt/(n + n1));



}
