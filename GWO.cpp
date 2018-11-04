#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<cstdint>
#include<fstream>
#include<numeric>
#include <iomanip>
#include <random>
#include<limits>
#include <string>
#include <bits/stdc++.h>
#include <iomanip>
#include <sstream>

using namespace std;

const double M_PI  =3.141592653589793238463; //defining the value of constant pi for future use
int len(int x[]) //length of array containig int elements
{
	return (sizeof(x)/sizeof(x[0]));
}
int lenDouble(double x[])//length of array containg double elements
{
	return (sizeof(x)/sizeof(x[0]));
}
double *power(double x[], int y) //to calculate power of each and every element of an array and returning the new array
{
	int lx=lenDouble(x);
	double *xp= new double[lx]; 
	//int xp[lx];
	for(int i=0;i<lx;i++)
	{
		xp[i]=pow(x[i],y);
	}
	return (xp);
}
double SummedUfun(double x[],int a,int k,int m)
{
	int dim=lenDouble(x);
	double y[dim];
	for (int i=0;i<dim;i++)
	{	
		if(x[i]>a)
		{
			y[i]=k*pow((x[i]-a),m);
		}
		else if(x[i]<-a)
		{
			y[i]=k*pow((-x[i]-a),m);
		}
		else
		{
			y[i]=0;
		}
	}
	double summedy=0;
	for (int i=0;i<dim;i++)
	{
		summedy=summedy+y[i];
	}
	return (summedy);
}
double prod(double a[]) //to find the product of all the element of the array
{
	int l=lenDouble(a);
	double result;
	for (int i=0;i<l;i++)
	{
		result=a[i]*result;
	}
	return result;
}
double arraySum(double a[])  //to calculate sum of all the element from the array
{
	int n = lenDouble(a); 
    double sum  = 0;
    for(int i=0;i<n;i++)
    {
    	sum=sum+a[i];
    }  
    return (sum); 
}
double F1(double x[])//c++ implementaion of sum(x**2);
{
	double fit=arraySum(power(x,2));
	return fit;
}
double F2(double x[])//c++ implementation of sum(abs(x))+prod(abs(x));
{	
	double fit=arraySum(x)+prod(x);
	return fit;
}
double max(double x[])//for calculating max element from an array
{
	int l=lenDouble(x);
	return ( *std::max_element(x, x+l) );
}
double F3(double x[])// c++ implementation of for i in range(1,dim): fit=fit+(numpy.sum(x[0:i]))**2;
{
	double dim=lenDouble(x)+1;
	double fit=0;
	int i;
	for(i=1;i<dim;i++)
	{
		double sliced[i];
		for (int j=0; j<i+1;j++)
		{
			sliced[j]=x[j];
		}
		fit=fit+pow(arraySum(sliced),2);
	}
	return fit;
}
double F4(double x[])
{
	double fit=abs(max(x));
	return fit;
}
double F5(double x[])//c++ implementation of sum(100*(x[1:dim]-(x[0:dim-1]**2))**2+(x[0:dim-1]-1)**2);
{
	int dim=lenDouble(x);
	double sliced1[dim];
	double sliced2[dim];
	for (int i=1;i<dim+1;i++)
	{	
		sliced1[i]=x[i];
		sliced2[i-1]=pow(x[i-1],2);
	}
	double slicedpower[dim];
	for (int i=0;i<dim;i++)
	{
		slicedpower[i]=100*(sliced1[i]-sliced2[i]);
	}
	double slicedpowerpower[dim];
	for (int i=0;i<dim;i++)
	{
		slicedpowerpower[i]=pow(slicedpower[i],2);
	}
	double sliced3powered[dim];
	for(int i=0;i<dim;i++)
	{
		sliced3powered[i]=pow(x[i]-1,2);
	}
	double finalarray[dim];
	for (int i=0;i<dim;i++)
	{
		finalarray[i]=slicedpowerpower[i]+sliced3powered[i];
	}
	double fit=arraySum(finalarray);  
	return fit;
}
double F6(double x[])//c++ implementation for sum(abs((x+.5))**2)
{	
	int dim=lenDouble(x);
	double chngx[dim];
	for(int i=0;i<dim;i++) 
	{
		chngx[i]=x[i]+0.5;
	}
	double fit=pow(arraySum(chngx),2);
	return fit;
}
double F7(double x[])
{
	double fit=0;
	int dim=lenDouble(x);
	for(int i=0;i<dim;i++)
	{
		fit=fit+((i+1)*pow(x[i],4)+rand()%2); //  fit=numpy.sum(w*(x**4))+numpy.random.uniform(0,1);
	}
	return fit;
}
double F8(double x[])//c++ implementation (x*sin(pow(x,1/2)))
{
	int dim=lenDouble(x);
	double arraypowered[dim];//(x*sin(pow(x,1/2)))
	for (int i=0;i<dim;i++)
	{
		arraypowered[i]=x[i]*sin(pow(x[i],1/2));
	}
	double fit=-(arraySum(arraypowered));
	return fit;
}
double F9(double x[])
{
	int dim=lenDouble(x);
	double arraypowered[dim];//pow(x,2)-10*cos(2*3.1415926*x)
	for (int i=0;i<dim;i++)
	{
		arraypowered[i]=pow(x[i],2)-10*cos(2*M_PI*x[i]);
	}
	double fit=arraySum(arraypowered)+10*dim;
	return fit;
}
double F10(double x[])//does not work as expected
{	
	/*double fit=-20*exp(-0.2*pow(arraySum(pow(x,2))/dim,
		1/2))-exp(arraySum(cos(2*3.1415926*x))/dim)+20+exp(1);*/
	int dim=lenDouble(x);
	double *arraypowered=power(x,2);
	double arraysumrooted=pow(arraySum(arraypowered)/dim,1/2); //-20*(-0.2*pow(arraySum(pow(x,2))/dim,2))) this much done
	double arraycosed[dim];
	for (int i=0;i<dim;i++)
	{
		arraycosed[i]=cos(2*M_PI*x[i]);
	}  //cos(2*3.1415926*x)  this much done
	double arraysumofcosed=arraySum(arraycosed);//arraySum(cos(2*3.1415926*x) this much done
	double fit=-20*exp(-0.2*arraysumrooted)-exp(arraysumofcosed/dim)+20+exp(1); //calculating fitness
	return fit;
}
double F11(double x[]) //c++ implementation for sum(x**2)/4000-prod(numpy.cos(x/numpy.sqrt(w)))+1; 
{
	int dim=lenDouble(x);
	double *arraysquared=power(x,2); 
	double summation=arraySum(arraysquared);//sum(x**2)
	double production=1; //at start the product will be 1
	for (int i=1;i<dim;i++)
	{
		production=production*(cos(x[i-1]/pow(i,1/2)));
	}
	float fit=(summation)/4000-production+1;
	return fit;
}
double F12(double x[])
{
	int dim=lenDouble(x);
	double slicedAndDividedbyFour[dim];/*(slice(x,1,dim-1)+1)/4*/
	for (int i=1;i<dim-1;i++)
	{
		slicedAndDividedbyFour[i]=(x[i]+1)/4;
	}
	double slicedAndDividedbyFouraddOne[dim];
	for (int i=0;i<dim;i++)
	{
		slicedAndDividedbyFouraddOne[i]=1+10*pow(sin(M_PI*(1+slicedAndDividedbyFour[i])),2);
	}/*sin(M_PI*(1+(slice(x,1,dim-1)+1)/4)*/
	double finalSummation;
	for (int i=0;i<dim;i++)
	{
		finalSummation=finalSummation+(pow(slicedAndDividedbyFour[i],2)*
								slicedAndDividedbyFouraddOne[i]);
	}
	double fit=(M_PI/dim)*(10*pow((sin(M_PI*(1+(x[0]+1/4)))),
		2)+finalSummation+pow(((x[dim-1]+1)/4),
		2))+SummedUfun(x,10,100,4);
	return fit;
}
double F13(double x[])
{
	int dim=lenDouble(x);
	double slicedminusone[dim];//slice(x,0,dim-2)
	for(int i=0;i<dim-1;i++)
	{
		slicedminusone[i]=pow(x[i]-1,2);
	}
	double slicedfrom1[dim]; //slice(x,1,dim-1)
	for (int i=0;i<dim;i++)
	{
		slicedfrom1[i]=slicedminusone[i]*(1+pow(sin(3*M_PI*x[i]),2));
	} //(power(slicedminusone,2)*(1+pow(sin(3*M_PI*slice(x,1,dim-1)),2))) this much done
	double fit=0.1*(pow(sin(3*M_PI*x[1]),2)+arraySum(slicedfrom1)+
		pow(x[dim-1]-1,2)*(1+pow(sin(2*M_PI*x[dim-1]),2)))+SummedUfun(x,5,100,4);
	return fit;
}
double F14(double x[])
{
	double aS[][25]={{-32,-16,0,16,32,-32,-16,0,16,32,-32,-16,0,
		16,32,-32,-16,0,16,32,-32,-16,0,16,32},{-32,-32,-32,
		-32,-32,-16,-16,-16,-16,-16,0,0,0,0,0,16,16,16,16,16,
		32,32,32,32,32},};
	double bS[25],H[2];
	for(int i=0;i<25;i++)
	{
		for (int j=0;j<2;j++)
		{
			H[j]=x[i]-aS[j][i];
		}
		bS[i]=arraySum(power(H,6));
	}
	double wplusBs[25];
	for (int i=0;i<24;i++)
	{
		wplusBs[i]=1/(i+1+bS[i]);
	}
	wplusBs[25]=25;
	double fit=(1/500)+pow(arraySum(wplusBs),-1);
	return (fit);
}


