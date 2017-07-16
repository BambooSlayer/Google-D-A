 
    #include <iostream>  // includes cin to read from stdin and cout to write to stdout
using namespace std;  // since cin and cout are both in namespace std, this saves some text
int DD(const int N,const int j,int Tnow,const int S[16],const int F[16],const int D[16] ,const int Ts,const int Tf,const int sum) {
	//if(Tnow>Tf)return 0;//如果赶不上，那就不成功
	if(j==N-1){
		if(Tnow<=Tf)
		{return sum;}
		else return -1;
	}
	int BUS,K,BK;
	if(Tnow-S[j]>0){BUS=S[j]+((Tnow-S[j]-1)/(F[j])+1)*F[j];}//计算直接走的上车时间
	else BUS=S[j];
	BK=BUS+D[j];//加上行进时间 不看的话，下个城市的Tnow
	if(BK>Tf)return -1;//如果不看都赶不上，那就不成功
	BK=DD(N,j+1,BK,S,F,D,Ts,Tf,sum);
	//go see
	Tnow+=Ts;
	if(Tnow-S[j]>0){BUS=S[j]+((Tnow-S[j]-1)/F[j]+1)*F[j];}//计算看完走的上车时间
	else BUS=S[j];
	K=BUS+D[j];//加上行进时间 看的话，下个城市的Tnow
	
	//if(BK<=Tf)
	
	//else BK=-1;
	
	if(K<=Tf)K=DD(N,j+1,K,S,F,D,Ts,Tf,sum+1);
	else {return BK;}

	if(BK>=K)return BK;
	else return K;
}
int main() {
  int t, N, Ts, Tf,sum=0;
  cin >> t;  // read t. cin knows that t is an int, so it reads it as such.
 
  int S[16],F[16],D[16];
  int BUS,x,Tnow,T1,T2;
  for (int i = 1; i <= t; ++i) { 
	cin >> N >> Ts >> Tf;
	for (int j = 0; j < N-1; ++j) { 
	    cin >> S[j] >> F[j]>> D[j];  // read n and then m.
	}
	Tnow=0;
	sum=DD(N,0,Tnow,S,F,D,Ts,Tf,0);
	if(sum == -1){
		cout << "Case #" << i << ": " << "IMPOSSIBLE" << endl;
	}
	else
	{
		cout << "Case #" << i << ": " << sum << endl;
	}
    // cout knows that n + m and n * m are ints, and prints them accordingly.
    // It also knows "Case #", ": ", and " " are strings and that endl ends the line.
  }

  return 0;
}
       