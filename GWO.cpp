#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<cstdint>
#include<numeric>
#include <iomanip>
#include <random>
#include<limits>
#include <fstream>
#include <bits/stdc++.h> 
using namespace std;
int len(int x[])
{
	return (sizeof(x)/sizeof(x[0]));
}
int lenDouble(double x[])
{
	return (sizeof(x)/sizeof(x[0]));
}
int *power(int x[], int y)
{
	int lx=len(x);
	int *xp= new int[lx]; 
	//int xp[lx];
	for(int i=0;i<lx;i++)
	{
		xp[i]=pow(x[i],y);
	}
	return (xp);
}
int arraySum(int a[])  
{
	int n = len(a); 
    int sum  = 0;
    for(int i=0;i<n;i++)
    {
    	sum=sum+a[i];
    }  
    return (sum); 
}
int F1(int x[])
{
	float fit=arraySum(power(x,2));
	return fit;
}

//float GWO(string objf,float lb,float ub,float dim,
//	float SearchAgents_no,float Max_iter);//obif, lb,ub,dim we will get from benchmark function not from optimizer

/*double *randomUniform(int lb1, int ub1, int length )  //for slicing the elements from array which are out of bound
{
	const double lb=lb1;
	const double ub=ub1;
    std::random_device rd;
    std::mt19937_64 mt(rd());
    std::uniform_real_distribution<double> distribution(lb, ub);
    double array[length];

    for(int i = 0; i < length; i++)
    {
        double d = distribution(mt);
        array[i] = d;
    }
	return (array);
}
double *prod(double a[], int p)
{
	int l=lenDouble(a);
	double resultArray[l];
	for (int i=0;i<l;i++)
	{
		resultArray[i]=a[i]*p;
	}
	return resultArray;
}
double *add(double a[], int ad)
{
	int l=lenDouble(a);
	double resultArray[l];
	for (int i=0; i<l;i++)
	{
		resultArray[i]=a[i]+ad;
	}
	return resultArray;
}*/
/*double *clamp(double positions[], int lb, int ub)
{
	int l=lenDouble(positions);
	int j=0;
	double positionsI[l];
	for (int i=0;i<l;i++)
	{
		if(double(lb)<=positions[i]<=double(ub))
		{
			positionsI[j]=positions[i];
			j++;
		}	
	}
	return positionsI;	
}*/
int GWO(int lb,int ub,int dim,int SearchAgents_no,int Max_iter)//obif, lb,ub,dim we will get from benchmark function not from optimizer
{
	double Alpha_pos[dim];
	double Alpha_score = std::numeric_limits<double>::infinity();
	//float Alpha_score=std::numeric_limits<float>::infinity();

	double Beta_pos[dim];
	double Beta_score = std::numeric_limits<double>::infinity();

	double Delta_pos[dim];
	double Delta_score = std::numeric_limits<double>::infinity();
	//initialize the positions of search agents
	int AgentsDim=SearchAgents_no*dim;
	double Positions[AgentsDim]; //initializing the array holding the Positions of wolves 
	
	// Positions=add(prod(randomUniform(0,1,AgentsDim),(ub-lb)),(lb)) -- Equation 1
	/* ("ORIGINAL FORMULA") Positions=add(prod(randomUniform(0,1,AgentsDim),(ub-lb)),(lb)) "Implimented like below:-" */
	//this block
    std::random_device rd;
    std::mt19937_64 mt(rd());
    std::uniform_real_distribution<double> distribution(lb, ub);
    double array[AgentsDim];

    for(int i = 0; i < AgentsDim; i++)
    {
        double d = distribution(mt);
        array[i] = d;
    }
	//will perform the randomUniform function

	/* ("NOW THE EQUATION SIMPLIFIESAD: ")Positions=add(prod(array,(ub-lb)),(lb))  "it is IMPLIMENTED like below:- "*/

	//this block
	int l=lenDouble(array);
	double productArray[l];
	for (int i=0;i<l;i++)
	{
		productArray[i]=array[i]*(ub-lb);
	}
	// will perform the prod function

	/*("NOW EQUATION FURTHER SIMPLIFIES TO:- ") Positions=add(productArray,lb) "it will be calculated like:- "*/
	//this block
	//int lpA=lenDouble(productArray);  //lpA- length of product array
	double addArray[l];
	for (int i=0; i<l;i++)
	{
		addArray[i]=productArray[i]+lb;
	}
	//will perform add function in euation
	//# Positions=addArray //randomUniform will return double values between 0 and 1

	//delete[] Positions; //deleting the old Postions array and clearing memory	//
	//double Positions[lpA]; //creating a new Poitions array with different length //
	for (int i=0;i<l;i++) //coping elements from PositionsI to positions       //    assigning result of equation 1 to positions
	{																			//
		Positions[i]=addArray[i];												//					
	}																			//
/*for for for for for for for for for for for for for for for for for for for for for for for for for for for for for for for for for  
for for for for for for for for for for for for for for for for for for for for for for for for for for for for for for for for for 
for for for for for for for for for for for for for for for for for for for for for for for for for for for for for for for for for  
for for for for for for for for for for for for for for for for for for for for for for for for for for for for for for for for for */
	double Convergence_curve[Max_iter];
	
	cout<<"\n--------------------------------------GWO is optimizing F1--------------------------\n";
	
	//cout<<"GWO is optimizing \" "<<objf.__name__<<"\"";
	for(int l=0;l<Max_iter;l++)
	{
		//Positions=clamp(Positions, lb, ub);
		int q=lenDouble(Positions);
		int j=0;
		double positionsI[q];
		for (int i=0;i<l;i++)
		{
			if(double(lb)<=Positions[i]<=double(ub))
			{
				positionsI[j]=Positions[i];
				j++;
			}	
		}
		//delete[] Positions; //deleting the old Postions array and clearing memory
		//double Positions[q]; //creating a new Poitions array with different length 
		for (int i=0;i<q;i++) //coping elements from PositionsI to Positions
		{
			Positions[i]=positionsI[i];	
		}	
		for(int i=0;i<SearchAgents_no;i++)
		{	
			//Return back the search agents that go beyond the boundries of the search space
			//Positions[i]=boost::algorithm::clamp(Positions[i], lb, ub);
			// Or #include <algorithm> std::clamp(n, lower, upper);
			//Calculate objective function for each search agent
			
			double fitness=2.0;  //objf(Positions[i]);

			if(fitness<Alpha_score)
			{
				Alpha_score=fitness;  //Update Alpha
				Alpha_pos[i]=Positions[i];
			}

			if(fitness>Alpha_score && fitness<Beta_score)
			{
				Beta_score=fitness; //Update Beta
				Beta_pos[i]=Positions[i];
			}

			if(fitness>Alpha_score && fitness>Beta_score && fitness<Delta_score)
			{
				Delta_score=fitness; //Update Delta
				Delta_pos[i]=Positions[i];
			}
		}

		int a=2-1*((2)/Max_iter); //'a' decreases linearly from 2 to 0 
		//Update the position of search agents including omegas
		for (int i=0;i<SearchAgents_no;i++)
		{
			for (int j=0;j<dim;j++)
			{
				int r1=rand()%2;  //r1 is random number in [0,1]
				int r2=rand()%2;  //r1 is random number in [0,1]  
				int A1=2*a*r1-a; //Equation (3.3)
				int C1=2*r2; //Equation (3.4)
				int D_alpha=abs(C1*Alpha_pos[j]-Positions[i*j]);//Equation (3.5)-part 1
				int X1=Alpha_pos[j]-A1*D_alpha; //Equation (3.6)-part 1

				r1=rand()%2;
				r2=rand()%2;
				int A2=2*a*r1-a; //Equation (3.3)
				int C2=2*r2; //Equation (3.4)
				int D_beta=abs(C2*Beta_pos[j]-Positions[i*j]); //Equation (3.5)-part 2
				int X2=Beta_pos[j]-A2*D_beta; //Equation (3.6)-part 2

				r1=rand()%2;
				r2=rand()%2;
				int A3=2*a*r1-a; //Equation (3.3)
				int C3=2*r2; //Equation (3.4)
				int D_delta=abs(C2*Delta_pos[j]-Positions[i*j]); //Equation (3.5)-part 3
				int X3=Delta_pos[j]-A3*D_delta; //Equation (3.6)-part 3

				Positions[i*j]=(X1+X2+X3)/3; //Equation (3.7)
			}
		}
		//Convergence_curve [l]=Alpha_score;

		cout<< "At iteration " << l << "the best fitness is " << Alpha_score<<"\n";
	}
}

int main(int args, char* arg[])
{
	/*bool benchmarkfunc[]={true,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false
		,false,false,false,false}; //length of benchmarkfunc array is: 23
 //not required currently as we are directly passing F1 function name while calling GWO function
	*/
	int NumOfRuns=1;
	int PopulationSize=50;
	int Iterations=100;

	//bool Export=false; for exporting results

	//bool Flag=false;

	for (int j=0;j<23;j++)
	{
		for(int k=0;k<NumOfRuns;k++)
		{
			GWO(-100,100,30,PopulationSize,Iterations);
			//Flag=true;
		}
	}
}
