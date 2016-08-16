
#include <cstdio>
#include <cmath>

struct Robot{
	int time;
	int position;
}A,B;

int abs(int x)
{
	return x>0? x : -x;
}



int main()
{
	int t,n,cost;
	scanf("%d",&t);
	int cs=0;
	while(cs++<t){
		int n;
		scanf("%d",&n);	

		cost=0;
		A.time=0;
		A.position=1;
		B.time=0;
		B.position=1;

		while(n--){
			char c=getchar();
			while(c==' '||c=='\t')c=getchar();
			int button;
			scanf("%d",&button);


			if(c=='O'){

				//printf("A.time=%d A.position=%d button=%d\n",A.time,A.position,button);
				if( A.time >= abs( button - A.position ) ){
					cost++;
					B.time++;
					A.time=0;
					A.position=button;
				}
				else{
					cost += abs(button-A.position)  - A.time +1 ;
					B.time += abs(button-A.position)  - A.time +1 ;
					A.time=0;
					A.position = button; 
				}

			}
			else if(c=='B'){
				//printf("B.time=%d B.position=%d button=%d\n",B.time,B.position,button);
				if( B.time >= abs( button - B.position ) ){
					cost++;
					A.time++;
					B.time=0;
					B.position=button;
				}
				else{
					cost += abs(button-B.position)  - B.time +1 ;
					A.time += abs(button-B.position)  - B.time +1 ;
					B.time=0;
					B.position = button; 
				}
					
			}
			else{
				while(1)puts("error");
			}
			//printf("n=%d cost=%d\n",n,cost);
		}
		
		printf("Case #%d: %d\n",cs,cost);
	
	}
	


	return 0;
}
