#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;


double normFunction(double tab)
{   double total=0;
    for(int i=0; i<128; i++)
    {
        total+= tab * tab;
    }
    double norm=sqrt(total);
    return norm;
}

int main()
{
    double mainTab[128][128]={0};

    for(int i=0; i<128; i++)
    {
        for(int j=0; j<128; j++)
        {
            if(i==j) mainTab[i][j]={4};
            else if(j==i+1 || j==i+5 || i==j+1 || i==j+5) mainTab[i][j]={1};
        }
    }

    double rightVector[128];
    for(int i=0; i<128; i++)
    {
        rightVector[i]=1;
    }

    double vector[128];
    for(int i=0; i<128; i++)
    {
        vector[i]={0};
    }

    int maxOfIterations=25;
    int firstIteration=0;

    double tempVectorForSolutions[128]={0};

    while (firstIteration <= maxOfIterations)
    {
        for (int i = 0; i < 128; i++)
        {
            tempVectorForSolutions[i] = (rightVector[i] / mainTab[i][i]);
            for (int j = 0; j < 128; j++)
            {
                if (i == j) continue;

                tempVectorForSolutions[i] = tempVectorForSolutions[i] - ((mainTab[i][j] / mainTab[i][i]) * vector[j]);
                vector[i] = tempVectorForSolutions[i];
            }
        }
        firstIteration++;
    }
    cout << "Result: " << endl;
    for(int i=0;i<128;i++){
        cout << "x" <<i+1 << "=" << setprecision(7) << tempVectorForSolutions[i] << endl;
    }
    cout<<endl;
    cout << "Norm: " << endl;
    for(int i=1;i<128; i++)
    {
        cout << i << ")" << normFunction(vector[i] - vector[i - 1]) << "\t";
    }


    return 0;
}