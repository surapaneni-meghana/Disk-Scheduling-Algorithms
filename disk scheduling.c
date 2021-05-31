#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int queue[20],n,head,i,j,k;
int seek=0,max,diff;
float avg;

void sort(int queue[20])
{
   int temp;
   for(i=1;i<=n;i++)
   {
     for(j=i+1;j<=n;j++)
     {
     	if(queue[i]>queue[j])
     	{
	     	temp=queue[i];
	     	queue[i]=queue[j];
	     	queue[j]=temp;
     	}
     }
   }	
}

void FCFS()
{
      queue[0]=head;
      printf("\nSeek sequence..\n");
      for(j=0;j<n;j++)
     {
        diff=abs(queue[j+1]-queue[j]);
        seek+=diff;
        if(j>0)
          printf("%d ",queue[j]); 	
    }
    printf("%d ",queue[j]); 
    printf("\nTotal seek time =%d\n",seek);
    avg=seek/(float)n;
    printf("Average seek time =%f\n",avg);
    seek=0;
}

void SSTF()
{
   int t[20],h;
   h=head;
   int c=0,k,v[20];
   for(i=1;i<=n;i++)
      v[i]=0;
   printf("\nSeek sequence..\n");
   while(c<n)
   {
       int min=999;
       for(i=1;i<=n;i++)
           if(min>abs(h-queue[i]) && !v[i]){
   	   min=abs(h-queue[i]);
   	   k=i;
           }
      seek=seek+min;
      h=queue[k];
      v[k]=1; 
      printf("%d ",queue[k]); 
      c++;	  
   }
    printf("\nTotal seek time =%d\n",seek);
    avg=seek/(float)n;
    printf("Average seek time =%f\n",avg);	
    seek=0;
}

void SCAN()
{
   sort(queue);
   int h=head;
   printf("\nSeek sequence..\n");
   for(i=1;i<=n;i++)
         if(h < queue[i])
              break;
   for(j=i-1;j>=1;j--)
   {
      seek=seek+abs(h-queue[j]);
      printf("%d ",queue[j]); 	
      h=queue[j];
   }
   seek+=h;
   h=0;
   printf("%d ",h);
   for(j=i;j<=n;j++)
   {
        seek=seek+abs(h-queue[j]);
        printf("%d ",queue[j]); 	
        h=queue[j];
   }
    printf("\nTotal seek time =%d\n",seek);
    avg=seek/(float)n;
    printf("Average seek time =%f\n",avg);	
    seek=0;
}

void CSCAN()
{
   sort(queue);
   int h=head;
   printf("\nSeek sequence..\n");
   for(i=1;i<=n;i++)
      if(h < queue[i])
          break;
   for(j=i;j<=n;j++)
   {
      seek=seek+abs(h-queue[j]);
      printf("%d ",queue[j]); 	
      h=queue[j];
   }
   seek+=abs(h-max-1);
   h=max-1;
   printf("%d ",h);
   seek+=h;
   h=0;
   printf("%d ",h);
   for(j=1;j<i;j++)
   {
        seek=seek+abs(h-queue[j]);
        printf("%d ",queue[j]); 	
        h=queue[j];
    }
    printf("\nTotal seek time =%d\n",seek);
    avg=seek/(float)n;
    printf("Average seek time =%f\n",avg);	
    seek=0;
}

void LOOK()
{
   sort(queue);
   int h=head;
   printf("\nSeek sequence..\n");
   for(i=1;i<=n;i++)
      if(h < queue[i])
           break;
   for(j=i-1;j>=1;j--)
   {
      seek=seek+abs(h-queue[j]);
      printf("%d ",queue[j]); 	
      h=queue[j];
   }
   for(j=i;j<=n;j++)
   {
        seek=seek+abs(h-queue[j]);
        printf("%d ",queue[j]); 	
        h=queue[j];
   }
    printf("\nTotal seek time =%d\n",seek);
    avg=seek/(float)n;
    printf("Average seek time =%f\n",avg);	
    seek=0;
}

void CLOOK()
{
   sort(queue);
   int h=head;
   printf("\nSeek sequence..\n");
   for(i=1;i<=n;i++)
       if(h < queue[i])
           break;
   for(j=i;j<=n;j++)
   {
      seek=seek+abs(h-queue[j]);
      printf("%d ",queue[j]); 	
      h=queue[j];
   }
   for(j=1;j<i;j++)
   {
       seek=seek+abs(h-queue[j]);
       printf("%d ",queue[j]); 	
       h=queue[j];
    }
    printf("\nTotal seek time =%d\n",seek);
    avg=seek/(float)n;
    printf("Average seek time =%f\n",avg);	
    seek=0;
}

int main()
{
     int ch;
     printf("Enter the max range of disk :\n");
     scanf("%d",&max);
     printf("Enter size of queue request :\n");
     scanf("%d",&n);
     printf("Enter queue of disk positions :\n");
     for(i=1;i<=n;i++)
         scanf("%d",&queue[i]);
     printf("Enter initial head position :\n");
     scanf("%d",&head);
     while(1)
     {
          printf("\n 1.FCFS 2.SSTF 3.SCAN 4.C-SCAN 5.LOOK 6.C-LOOK\n");
          scanf("%d",&ch);
          switch(ch)
         {	
              case 1:
  	      printf("FCFS\n");
  	      printf("------------------------");
	      FCFS();
	      printf("------------------------\n");
	      break;
              case 2:
	      printf("SSTF\n");
  	      printf("------------------------");
	      SSTF();
	      printf("------------------------\n");
	      break;
              case 3:
                         printf("SCAN\n");
  	      printf("------------------------");
                         SCAN();
                         printf("------------------------\n");
                         break;
              case 4:
                         printf("C-SCAN\n");
  	      printf("------------------------");
                         CSCAN();
                         printf("------------------------\n");
                         break;
              case 5:
                         printf("LOOK\n");
  	      printf("------------------------");
                         LOOK();
                         printf("------------------------\n");
                         break;
              case 6:
                         printf("C-LOOK\n");
  	      printf("------------------------");
                        CLOOK();
                        printf("------------------------\n");
                        break;
              case 7:
	     exit(1); 
	     break; 	
          }	
     }
     return 0;
}