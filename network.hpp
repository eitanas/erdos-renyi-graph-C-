    #include <iostream>
    #include <vector>
    #include <time.h>
    #include <stdio.h>      /* printf, scanf, puts, NULL */
    #include <stdlib.h>     /* srand, rand */
    #include <string>
    #include <stdexcept>
    #include <queue>
    using namespace std;


    class network{
	public:
	  int n,k,p;
	  vector < vector<int> > adj_list;
	  network(int n , int k);
	  bool is_connected(int n1, int n2);
	  vector<long int>  BFS(int source);
	  long double MPL();
	  long double avg_distances(int s);   
	};
	
	//c'tor
	network::network(int N , int K){
	  n = N;
	  k = K;
	  
	  //initializing empty vectors 
	  for (int i=0; i<n ; i++){
	    vector<int> v;
	    adj_list.push_back(v);
	  }
	  srand(time(0));
	  int r1,r2;
	  for (int i=0; i<n*k/2; i++){
	    r1 = rand() % n;
	    r2 = rand() % n;
	    
	    if(!is_connected(r1,r2)  && r1!=r2){
	      adj_list[r1].push_back(r2);
	      adj_list[r2].push_back(r1);
	    }
	  }
	}

	bool network::is_connected(int n1, int n2){
	  for (int i = 0 ; i < adj_list[n1].size() ; i++ ){
	    if (adj_list[n1][i] == n2)
	      return true;	
	  }
	  return false;
	}

	
    vector<long int> network::BFS(int s){
      //this function returns the sum of all the distances from edge u to any other edge v
      //divided by the number of edges (average path length)
      //adjList is the same as adj_list , just inside the function
      bool visited[n];
      int distance[n];
      
      long int sum = 0 , counter = 0;
      vector<long int> results;
      for (int i=0 ; i<n ; i++){
	visited[i] = 0;
	distance[i] = -1;
      }
      
      
      // memset(visited,0,sizeof visited);
      //memset(distance,-1,sizeof distance);
      distance[0] = 0;
      visited[0] = 1;
      queue <int> bfsq;
      bfsq.push(s);
      
      while (!bfsq.empty()){
	int u = bfsq.front();
	bfsq.pop();
	
	//looking at all neighbors of u
	for (int i = 0; i < adj_list[u].size() ; i++){
	    int v = adj_list[u][i];
	    
	    if (!visited[v]){
	      visited[v] = 1;
	      distance[v] = distance[u] + 1;
	      bfsq.push(v);
	      
	      sum  += distance[v];
	      counter += 1;
	    }   
	} 
      }
	
	results.push_back(sum);
	results.push_back(counter);
	return results;
    }
    
    long double network::MPL(){
      
      long double sum = 0, counter = 0;
      vector <long int> mpl_v;
      for ( int i=0 ; i<n; i++){
	
	mpl_v = BFS(i);
	sum += mpl_v[0];
	counter += mpl_v[1];
      }
      return (long double) sum/counter;
     }
   
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
   
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
   
      
      
     