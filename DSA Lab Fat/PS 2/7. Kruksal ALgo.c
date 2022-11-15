#include<stdio.h>
#include<conio.h>
#define MAX 30
 
typedef struct edge{
    int u,v,w;
}edge;
 
edge elist[MAX];
int set[MAX]; 
int n;

void updateset(int c1,int c2) {
    int i;
    for(i=0;i<=n;i++)
        if(set[i]==c1)
            set[i]=c2;
}
 
int main() {
    int i,j,s,d,w,total_cost=0,n_edges,e1,e2;
    
    printf("\nEnter number of vertices:");
    
    scanf("%d",&n);
    n_edges=n*(n-1);
    
    for(i=0;i<n_edges;i++)
    {
      printf("enter the source and destination and cost\n");
      scanf("%d%d",&s,&d);
      if(s==0 && d==0)
        break;
      else
      {
      printf("enter the weight\n");
      scanf("%d",&w);
      elist[i].u=s;
      elist[i].v=d;
      elist[i].w=w;
      }
    }
    n_edges=i;
    edge temp;   
    for(i=0;i<n_edges-1;i++)
        for(j=i+1;j<n_edges;j++)
            if(elist[i].w>elist[j].w)
            {
                temp=elist[j];
                elist[j]=elist[i];
                elist[i]=temp;
            }
    for(i=0;i<n_edges;i++)
    printf("%d %d %d \n",elist[i].u,elist[i].v,elist[i].w);
    printf("spanning tree %d nr edges\n",n_edges);
    for(i=0;i<=n;i++)
        set[i]=i;
    int added_edges=0;
    
    for(i=0;i<n_edges;i++)
    {
        e1=set[elist[i].u];
        e2=set[elist[i].v];
        
        if(e1!=e2)
        {
            printf("%d %d %d \n",elist[i].u,elist[i].v,elist[i].w);
            added_edges++;
            updateset(e1,e2);
            total_cost+=elist[i].w;
        }
        if(added_edges>=n-1)
          break;
    }
    printf("cost=%d\n",total_cost);
    
}
