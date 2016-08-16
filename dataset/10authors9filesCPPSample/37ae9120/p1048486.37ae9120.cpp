

#include <cstdio>
#include <cstring>


char strs[110][110];

double wp[110], owp[110],oowp[110],rp[110],total[110];

int main()
{
	int T,cs=0;
	scanf("%d",&T);
	while(cs++<T){
		memset(wp,0,sizeof (wp));	
		memset(owp,0,sizeof (owp));	
		memset(oowp,0,sizeof (oowp));	
		
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%s",strs[i]);
		}
		
		for(int i=0;i<n;++i){
			int win=0,fail=0;
			for(int j=0;j<n;++j){
				if(strs[i][j]=='1')win++;
				if(strs[i][j]=='0')fail++;
			}
			total[i]=win+fail;
			wp[i]=(double)win/(win+(double)fail);

			//printf("i=%d win=%d fail=%d wp[i]=%lf total[i]=%lf\n",i,win,fail,wp[i],total[i]);
		}

		for(int i=0;i<n;++i){
			int ct=0;
			double sum=0;
			for(int j=0;j<n;++j){
				if(strs[i][j]!='.'){
					double temp;	
					if(strs[i][j]=='1')
						temp=wp[j]*total[j]/(total[j]-1.0);
					else
						temp=(wp[j]*total[j]-1.0)/(total[j]-1.0);
					
					//printf("j=%d temp=%lf : wp[j]=%lf total[j]=%lf\n",j,temp,wp[j],total[j]);

					sum+=temp;
					//sum+=wp[j];
					ct++;	
				}
			}
			owp[i]=(double)sum/ct;
			//printf("i=%d owp[i]=%lf\n",i,owp[i]);
		}

		
		for(int i=0;i<n;++i){
			int ct=0;
			double sum=0;
			for(int j=0;j<n;++j){
				if(strs[i][j]!='.'){
					sum+=owp[j];
					ct++;	
				}
			}
			oowp[i]=(double)sum/ct;
			//printf("i=%d oowp[i]=%lf\n",i,oowp[i]);
		}
		

		for(int i=0;i<n;++i){
			rp[i] = 0.25*wp[i]+0.5*owp[i]+0.25*oowp[i];
		}


		printf("Case #%d:\n",cs);
		for(int i=0;i<n;++i)printf("%.7lf\n",rp[i]);
	
	}


	return 0;
}