/*double callfunction(double** Positions, int funName,int i)
{
	double fitness;
	if (funName==0)		{double fitness=F1(Positions[i]);}
	else if (funName==1){double fitness=F2(Positions[i]);}
	else if (funName==2){double fitness=F3(Positions[i]);}
	else if (funName==3){double fitness=F4(Positions[i]);}
	else if (funName==4){double fitness=F5(Positions[i]);}
	else if (funName==5){double fitness=F6(Positions[i]);}
	else if (funName==6){double fitness=F7(Positions[i]);}
	else if (funName==7){double fitness=F8(Positions[i]);}
	else if (funName==8){double fitness=F9(Positions[i]);}
	else if (funName==9){double fitness=F10(Positions);}
	else if (funName==10){double fitness=F11(Positions);}
	else if (funName==11){double fitness=F12(Positions);}
	else if (funName==12){double fitness=F13(Positions);}
	else if (funName==13){double fitness=F14(Positions);}
	else if (funName==14){double fitness=F15(Positions);}
	else if (funName==15){double fitness=F16(Positions);}
	else if (funName==16){double fitness=F17(Positions);}
	else if (funName==17){double fitness=F18(Positions);}
	else if (funName==18){double fitness=F19(Positions);}
	else if (funName==19){double fitness=F20(Positions);}
	else if (funName==20){double fitness=F21(Positions);}
	else if (funName==21){double fitness=F22(Positions);}
	else if (funName==22){double fitness=F23(Positions);}
	return fitness;
}*/			 //NOT WORKING


