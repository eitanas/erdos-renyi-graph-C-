#include <iostream>
#include <vector>
#include "network.hpp"
#include <fstream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

int main(int argc, char **argv) {
    std::cout << "Hello, world!" << std::endl;
    long double huge_sum;
    vector<long double> mpl,mpl_av;
    vector<int> N;
    int const k = 6;
    int num_of_simulations = 100;
    
    for (int i = 500; i<30000 ; i += 500) {// building N vector
      cout<<"building network with :" << i << "nodes" <<endl;
      huge_sum = 0;
      for (int j = 0 ; j < num_of_simulations ; j++){
	network *net = new network(i , k);
	huge_sum+=(net->MPL());
      }
      mpl_av.push_back((long double)huge_sum/num_of_simulations);
      N.push_back(i);
      
      
    }
    
    ofstream data;
    string path = "/home/eitan/projects/newER/k_6_sim_100.txt";
    const char * c_path  = path.c_str();
    data.open(c_path, ofstream::out);
    for(int i=0;i<mpl_av.size();i++)
    data<<N[i]<<"	"<<mpl_av[i]<<endl;
    data.close();
    
    return 0;
}

