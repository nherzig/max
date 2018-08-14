// max.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>

std::tuple<double, int> maxpklc(std::vector<double> x){
	double pk(x[0]);
	int lc(0);
	int n=x.size();
	for(int i(1);i<n;i++){
		lc= (pk<x[i])? i:lc;
		pk = (pk<x[i])? x[i]:pk;
	}
	return  std::make_tuple(pk,lc);
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<double> x;
	std::ifstream ifs;
	double num(0.0);
	//Loading data to filter
	ifs.open("x_unfilt.txt");
	if(!ifs){
		std::cout<<"x_unfilt.txt file not loaded"<<std::endl;
	}
	while (ifs >> num) {
        x.push_back(-num);
	}

	double pk;
	int lc;
	std::tie(pk,lc) =maxpklc(x);

	std::cout<<"max = "<<pk<<" loc: "<<lc<<std::endl;

	std::getchar();
}

