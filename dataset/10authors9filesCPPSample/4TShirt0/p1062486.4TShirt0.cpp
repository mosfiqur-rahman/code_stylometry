#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

const int maxd = 10005;
const int maxl = 104;

int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("B-small-attempt1.out","w",stdout);
	int t;
	cin >> t;
	for (int cases=1;cases<=t;cases++)
	{
		int n,m;
		cin >> n >> m;
		string dic[maxd];
		string lis[maxl];
		for (int i=0;i<n;i++)
		{
			cin >> dic[i];
		}
		for (int i=0;i<m;i++)
		{
			cin >> lis[i];
		}
		vector<string> res;
		for (int i=0;i<m;i++)
		{
			int maxlen = -1,maxindex = 0;
			for (int j=0;j<n;j++)
			{
				string tmpstr = dic[j];
				int diclen = tmpstr.length();
				bool flag[maxd] = { false };
				for (int k=0;k<n;k++)
				{
					if (diclen != dic[k].length())
					{
						flag[k] = true;
					}
				}
				vector<int> pos;vector<char> alp;
				int start = 0,points=0;
				while(alp.size() < diclen && start<26)
				{
					bool show = false;
					for (int k=0;k<n && show==false;k++)
					{
						if (flag[k] == false)
						{
							for (int ii=0;ii<dic[k].length();ii++)
							{
								if (dic[k][ii] == lis[i][start])
								{
									show = true;break;
								}
							}
						}
					}
					if (show==false)
					{
						for (int k=0;k<n;k++)
						{
							if (flag[k] == false)
							{
								for (int kk =0;kk<dic[k].length();kk++)
								{
									if (dic[k][kk] == lis[i][start])
									{
										flag[k] = true;break;
									}
								}
							}
						}
						start++;
					}
					else
					{
						bool isshow = false;
						for (int k=0;k<tmpstr.length();k++)
						{
							if (tmpstr[k] == lis[i][start])
							{
								isshow=true;pos.push_back(k);alp.push_back(tmpstr[k]);
							}
						}
						if (isshow)
						{
							for (int k=0;k<n;k++)
							{
								if (flag[k] == false)
								{
									for (int kk=0;kk<alp.size();kk++)
									{
										if (dic[k][pos[kk]] != alp[kk])
										{
											flag[k] = true;break;
										}
									}
								}
							}
						}
						else points++;
						start ++;
					}
				}
				if (points > maxlen)
				{
					maxlen = points;
					maxindex = j;
				}
			}
			res.push_back(dic[maxindex]);
		}
		printf("Case #%d:",cases);
		for (int i=0;i<m;i++)
		{
			//printf(" %s",res[i]);
			cout <<" "<<res[i];
		}
		printf("\n");
	}
	return 0;
}