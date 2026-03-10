#include <stdio.h>
int main()
{
 int pages[50], frames[10];
 int n, f, i, j, k, flag, faults=0;
 int pos, farthest, index;
 printf("Enter number of pages: ");
 scanf("%d",&n);
 printf("Enter page reference string:\n");
 for(i=0;i<n;i++)
 scanf("%d",&pages[i]);
 printf("Enter number of frames: ");
 scanf("%d",&f);
 for(i=0;i<f;i++)
 frames[i] = -1;
 for(i=0;i<n;i++)
 {
 flag=0;
 for(j=0;j<f;j++)
 {
 if(frames[j]==pages[i])
 {
 flag=1;
 break;
 }
 }
 if(flag==0)
 {
 if(i<f)
 {
 frames[i]=pages[i];
 faults++;
 }
 else
 {
 farthest=-1;
 for(j=0;j<f;j++)
 {
 index=-1;
 for(k=i+1;k<n;k++)
 {
 if(frames[j]==pages[k])
 {
 index=k;
 break;
 }
 }
 if(index==-1)
 {
 pos=j;
 break;
 }
 if(index>farthest)
 {
 farthest=index;
 pos=j;
 }
 }
 frames[pos]=pages[i];
 faults++;
 }
 }
 }
 printf("Total Page Faults = %d",faults);
 return 0;
}
