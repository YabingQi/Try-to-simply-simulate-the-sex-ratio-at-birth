#include <stdio.h>
#include <stdlib.h>
struct Family {
	int childNum;
	int boy;
	int girl;
};

int main()
{
	int n = 10000;
	int girlNum = 0;
	int boyNum = 0;
	int a[4][2];
	for(int i=0;i<4;i++) {
		a[i][0]=0;
		a[i][1]=0;
	}
	struct Family* families = malloc(n*sizeof(struct Family));
	for(int i=0;i<n;i++) { 
		families[i].childNum = 0;
		families[i].boy = 0;
		families[i].girl = 0;
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<4;j++) {
			int k = random()%2;
			if(k==1) {
				families[i].childNum++;
				families[i].boy++;
				boyNum++;
				a[j][1]++;
				break;
			} else if (k==0&&j!=3){
				families[i].childNum++;
				families[i].girl++;
				girlNum++;
				a[j][0]++;
			} else if(j==3) {
				j--;
			}
		}
	}
    printf("girl:%d, boy:%d\n",girlNum,boyNum);
	printf("first child: girl:%d, boy:%d\n",a[0][0],a[0][1]);
	printf("second child: girl:%d, boy:%d\n",a[1][0],a[1][1]);
	printf("third child: girl:%d, boy:%d\n",a[2][0],a[2][1]);
	printf("forth child: girl:%d, boy:%d\n",a[3][0],a[3][1]);
   
   return 0;
}