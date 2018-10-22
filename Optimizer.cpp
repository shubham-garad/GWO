#include<iostream>
#include<string>
#include <cstdlib>
using namespace std;

/*int selector(algo,func_details,popSize,Iter)
{
	string function_name=func_details[0];
	*or string function_name;
	  	getline(func_details[0],function_name);*

	float lb=func_details[1];
	float ub=func_details[2];
	float dim=func_details[3];

	//x=GWO(,lb,ub,dim,popSize,Iter)  Incomplete need to think another way

	//return x;  not sure
}
*/
int len(int x[])
{
	return (sizeof(x)/sizeof(x[0]));
}
int main(char args, char* arg[])
{
	bool F1=true;
	bool F2=true;
	bool F3=true;
	bool F4=true;
	bool F5=true;
	bool F6=true;
	bool F7=true;
	bool F8=true;
	bool F9=true;
	bool F10=true;
	bool F11=true;
	bool F12=true;
	bool F13=true;
	bool F14=true;
	bool F15=true;
	bool F16=true;
	bool F17=true;
	bool F18=true;
	bool F19=true;
	bool F20=true;
	bool F21=true;
	bool F22=true;

	int benchmarkfunc[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22}; 

	int NumOfRuns=1;
	int PopulationSize=50;
	int Iterations=100;

	bool Export=false; //for exporting results

	bool Flag=false;

	for (int j=0;j<len(benchmarkfunc);j++)
	{
		if(benchmarkfunc[j]==true)
		{
			for(int k=0;k<NumOfRuns)
			{
				GWO(benchmarkfunc[j],PopulationSize,Iterations);
				Flag=true;
			}
		}
	}
}