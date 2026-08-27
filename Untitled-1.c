#include<stdio.h>
int main(){
    int n,r,i,j,k,a,b,c;
    printf("enter no of processes:");
    scanf("%d",&n);
    r=3;
    int allocation[n][r];
    for(a=0;a<0;a++){
        printf("enter p[%d] allocation \t\t :",a);
        for(b=0;b<r;b++){
            scanf("%d",&allocation[a][b]);
        }
    }
    int max[n][r];
    for(a=0;a<n;a++){
        printf("enter p[%d] max alloc \t\t :",a);
        for(b=0;b<n;b++){
            scanf("%d",&max[a][b]);
        }
    }
    int available[3] = {3,3,2};
    int f[n],ans[n],ind=0;
    for(k=0;k<n;k++){
        f[k]=0;
    }
    int need[n][r];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
        need[i][j]=max[i][j]- allocation[i][j];
    }
    int y=0;
    for(k=0;k<5;k++){
        for(i=0;i<n;i++){
            if(f[i]==0){
                int flag=0;
                for(j=0;j<r;j++){
                    if(need[i][j] > available[i][j]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    ans[ind++]==i;
                    for(y=0;y<r;y++)
                    available[i][j]+=allocation[i][j];
                    f[i]=1;
                }
            }
        }
    }
    printf("the safe sequence is as follows : \n");
    for(i=0;i<n-1;i++)
    printf("p%d->",ans[i]);
    printf("p%d",ans[n-1]);
    return 0;
}