#include<iostream.h>
#include <boost/algorithm/clamp.hpp>
#include<cstlib.h>
using namespace std;
int randomUniform(int lb, int ub,int length )
{
	const int length = length;
	const int lb=lb;
	const int ub=ub;
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

int main(obif,lb,ub,dim,SearchAgents_no,Max_iter)
{
	float Alpha_pos[dim];
	float Alpha_score=std::numeric_limits<float>::infinity;

	float Beta_pos[dim];
	float Beta_score=std::numeric_limits<float>::infinity;

	float Delta_pos[dim];
	float Delta_score=std::numeric_limits<float>::infinity;
	//initialize the positions of search agents
	float Positions[]=randomUniform(0,1,(SearchAgents_no*dim))*(ub-lb)+lb

	float Convergence_curve[Max_iter];

	cout<<"GWO is optimizing \" "<<objf.__name__<<"\"";
	for(int l=0;l<Max_iter;l++)
	{
		for(int i=0;i<SearchAgents_no;i++)
		{	
			//Return back the search agents that go beyond the boundries of the search space
			Positions[i]=boost::algorithm::clamp(Positions[i], lb, ub);
			// Or #include <algorithm> std::clamp(n, lower, upper);
			//Calculate objective function for each search agent
			float fitness[]=objf(Positions[i]);

			if(fitness<Apha_score)
			{
				Alpha_score=fitness;  //Update Alpha
				Alpha_pos=Positions[i];
			}

			if(fitness>Alpha_score && fitness<Beta_score)
			{
				Beta_score=fitness; //Update Beta
				Beta_pos=Positions[i];
			}

			if(fitness>Alpha_score && fitness>Beta_score && fitness<Delta_score)
			{
				Delta_score=fitness; //Update Delta
				Delta_pos=Positions[i];
			}
		}

		float a=2-1*((2)/Max_iter); //'a' decreases linearly from 2 to 0 
		//Update the position of search agents including omegas
		for (int i=0;i<SearchAgents_no;i++)
		{
			for (int j=0;j<dim;j++)
			{
				int r1=rand()%2;  //r1 is random number in [0,1]
				int r2=rand()%2;  //r1 is random number in [0,1]  
				int A1=2*a*r1-a; //Equation (3.3)
				int C1=2*r2; //Equation (3.4)
				int D_alpha=abs(C1*Alpha_pos[j]-Positions[i,j]);//Equation (3.5)-part 1
				int X1=Alpha_pos[j]-A2*D_alpha; //Equation (3.6)-part 1

				int r1=rand()%2;
				int r2=rand()%2;
				int A2=2*a*r1-a; //Equation (3.3)
				int C2=2*r2; //Equation (3.4)
				int D_beta=abs(C2*Beta_pos[j]-Positions[i,j]); //Equation (3.5)-part 2
				int X2=Beta_pos[j]-A2*D_beta; //Equation (3.6)-part 2

				int r1=rand()%2;
				int r2=rand()%2;
				int A3=2*a*r1-a; //Equation (3.3)
				int C3=2*r2; //Equation (3.4)
				int D_delta=abs(C2*Delta_pos[j]-Positions[i,j]); //Equation (3.5)-part 3
				int X3=Delta_pos[j]-A2*D_delta; //Equation (3.6)-part 3

				float Positions[i,j]=(X1+X2+X3)/3; //Equation (3.7)
			}
		}
		Convergence_curve[l]=Alpha_score;

		if (l%1==0)
		{
			cout<<'At iteration '<< l <<'the best fitness is '<< Alpha_score;
		}
	}
}