int GWO(int lb,int ub,int dim,int SearchAgents_no,int Max_iter,std::ofstream& myFile)// lb,ub,dim we will get from benchmark function not from optimizer
{
	//ofstream myFile;
	//myFile.open("GWO.csv",std::ios::app);
	
	double Alpha_pos[dim];
	double Alpha_score = std::numeric_limits<double>::infinity();

	double Beta_pos[dim];
	double Beta_score = std::numeric_limits<double>::infinity();

	double Delta_pos[dim];
	double Delta_score = std::numeric_limits<double>::infinity();
	//initialize the positions of search agents
	double Positions[SearchAgents_no][dim]; //initializing the array holding the Positions of wolves 
	
	// Positions=add(prod(randomUniform(0,1,AgentsDim),(ub-lb)),(lb)) -- Equation 1
	/* ("ORIGINAL FORMULA") Positions=add(prod(randomUniform(0,1,AgentsDim),(ub-lb)),(lb)) "Implimented like below:-" */
	//this block
    std::random_device rd;
    std::mt19937_64 mt(rd());
    std::uniform_real_distribution<double> distribution(lb, ub);
    double array[SearchAgents_no][dim];

    for(int i = 0; i < SearchAgents_no; i++)
    {
    	for (int j=0;j<dim;j++)
    	{
        	double d = distribution(mt);
        	array[i][j] = d;
        }
    }
	//will perform the randomUniform function

	/* ("NOW THE EQUATION SIMPLIFIESAD: ")Positions=add(prod(array,(ub-lb)),(lb))  "it is IMPLIMENTED like below:- "*/

	//this block
	//int l=lenDouble(array);
	double productArray[SearchAgents_no][dim];
	for (int i=0;i<SearchAgents_no;i++)
	{
		for(int j=0;j<dim;j++)
		{
			productArray[i][j]=array[i][j]*(ub-lb);
		}
	}
	// will perform the prod function

	/*("NOW EQUATION FURTHER SIMPLIFIES TO:- ") Positions=add(productArray,lb) "it will be calculated like:- "*/
	//this block
	//int lpA=lenDouble(productArray);  //lpA- length of product array
	double addArray[SearchAgents_no][dim];
	for (int i=0; i<SearchAgents_no;i++)
	{
		for (int j=0;j<dim;j++)
		{
			addArray[i][j]=productArray[i][j]+lb;
		}
	}
	//will perform add function in euation
	//# Positions=addArray //randomUniform will return double values between 0 and 1

	//delete[] Positions; //deleting the old Postions array and clearing memory	//
	//double Positions[lpA]; //creating a new Poitions array with different length //
	for (int i=0;i<SearchAgents_no;i++) //coping elements from PositionsI to positions       //    assigning result of equation 1 to positions
	{																			//
		for(int j=0;j<dim;j++)
		{
			Positions[i][j]=addArray[i][j];												//					
		}
	}																			//
	double Convergence_curve[Max_iter];
	double fitness;
//	cout<<"\n--------------------------------------GWO is optimizing F1--------------------------\n";
	
	//cout<<"GWO is optimizing \" "<<objf.__name__<<"\"";
	for(int l=0;l<Max_iter;l++)
	{
		//cout<<"\n---------function---------- "<<l+1<<"\n";
		//Positions=clamp(Positions, lb, ub);
		//int q=lenDouble(Positions);
		/*int k=0;
		double positionsI[SearchAgents_no][dim];
		for (int i=0;i<SearchAgents_no;i++)
		{
			for (int j=0;j<dim;j++)
			{
				if(double(lb)<=Positions[i][j]<=double(ub))
				{
					positionsI[k]=Positions[i];
					j++;
				}
			}	
		}

		//delete[] Positions; //deleting the old Postions array and clearing memory
		//double Positions[q]; //creating a new Poitions array with different length 
		for (int i=0;i<q;i++) //coping elements from PositionsI to Positions
		{
			Positions[i]=positionsI[i];	
		}*/
		for(int i=0;i<SearchAgents_no;i++)
		{	
			//cout<< "Inside for loop 2\n ";
			//cout<<" in i<SearchAgents_no";
			//Return back the search agents that go beyond the boundries of the search space
			//Positions[i]=boost::algorithm::clamp(Positions[i], lb, ub);
			// Or #include <algorithm> std::clamp(n, lower, upper);
			//Calculate objective function for each search agent
			//double fitness=F1(Positions[i]);
			
			
			
			
			double fitness=F14(Positions[i]);
			
			
			//fitness =callfunction(Position,funName,i);  //NOT WORKING
						
			
					
			if(fitness<Alpha_score)
			{
				Alpha_score=fitness;  //Update Alpha
				//Alpha_pos=Positions[i];
				for(int z=0;z<SearchAgents_no;z++)
				{
					Alpha_pos[z]=Positions[i][z];
				}
			}

			if(fitness>Alpha_score && fitness<Beta_score)
			{
				Beta_score=fitness; //Update Beta
				//Beta_pos=Positions[i];
				for(int z=0;z<SearchAgents_no;z++)
				{
					Beta_pos[z]=Positions[i][z];
				}
			}

			if(fitness>Alpha_score && fitness>Beta_score && fitness<Delta_score)
			{
				Delta_score=fitness; //Update Delta
				//Delta_pos[i]=Positions[i];
				for(int z=0;z<SearchAgents_no;z++)
				{
					Delta_pos[z]=Positions[i][z];
				}
			}
		}
		int a=2-1*((2)/Max_iter); //'a' decreases linearly from 2 to 0 
		//Update the position of search agents including omegas
		for (int i=0;i<SearchAgents_no;i++)
		{
//			cout<<" Inside for loop 3 \n";

			for (int j=0;j<dim;j++)
			{
			//	cout<<" Inside for loop 3.1 \n";
				int r1=rand()%2;  //r1 is random number in [0,1]
				int r2=rand()%2;  //r1 is random number in [0,1]  
				int A1=2*a*r1-a; //Equation (3.3)
				int C1=2*r2; //Equation (3.4)
				int D_alpha=abs(C1*Alpha_pos[j]-Positions[i][j]);//Equation (3.5)-part 1
				int X1=Alpha_pos[j]-A1*D_alpha; //Equation (3.6)-part 1

				r1=rand()%2;
				r2=rand()%2;
				int A2=2*a*r1-a; //Equation (3.3)
				int C2=2*r2; //Equation (3.4)
				int D_beta=abs(C2*Beta_pos[j]-Positions[i][j]); //Equation (3.5)-part 2
				int X2=Beta_pos[j]-A2*D_beta; //Equation (3.6)-part 2

				r1=rand()%2;
				r2=rand()%2;
				int A3=2*a*r1-a; //Equation (3.3)
				int C3=2*r2; //Equation (3.4)
				int D_delta=abs(C2*Delta_pos[j]-Positions[i][j]); //Equation (3.5)-part 3
				int X3=Delta_pos[j]-A3*D_delta; //Equation (3.6)-part 3

				Positions[i][j]=(X1+X2+X3)/3; //Equation (3.7)
			}
		}
		//Convergence_curve [l]=Alpha_score;
		//printf("\n-----------------yoooooooo---------------\n");
		//cout<<" \n in l<Max_iter\n";	
		
		cout<< "At iteration " << l << "the best fitness is " << Alpha_score<<"\n";
	
		myFile <<Alpha_score<<',';
	}
	myFile<<endl;
}

int main(int args, char* arg[])
{
	/*bool benchmarkfunc[]={true,true,false,true,false,false,false,false,false,false,false,false,false,false,false,false,false,false
		,false,false,false,false}; *///length of benchmarkfunc array is: 23
 //not required currently as we are directly passing function name while calling GWO function
	
	int NumOfRuns=1;
	int PopulationSize=10;
	int Iterations=100;

//	time_t now = time(0);                         
//    struct tm* localtm = localtime(&now);// Convert now to tm struct for local timezone
//    char buffer[500];
//    strftime (buffer,500,"GWO at(%a %c).csv",localtm);                 //this is suoposed to create file name based on current date and time but currently not working
//	string buff=buffer;
//	cout<<buff;
	ofstream myFile;
//    myFile.open(buff.c_str(),std::ofstream::out);
	myFile.open("GWO.csv", ofstream::out);
    
	for (int i=0;i<Iterations;i++)
	{
		myFile<< "iteration "<<i<<',';			//Creating Output file and creating the first row containg column info
	}
	myFile<<endl;
	for (int j=0;j<1;j++)  //take for(int j=0;j<23;j++)  when you want more than one fitness function and uncomment the 'if' condition from below //sorry but not sure how to implement
	{
		//cout<<"\t\t iteration "<<j<<" Done \n";
		//myFile << ", , , , Run: "<<NumOfRuns<< ", , , ";
		//if(benchmarkfunc[j]==true)
		//{		
			for(int k=0;k<NumOfRuns;k++)
			{
				GWO(-100,100,30,PopulationSize,Iterations,myFile);
				//Flag=true;
			}
		//}
	}
	myFile.close();
	
	
	return 0;
}
